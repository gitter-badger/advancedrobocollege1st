
#ifdef __cplusplus

extern "C" {
void abort(void);

#endif
void main(void);
#ifdef __cplusplus
}
#endif


#define	MAIN


/*�C���N���[�h***********************************************************/
#include <iodefine.h>
#include "appli.h"
#include "sc.h"




/*�֐�*****************************************************************/
void	SENSOR_check(unsigned char);

void	MTR_INIT();
void	MTR_RUN(char m1, char m2, char m3, char m4);
void	LED_CTL();
void	BRAKE_SET();


/*���C���֐�***********************************************************/
void main(void){
	
	int 	i,j;
	char	joystick;
	
	set_imask_ccr(1);
	HardwareSetup();		//CPU�̏����ݒ�
	set_imask_ccr(0);
	
	//## �u�U�[ ##
	Wait(1000);
	BuzzerSet(0x80,0x80); 	//�u�U�[�̐ݒ�
	BuzzerStart();
	Wait(500); 
	BuzzerStop();
	
	
	//����
	//���[�^�h���C�o���8-45V�œ���
	//�WV�ȉ��ł͓���s����i���Z�b�g���s�j
	
	MTR_INIT();				//�h���C�o������
	
	
	while(1){
		
		//�V���A���ʐM�R�}���h����
		ap_select_SCI1();
		ap_select_SCI2();
		
		//�ŐV�̃Q�[���p�b�h�̏����擾
		updatePAD();
		B1DATE=getPAD(PAD_B1);		//PAD_B1�̃f�[�^��B1DATE�ɓǂݍ���	
		B2DATE=getPAD(PAD_B2);		//PAD_B2�̃f�[�^��B2DATE�ɓǂݍ���
		
		
		//	���A�i���O�X�e�B�b�N�̑O��̌X���̒l���擾���ASpeed�ɑ���B
		//	�X�e�B�b�N�̒l��-128�`127�͈̔͊O�ł���΁A�͈͓��̐��l�ɕ␳
		
		YSPEED = (int)getPAD(PAD_AN_LY)-128 == 128 ? 127 
				: (int)getPAD(PAD_AN_LY)-128 == -128 ? -127 
				: (int)getPAD(PAD_AN_LY)-128;
		
		XSPEED = (int)getPAD(PAD_AN_LX)-128 == 128 ? 127
				: (int)getPAD(PAD_AN_LX)-128 == -128 ? -127
				: (int)getPAD(PAD_AN_LX)-128;
				
		//�E�A�i���O�X�e�B�b�N�̍��E�̌X���̒l���擾���ATURN�ɑ���B
				
		TURN   = (int)getPAD(PAD_AN_RX)-128 == 128 ? 127 
				: (int)getPAD(PAD_AN_RX)-128 == -128 ? -127 
				: (int)getPAD(PAD_AN_RX)-128;
		
		//	�A�i���O�X�e�B�b�N�̌X������Speed�̐��l���Ⴂ�ꍇ��Speed��0�ɂ���
		if(YSPEED < 20 && YSPEED > -20)		YSPEED = 0;
		if(XSPEED < 20 && XSPEED > -20)		XSPEED = 0;
		if(TURN	  < 20 && TURN   > -20)		TURN   = 0;
		
		if(XSPEED == 0 && YSPEED == 0 && TURN == 0)		joystick = 0;
		else											joystick = 1;
		
		
		if(SW3 == 1){
			//#####�D��{�^��(�X�g�b�v�E��])#####
			if((B2DATE & 0x80) == 0x80){
				//���{�^��  �ً}��~
				BRAKE_SET();
			}
			else if(B1DATE == 0x08){
				//start�{�^��
				MTR_INIT();
				BuzzerStart();
				Wait(500);
				BuzzerStop();
				Wait(500);
			}
			else if(B1DATE == 0x01){
				//select�{�^��
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
				//R1�������ꂽ�ꍇ�o�p�������s
				for(i=0;i<4;i++)	TARGET_SPD[i] = VSP * 0.8;
			}
			else if(B2DATE==0x04){
				//L1�������ꂽ�ꍇ�o�p�������s
				for(i=0;i<4;i++)	TARGET_SPD[i] = -VSP * 0.8;
			}
			else if(B2DATE==0x10){
				//���{�^��
			}
			else if(B2DATE==0x20){
				//�~�{�^��
			}
			else if(B2DATE==0x40){
				//���{�^��
			}
			else if(B2DATE==0x01){
				//L2�{�^��
			}
			else if(B2DATE==0x02){
				//R2�{�^��
			}
			
			//#####�D��{�^���R�R�܂�#####
			else{
				//�ǂ̏������������Ȃ��ꍇ
				//#####�f�W�^������######
				if(B1DATE == 0x30){
					//�\���{�^���E�オ�����ꂽ�ꍇ�o�p�������s
					TARGET_SPD[0] =  VSP;
					TARGET_SPD[1] =  0.0;
					TARGET_SPD[2] = -VSP;
					TARGET_SPD[3] =  0.0;
				}
				else if(B1DATE == 0x90){
					//�\���{�^�����オ�����ꂽ�ꍇ�o�p�������s
					TARGET_SPD[0] =  0.0;
					TARGET_SPD[1] = -VSP;
					TARGET_SPD[2] =  0.0;
					TARGET_SPD[3] =  VSP;
				}
				else if(B1DATE == 0x60){
					//�\���{�^���E���������ꂽ�ꍇ�o�p�������s
					TARGET_SPD[0] =  0.0;
					TARGET_SPD[1] =  VSP;
					TARGET_SPD[2] =  0.0;
					TARGET_SPD[3] = -VSP;
				}
				else if(B1DATE == 0xC0){
					//�\���{�^�������������ꂽ�ꍇ�o�p�������s
					TARGET_SPD[0] = -VSP;
					TARGET_SPD[1] =  0.0;
					TARGET_SPD[2] =  VSP;
					TARGET_SPD[3] =  0.0;
				}
				else if(B1DATE==0x10){
					//�\���{�^���オ�����ꂽ�ꍇ
					TARGET_SPD[0] =  VSP;
					TARGET_SPD[1] = -VSP;
					TARGET_SPD[2] = -VSP;
					TARGET_SPD[3] =  VSP;
				}
				else if(B1DATE==0x80){
					//�\���{�^�����������ꂽ�ꍇ
					TARGET_SPD[0] = -VSP;
					TARGET_SPD[1] = -VSP;
					TARGET_SPD[2] =  VSP;
					TARGET_SPD[3] =  VSP;
				}
				else if(B1DATE==0x40){
					//�\���{�^�����������ꂽ�ꍇ�o�p�������s
					TARGET_SPD[0] = -VSP;
					TARGET_SPD[1] =  VSP;
					TARGET_SPD[2] =  VSP;
					TARGET_SPD[3] = -VSP;
				}
				else if(B1DATE==0x20){
					//�\���{�^���E�������ꂽ�ꍇ�o�p�������s
					TARGET_SPD[0] =  VSP;
					TARGET_SPD[1] =  VSP;
					TARGET_SPD[2] = -VSP;
					TARGET_SPD[3] = -VSP;
				}
				else if(joystick == 1){
					//�A�i���O���͏���
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
					//�E�A�i���O�X�e�B�b�N�̍��E�ɂ���ĉ�]
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
			//��������
			VSP = 30.0;		//�����l�ݒ�
			
			if((SENSOR == 0x01) || (SENSOR == 0x0B)){
				//����ړ�
				TARGET_SPD[0] = -VSP;
				TARGET_SPD[1] =  VSP;
				TARGET_SPD[2] =  VSP;
				TARGET_SPD[3] = -VSP;
			}
			else if((SENSOR == 0x02) || (SENSOR == 0x07)){
				//�������ړ�
				TARGET_SPD[0] = -VSP;
				TARGET_SPD[1] = -VSP;
				TARGET_SPD[2] =  VSP;
				TARGET_SPD[3] =  VSP;
			}
			else if(SENSOR == 0x03){
				//������ړ�
				TARGET_SPD[0] = -VSP;
				TARGET_SPD[1] =  0.0;
				TARGET_SPD[2] =  VSP;
				TARGET_SPD[3] =  0.0;
			}
			else if((SENSOR == 0x04) || (SENSOR == 0x0E)){
				//�O���ړ�
				TARGET_SPD[0] =  VSP;
				TARGET_SPD[1] = -VSP;
				TARGET_SPD[2] = -VSP;
				TARGET_SPD[3] =  VSP;
			}
			else if(SENSOR == 0x06){
				//���O���ړ�
				TARGET_SPD[0] =  0.0;
				TARGET_SPD[1] = -VSP;
				TARGET_SPD[2] =  0.0;
				TARGET_SPD[3] =  VSP;
			}
			else if((SENSOR == 0x08) || (SENSOR == 0x0D)){
				//�E�����ړ�
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
		
		
		
		//���ʃu���b�N
    	for(i=0;i<4;i++){
			if(TARGET_SPD[i] - CURRENT_SPD[i] > MSP_UP) 		CURRENT_SPD[i] += MSP_UP;
			else if(TARGET_SPD[i] - CURRENT_SPD[i] < -MSP_UP)	CURRENT_SPD[i] -= MSP_UP;
			else												CURRENT_SPD[i] = TARGET_SPD[i];
		}
		
		//���[�^����u���b�N
		MTR_RUN((char)CURRENT_SPD[0], (char)CURRENT_SPD[1], (char)CURRENT_SPD[2], (char)CURRENT_SPD[3]);
		
		//LED����
		LED_CTL();
	}
}



void Nop(){
	int i;
	for(i=0;i<100;i++);
}



//****************************************************************************
//
//	���[�^�[�������֐�
//
//****************************************************************************
void	MTR_INIT(){
	
	int	i;
	
	//������
	VSP = 40.0;
	
	M_ENABLE = 0;
	MSP_UP = 5.0;		//�����W��
	
	B1DATE = 0;
	B2DATE = 0;
	
	for(i=0;i<4;i++){
		TARGET_SPD[i] = 0.0;	//�ڕW�l
		CURRENT_SPD[i] = 0.0;	//���ݒl
		MDIR[i] = 3;			//���[�^�t���[
	}
	
}


//****************************************************************************
//
//	LED����֐�
//
//****************************************************************************

void	LED_CTL(){
	
	if(SW3 == 1){
		//�����R�����䎞�ɓ��쎲��_���\��
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
		
		//�������䎞�ɃZ���T�[������\��
		
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
//	�X�s�[�h�ݒ�֐�
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
	
	//���[�^#1 Duty�ݒ�
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
	
	//���[�^#2 Duty�ݒ�
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
	
	//���[�^#3 Duty�ݒ�
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
	
	//���[�^#4 Duty�ݒ�
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
//	�Z���T�[���j�^�[�֐�
//
//****************************************************************************
void	SENSOR_check(unsigned char vlt){
	
	unsigned short	ADC[4];
	unsigned short	thresh;
	
	//臒l��2.5V�ɂ���ꍇ�Avlt = 25��ݒ肷��B
	//0.1V = 0x051E (0xFFFF/50)�ɑ���
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