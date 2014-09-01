/********************************************************************/
/*																	*/
/* ファイル名	Timer.c												*/
/*																	*/
/* 機能概略		1mSecタイマーによるタイムアウト判断					*/
/*																	*/
/*																	*/
/********************************************************************/
#include "iodefine.h"
#include "appli.h"


#define	TIMEOUT_CNT_MAX		(0x80000000)



int Time_Check( unsigned short timeout_counter, unsigned short now_time){
	
	unsigned short	keika_time;
	int				result;
	
	if(timeout_counter >= TIMEOUT_CNT_MAX)	return(0);	// max値は入れられないので即ﾀｲﾑｱｳﾄにする
	
	result = 1;	//戻り値の初期値設定
	
	keika_time = (unsigned short)(timeout_counter + now_time);		//現在値と比較する値
	
	if(now_time <= CLOCK_1MSEC_COUNTER){
		if(keika_time >= now_time){
			if(CLOCK_1MSEC_COUNTER > keika_time)	result = 0;		//現在値が経過タイマー値を超えた
		}
	}
	else{
		if(keika_time < now_time){
			if(CLOCK_1MSEC_COUNTER > keika_time)	result = 0;		//現在値が経過タイマー値を超えた
		}
		else	result = 0;	//現在値が経過タイマー値を超えた
	}
	return(result);
}



void Wait(unsigned short ms){
	
	unsigned short	Dummy_time;
	
	Dummy_time = CLOCK_1MSEC_COUNTER;
	
	while(Time_Check(ms, Dummy_time));
}


