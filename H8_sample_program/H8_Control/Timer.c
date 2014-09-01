/********************************************************************/
/*																	*/
/* �t�@�C����	Timer.c												*/
/*																	*/
/* �@�\�T��		1mSec�^�C�}�[�ɂ��^�C���A�E�g���f					*/
/*																	*/
/*																	*/
/********************************************************************/
#include "iodefine.h"
#include "appli.h"


#define	TIMEOUT_CNT_MAX		(0x80000000)



int Time_Check( unsigned short timeout_counter, unsigned short now_time){
	
	unsigned short	keika_time;
	int				result;
	
	if(timeout_counter >= TIMEOUT_CNT_MAX)	return(0);	// max�l�͓�����Ȃ��̂ő���ѱ�Ăɂ���
	
	result = 1;	//�߂�l�̏����l�ݒ�
	
	keika_time = (unsigned short)(timeout_counter + now_time);		//���ݒl�Ɣ�r����l
	
	if(now_time <= CLOCK_1MSEC_COUNTER){
		if(keika_time >= now_time){
			if(CLOCK_1MSEC_COUNTER > keika_time)	result = 0;		//���ݒl���o�߃^�C�}�[�l�𒴂���
		}
	}
	else{
		if(keika_time < now_time){
			if(CLOCK_1MSEC_COUNTER > keika_time)	result = 0;		//���ݒl���o�߃^�C�}�[�l�𒴂���
		}
		else	result = 0;	//���ݒl���o�߃^�C�}�[�l�𒴂���
	}
	return(result);
}



void Wait(unsigned short ms){
	
	unsigned short	Dummy_time;
	
	Dummy_time = CLOCK_1MSEC_COUNTER;
	
	while(Time_Check(ms, Dummy_time));
}


