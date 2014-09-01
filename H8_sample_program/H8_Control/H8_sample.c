
#ifdef __cplusplus

extern "C" {
void abort(void);

#endif
void main(void);
#ifdef __cplusplus
}
#endif


#define	MAIN


/*インクルード***********************************************************/
#include <iodefine.h>
#include "appli.h"
#include "sc.h"




/*関数*****************************************************************/
void	SENSOR_check(unsigned char);

void	MTR_INIT();
void	MTR_RUN(char m1, char m2, char m3, char m4);
void	LED_CTL();
void	BRAKE_SET();


/*メイン関数***********************************************************/
void main(void){
	
	int 	i,j;
	char	joystick;
	
	set_imask_ccr(1);
	HardwareSetup();		//CPUの初期設定
	set_imask_ccr(0);
	
	//## ブザー ##
	Wait(1000);
	BuzzerSet(0x80,0x80); 	//ブザーの設定
	BuzzerStart();
	Wait(500); 
	BuzzerStop();
	
	
	//注意
	//モータドライバ基板は8-45Vで動作
	//８V以下では動作不安定（リセット等不可）
	
	MTR_INIT();				//ドライバ初期化
	
	
	while(1){
		
		//シリアル通信コマンド処理
		ap_select_SCI1();
		ap_select_SCI2();
		
		//最新のゲームパッドの情報を取得
		updatePAD();
		B1DATE=getPAD(PAD_B1);		//PAD_B1のデータをB1DATEに読み込む	
		B2DATE=getPAD(PAD_B2);		//PAD_B2のデータをB2DATEに読み込む
		
		
		//	左アナログスティックの前後の傾きの値を取得し、Speedに代入。
		//	スティックの値が-128～127の範囲外であれば、範囲内の数値に補正
		
		YSPEED = (int)getPAD(PAD_AN_LY)-128 == 128 ? 127 
				: (int)getPAD(PAD_AN_LY)-128 == -128 ? -127 
				: (int)getPAD(PAD_AN_LY)-128;
		
		XSPEED = (int)getPAD(PAD_AN_LX)-128 == 128 ? 127
				: (int)getPAD(PAD_AN_LX)-128 == -128 ? -127
				: (int)getPAD(PAD_AN_LX)-128;
				
		//右アナログスティックの左右の傾きの値を取得し、TURNに代入。
				
		TURN   = (int)getPAD(PAD_AN_RX)-128 == 128 ? 127 
				: (int)getPAD(PAD_AN_RX)-128 == -128 ? -127 
				: (int)getPAD(PAD_AN_RX)-128;
		
		//	アナログスティックの傾きが浅くSpeedの数値が低い場合はSpeedを0にする
		if(YSPEED < 20 && YSPEED > -20)		YSPEED = 0;
		if(XSPEED < 20 && XSPEED > -20)		XSPEED = 0;
		if(TURN	  < 20 && TURN   > -20)		TURN   = 0;
		
		if(XSPEED == 0 && YSPEED == 0 && TURN == 0)		joystick = 0;
		else											joystick = 1;
		
		
		if(SW3 == 1){
			//#####優先ボタン(ストップ・回転)#####
			if((B2DATE & 0x80) == 0x80){
				//左ボタン  緊急停止
				BRAKE_SET();
			}
			else if(B1DATE == 0x08){
				//startボタン
				MTR_INIT();
				BuzzerStart();
				Wait(500);
				BuzzerStop();
				Wait(500);
			}
			else if(B1DATE == 0x01){
				//selectボタン
				if(VSP == 20.0){
					VSP = 40.0;
					
					BuzzerStart();
					Wait(100);
					BuzzerStop();
					Wait(500);
				}
				else if(VSP == 40.0){
					VSP = 60.0;
					
					BuzzerStart();
					Wait(100);
					BuzzerStop();
					Wait(100);
					
					BuzzerStart();
					Wait(100);
					BuzzerStop();
					Wait(500);
				}
				else if(VSP == 60.0){
					VSP = 80.0;
					
					BuzzerStart();
					Wait(100);
					BuzzerStop();
					Wait(100);
					
					BuzzerStart();
					Wait(100);
					BuzzerStop();
					Wait(100);
					
					BuzzerStart();
					Wait(100);
					BuzzerStop();
					Wait(500);
				}
				else{
					VSP = 20.0;
					BuzzerStart();
					Wait(500);
					BuzzerStop();
					Wait(500);
				}
			}
			else if(B2DATE == 0x08){
				//R1が押された場合｛｝内を実行
				for(i=0;i<4;i++)	TARGET_SPD[i] = VSP * 0.8;
			}
			else if(B2DATE==0x04){
				//L1が押された場合｛｝内を実行
				for(i=0;i<4;i++)	TARGET_SPD[i] = -VSP * 0.8;
			}
			else if(B2DATE==0x10){
				//△ボタン
			}
			else if(B2DATE==0x20){
				//×ボタン
			}
			else if(B2DATE==0x40){
				//□ボタン
			}
			else if(B2DATE==0x01){
				//L2ボタン
			}
			else if(B2DATE==0x02){
				//R2ボタン
			}
			
			//#####優先ボタンココまで#####
			else{
				//どの条件も満たさない場合
				//#####デジタル制御######
				if(B1DATE == 0x30){
					//十字ボタン右上が押された場合｛｝内を実行
					TARGET_SPD[0] =  VSP;
					TARGET_SPD[1] =  0.0;
					TARGET_SPD[2] = -VSP;
					TARGET_SPD[3] =  0.0;
				}
				else if(B1DATE == 0x90){
					//十字ボタン左上が押された場合｛｝内を実行
					TARGET_SPD[0] =  0.0;
					TARGET_SPD[1] = -VSP;
					TARGET_SPD[2] =  0.0;
					TARGET_SPD[3] =  VSP;
				}
				else if(B1DATE == 0x60){
					//十字ボタン右下が押された場合｛｝内を実行
					TARGET_SPD[0] =  0.0;
					TARGET_SPD[1] =  VSP;
					TARGET_SPD[2] =  0.0;
					TARGET_SPD[3] = -VSP;
				}
				else if(B1DATE == 0xC0){
					//十字ボタン左下が押された場合｛｝内を実行
					TARGET_SPD[0] = -VSP;
					TARGET_SPD[1] =  0.0;
					TARGET_SPD[2] =  VSP;
					TARGET_SPD[3] =  0.0;
				}
				else if(B1DATE==0x10){
					//十字ボタン上が押された場合
					TARGET_SPD[0] =  VSP;
					TARGET_SPD[1] = -VSP;
					TARGET_SPD[2] = -VSP;
					TARGET_SPD[3] =  VSP;
				}
				else if(B1DATE==0x80){
					//十字ボタン左が押された場合
					TARGET_SPD[0] = -VSP;
					TARGET_SPD[1] = -VSP;
					TARGET_SPD[2] =  VSP;
					TARGET_SPD[3] =  VSP;
				}
				else if(B1DATE==0x40){
					//十字ボタン下が押された場合｛｝内を実行
					TARGET_SPD[0] = -VSP;
					TARGET_SPD[1] =  VSP;
					TARGET_SPD[2] =  VSP;
					TARGET_SPD[3] = -VSP;
				}
				else if(B1DATE==0x20){
					//十字ボタン右が押された場合｛｝内を実行
					TARGET_SPD[0] =  VSP;
					TARGET_SPD[1] =  VSP;
					TARGET_SPD[2] = -VSP;
					TARGET_SPD[3] = -VSP;
				}
				else if(joystick == 1){
					//アナログ入力処理
					if(XSPEED * YSPEED == 0){
						TARGET_SPD[0] = ( XSPEED - YSPEED) / 80.0 * VSP;
						TARGET_SPD[1] = ( XSPEED + YSPEED) / 80.0 * VSP;
						TARGET_SPD[2] = (-XSPEED + YSPEED) / 80.0 * VSP;
						TARGET_SPD[3] = (-XSPEED - YSPEED) / 80.0 * VSP;
					}
					else{
						TARGET_SPD[0] = ( XSPEED - YSPEED) / 127.0 * VSP;
						TARGET_SPD[1] = ( XSPEED + YSPEED) / 127.0 * VSP;
						TARGET_SPD[2] = (-XSPEED + YSPEED) / 127.0 * VSP;
						TARGET_SPD[3] = (-XSPEED - YSPEED) / 127.0 * VSP;
					}
					//右アナログスティックの左右によって回転
					if(TURN != 0){
						TARGET_SPD[0] = TURN / 80.0 *VSP;
						TARGET_SPD[1] = TURN / 80.0 *VSP;
						TARGET_SPD[2] = TURN / 80.0 *VSP;
						TARGET_SPD[3] = TURN / 80.0 *VSP;
					}
						
				}
				else	pc_ctrl();
			}
		}
		else if(SW3 == 0){
			//自立制御
			VSP = 30.0;		//初期値設定
			
			if((SENSOR == 0x01) || (SENSOR == 0x0B)){
				//後方移動
				TARGET_SPD[0] = -VSP;
				TARGET_SPD[1] =  VSP;
				TARGET_SPD[2] =  VSP;
				TARGET_SPD[3] = -VSP;
			}
			else if((SENSOR == 0x02) || (SENSOR == 0x07)){
				//左方向移動
				TARGET_SPD[0] = -VSP;
				TARGET_SPD[1] = -VSP;
				TARGET_SPD[2] =  VSP;
				TARGET_SPD[3] =  VSP;
			}
			else if(SENSOR == 0x03){
				//左後方移動
				TARGET_SPD[0] = -VSP;
				TARGET_SPD[1] =  0.0;
				TARGET_SPD[2] =  VSP;
				TARGET_SPD[3] =  0.0;
			}
			else if((SENSOR == 0x04) || (SENSOR == 0x0E)){
				//前方移動
				TARGET_SPD[0] =  VSP;
				TARGET_SPD[1] = -VSP;
				TARGET_SPD[2] = -VSP;
				TARGET_SPD[3] =  VSP;
			}
			else if(SENSOR == 0x06){
				//左前方移動
				TARGET_SPD[0] =  0.0;
				TARGET_SPD[1] = -VSP;
				TARGET_SPD[2] =  0.0;
				TARGET_SPD[3] =  VSP;
			}
			else if((SENSOR == 0x08) || (SENSOR == 0x0D)){
				//右方向移動
				TARGET_SPD[0] =  VSP;
				TARGET_SPD[1] =  VSP;
				TARGET_SPD[2] = -VSP;
				TARGET_SPD[3] = -VSP;
			}
			else if(SENSOR == 0x0C){
				TARGET_SPD[0] =  VSP;
				TARGET_SPD[1] =  0.0;
				TARGET_SPD[2] = -VSP;
				TARGET_SPD[3] =  0.0;
			}
			else if(SENSOR == 0x09){
				TARGET_SPD[0] =  0.0;
				TARGET_SPD[1] =  VSP;
				TARGET_SPD[2] =  0.0;
				TARGET_SPD[3] = -VSP;
			}
			else{
				for(i=0;i<4;i++)	TARGET_SPD[i] = 0.0;
			}
		}
		
		
		
		//共通ブロック
    	for(i=0;i<4;i++){
			if(TARGET_SPD[i] - CURRENT_SPD[i] > MSP_UP) 		CURRENT_SPD[i] += MSP_UP;
			else if(TARGET_SPD[i] - CURRENT_SPD[i] < -MSP_UP)	CURRENT_SPD[i] -= MSP_UP;
			else												CURRENT_SPD[i] = TARGET_SPD[i];
		}
		
		//モータ制御ブロック
		MTR_RUN((char)CURRENT_SPD[0], (char)CURRENT_SPD[1], (char)CURRENT_SPD[2], (char)CURRENT_SPD[3]);
		
		//LED制御
		LED_CTL();
	}
}



void Nop(){
	int i;
	for(i=0;i<100;i++);
}



//****************************************************************************
//
//	モーター初期化関数
//
//****************************************************************************
void	MTR_INIT(){
	
	int	i;
	
	//初期化
	VSP = 40.0;
	
	M_ENABLE = 0;
	MSP_UP = 5.0;		//加速係数
	
	B1DATE = 0;
	B2DATE = 0;
	
	for(i=0;i<4;i++){
		TARGET_SPD[i] = 0.0;	//目標値
		CURRENT_SPD[i] = 0.0;	//現在値
		MDIR[i] = 3;			//モータフリー
	}
	
}


//****************************************************************************
//
//	LED制御関数
//
//****************************************************************************

void	LED_CTL(){
	
	if(SW3 == 1){
		//リモコン制御時に動作軸を点灯表示
		if(TARGET_SPD[0] == 0.0)	LED1 = 1;
		else						LED1 = 0;
	
		if(TARGET_SPD[1] == 0.0)	LED2 = 1;
		else						LED2 = 0;
	
		if(TARGET_SPD[2] == 0.0)	LED3 = 1;
		else						LED3 = 0;
	
		if(TARGET_SPD[3] == 0.0)	LED4 = 1;
		else						LED4 = 0;
	}
	else{
		
		//自立制御時にセンサー反応を表示
		
		if((SENSOR & 0x01) == 0x01)	LED1 = 0;
		else						LED1 = 1;
		
		if((SENSOR & 0x02) == 0x02)	LED2 = 0;
		else						LED2 = 1;
		
		if((SENSOR & 0x04) == 0x04)	LED3 = 0;
		else						LED3 = 1;
		
		if((SENSOR & 0x08) == 0x08)	LED4 = 0;
		else						LED4 = 1;
	}
}



//****************************************************************************
//
//	スピード設定関数
//
//****************************************************************************
void MTR_RUN(char m1, char m2, char m3, char m4){
	
	if(m1 > 100)			m1 =  100;
	else if(m1 < -100)		m1 = -100;
	
	if(m2 > 100)			m2 =  100;
	else if(m2 < -100)		m2 = -100;
	
	if(m3 > 100)			m3 =  100;
	else if(m3 < -100)		m3 = -100;
	
	if(m4 > 100)			m4 =  100;
	else if(m4 < -100)		m4 = -100;
	
	//モータ#1 Duty設定
	if(m1 > 0){
		MDIR[0] = 0;
		TZ0.GRA = 148 * m1;
	}
	else if(m1 < 0){
		MDIR[0] = 1;
		TZ0.GRA = 148 * m1 * (-1);
	}
	else if(MDIR[0] != 2){
		MDIR[0] = 3;
		TZ0.GRA = 0;
	}
	
	//モータ#2 Duty設定
	if(m2 > 0){
		MDIR[1] = 0;
		TZ0.GRB = 148 * m2;
	}
	else if(m2 < 0){
		MDIR[1] = 1;
		TZ0.GRB = 148 * m2 * (-1);
	}
	else if(MDIR[1] != 2){
		MDIR[1] = 3;
		TZ0.GRB = 0;
	}
	
	//モータ#3 Duty設定
	if(m3 > 0){
		MDIR[2] = 0;
		TZ1.GRA = 148 * m3;
	}
	else if(m3 < 0){
		MDIR[2] = 1;
		TZ1.GRA = 148 * m3 * (-1);
	}
	else if(MDIR[2] != 2){
		MDIR[2] = 3;
		TZ1.GRA = 0;
	}
	
	//モータ#4 Duty設定
	if(m4 > 0){
		MDIR[3] = 0;
		TZ1.GRB = 148 * m4;
	}
	else if(m4 < 0){
		MDIR[3] = 1;
		TZ1.GRB = 148 * m4 * (-1);
	}
	else if(MDIR[3] != 2){
		MDIR[3] = 3;
		TZ1.GRB = 0;
	}
}


void	BRAKE_SET(){
	int	i;
	
	for(i=0;i<4;i++){
		MDIR[i] = 2;
		TARGET_SPD[i] = 0.0;
		CURRENT_SPD[i] = 0.0;
	}
}

//****************************************************************************
//
//	センサーモニター関数
//
//****************************************************************************
void	SENSOR_check(unsigned char vlt){
	
	unsigned short	ADC[4];
	unsigned short	thresh;
	
	//閾値を2.5Vにする場合、vlt = 25を設定する。
	//0.1V = 0x051E (0xFFFF/50)に相当
	thresh = 0x051E * vlt;
	
	ADC[0] = AD.ADDRA;
	ADC[1] = AD.ADDRB;
	ADC[2] = AD.ADDRC;
	ADC[3] = AD.ADDRD;
	
	if(ADC[0] > thresh)		SENSOR |= 0x01;
	else					SENSOR &= 0xFE;
	
	if(ADC[1] > thresh)		SENSOR |= 0x02;
	else					SENSOR &= 0xFD;
	
	if(ADC[2] > thresh)		SENSOR |= 0x04;
	else					SENSOR &= 0xFB;
	
	if(ADC[3] > thresh)		SENSOR |= 0x08;
	else					SENSOR &= 0xF7;
	
	return;
}


#ifdef __cplusplus
void abort(void)
{
	
}
#endif