/*インクルード***********************************************************/
#include "iodefine.h"
#include "appli.h"
#include "sc.h"


char	pc_ctrl() {
	
	int	i;
	
	if(Code_flg == 1){
		//新コマンド実行処理
		if((CODE[0] == 2) && (CODE[3] == 2) && (CODE[6] == 2) && (CODE[9] == 2)){
			for(i=0;i<4;i++){
				TARGET_SPD[i] = 0.0;
				MDIR[i] = 2;		//ブレーキ設定
			}
		}
		else{
			if(CODE[0]==0)			TARGET_SPD[0] = (float)( CODE[1]*10 + CODE[2]);
			else if(CODE[0]==1)		TARGET_SPD[0] = (float)(-CODE[1]*10 - CODE[2]);
			else if(CODE[0]==2){
				TARGET_SPD[0] = 0.0;
				MDIR[0] = 2;
			}
			else if(CODE[0]==3){
				TARGET_SPD[0] = 0.0;		//モータフリー
				MDIR[0] = 3;
			}
			
			if(CODE[3]==0)			TARGET_SPD[1] = (float)( CODE[4]*10 + CODE[5]);
			else if(CODE[3]==1)		TARGET_SPD[1] = (float)(-CODE[4]*10 - CODE[5]);
			else if(CODE[3]==2){
				TARGET_SPD[1] = 0.0;
				MDIR[1] = 2;
			}
			else if(CODE[3]==3){
				TARGET_SPD[1] = 0.0;
				MDIR[1] = 3;
			}
			
			
			if(CODE[6]==0)			TARGET_SPD[2] = (float)( CODE[7]*10 + CODE[8]);
			else if(CODE[6]==1)		TARGET_SPD[2] = (float)(-CODE[7]*10 - CODE[8]);
			else if(CODE[6]==2){
				TARGET_SPD[2] = 0.0;
				MDIR[2] = 2;
			}
			else if(CODE[6]==3){
				TARGET_SPD[2] = 0.0;
				MDIR[2] = 3;
			}
			
			
			if(CODE[9]==0)			TARGET_SPD[3] = (float)( CODE[10]*10 + CODE[11]);
			else if(CODE[9]==1)		TARGET_SPD[3] = (float)(-CODE[10]*10 - CODE[11]);
			else if(CODE[9]==2){
				TARGET_SPD[3] = 0.0;
				MDIR[3] = 2;
			}
			else if(CODE[9]==3){
				TARGET_SPD[3] = 0.0;
				MDIR[3] = 3;
			}
		}
		
		Code_flg = 2;
		PC_CNT = 0;
		return(1);
	}
	else if(Code_flg == 2){
		//コマンドバッファ処理
		if(++PC_CNT > 200){
			for(i=0;i<16;i++)	CODE[i] = 0;
			Code_flg = 0;
			PC_CNT = 0;
		}
		return(1);
	}
	else{
		//コマンド終了処理
		for(i=0;i<4;i++){
			TARGET_SPD[i] = 0.0;
			MDIR[i] = 3;
		}
		return(0);
	}
}



void	ap_select_SCI1(){
	
	int	i;
	
	while(SC1_T_RS232C_RCV.iptr != SC1_T_RS232C_RCV.optr){
		
		if((SC1_T_RS232C_RCV.data[SC1_T_RS232C_RCV.optr] == 0x0d) 
		&& (SC1_T_RS232C_RCV.data[(SC1_T_RS232C_RCV.optr - 13 + RB_LENGTH)%RB_LENGTH] == 'a')){
			for(i=0;i<12;i++)	CODE[i] = SC1_T_RS232C_RCV.data[(SC1_T_RS232C_RCV.optr-12+i+RB_LENGTH)%RB_LENGTH]-48;
			Code_flg = 1;
			SC1_T_RS232C_RCV.optr = (SC1_T_RS232C_RCV.optr + 1)%RB_LENGTH;
			return;
		}
		SC1_T_RS232C_RCV.optr = (SC1_T_RS232C_RCV.optr + 1)%RB_LENGTH;
	}
}



void	ap_select_SCI2(){
	
	int	i;
	
	while(SC2_T_RS232C_RCV.iptr != SC2_T_RS232C_RCV.optr){
		
		if((SC2_T_RS232C_RCV.data[SC2_T_RS232C_RCV.optr] == 0x0d) 
		&& (SC2_T_RS232C_RCV.data[(SC2_T_RS232C_RCV.optr - 13 + RB_LENGTH)%RB_LENGTH] == 'a')){
			for(i=0;i<12;i++)	CODE[i] = SC2_T_RS232C_RCV.data[(SC2_T_RS232C_RCV.optr-12+i+RB_LENGTH)%RB_LENGTH]-48;
			Code_flg = 1;
			SC2_T_RS232C_RCV.optr = (SC2_T_RS232C_RCV.optr + 1)%RB_LENGTH;
			return;
		}
		SC2_T_RS232C_RCV.optr = (SC2_T_RS232C_RCV.optr + 1)%RB_LENGTH;
	}
}









