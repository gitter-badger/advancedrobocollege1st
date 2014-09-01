/********************************************************************/
/*																	*/
/* ファイル名	sc_rs232c.c											*/
/*																	*/
/* 機能概略		RS232C送受信関係									*/
/*																	*/
/*																	*/
/********************************************************************/
#include "iodefine.h"
#include "sc.h"
#include "appli.h"



unsigned char sc_rb_read(struct SC_T_RB* SC_T_RCV, unsigned char* rd_data){
	/* ﾘﾝｸﾞﾊﾞｯﾌｧからの読み込み */
	
	if( SC_T_RCV->iptr == SC_T_RCV->optr){
		return(0);								/* ﾃﾞｰﾀ無し */
	}
	
	*rd_data = SC_T_RCV->data[ SC_T_RCV->optr ];
	SC_T_RCV->optr = (SC_T_RCV->optr + 1)%RB_LENGTH;
	
	return(1);
}



unsigned char sc_rb_write(struct SC_T_RB* SC_T_TRN, unsigned char wr_data){
	
	unsigned char ptr;
	ptr = (SC_T_TRN->iptr + 1)%RB_LENGTH;
	
	if( ptr == SC_T_TRN->optr ){
		/* ﾊﾞｯﾌｧﾌﾙ */;
		return( wr_data );
	}
	
	SC_T_TRN->data[ SC_T_TRN->iptr ] = wr_data;	/* ﾃﾞｰﾀ書き込み */
	SC_T_TRN->iptr = (SC_T_TRN->iptr + 1)%RB_LENGTH;
	
	return(0);
}



unsigned char sc1_rs232c_putc(unsigned char put_data){
	unsigned char rc;
	
	rc = sc_rb_write( &SC1_T_RS232C_TRN, put_data);
	
	if( rc != 0 ){
		return( rc );			/* ﾘﾝｸﾞﾊﾞｯﾌｧがいっぱい */
	}

	SCI3.SCR3.BYTE |= 0xa0;		/* 送信ｲﾈｰﾌﾞﾙ */

	/* この後ｴﾝﾌﾟﾃｨ割込みが入ってTDRへﾃﾞｰﾀが転送される */

	return(0);
}


void sc1_rs232c_puts(unsigned char *put_data){
	
	unsigned char	cnt1,cnt2;
	unsigned char*	str_ptr;
	unsigned short 	Dummy;

	str_ptr = put_data;
		
	while(1){
		if(cnt1 = *str_ptr++){
			Dummy = CLOCK_1MSEC_COUNTER;
			while(1){
				/* 戻りが0になるまで繰り返す */
				cnt2 = sc1_rs232c_putc(cnt1);
				if( cnt2 == 0 )		break;
				if(!(Time_Check( 10, Dummy))) return;
			}
		}
		else	break;
	}
	return;
}



unsigned char sc2_rs232c_putc(unsigned char put_data){
	unsigned char rc;
	
	rc = sc_rb_write( &SC2_T_RS232C_TRN, put_data);
	
	if( rc != 0 ){
		return( rc );			/* ﾘﾝｸﾞﾊﾞｯﾌｧがいっぱい */
	}

	SCI3_2.SCR3.BYTE |= 0xa0;		/* 送信ｲﾈｰﾌﾞﾙ */

	/* この後ｴﾝﾌﾟﾃｨ割込みが入ってTDRへﾃﾞｰﾀが転送される */

	return(0);
}


void sc2_rs232c_puts(unsigned char *put_data){
	
	unsigned char	cnt1,cnt2;
	unsigned char*	str_ptr;
	unsigned short 	Dummy;

	str_ptr = put_data;
		
	while(1){
		if(cnt1 = *str_ptr++){
			Dummy = CLOCK_1MSEC_COUNTER;
			while(1){
				/* 戻りが0になるまで繰り返す */
				cnt2 = sc2_rs232c_putc(cnt1);
				if( cnt2 == 0 )		break;
				if(!(Time_Check( 10, Dummy))) return;
			}
		}
		else	break;
	}
	return;
}




void cpu_sci1_init(){
	
	int i;
	
	/* ﾘﾝｸﾞﾊﾞｯﾌｧの入出力ﾎﾟｲﾝﾀの初期化 */
	for(i=0;i<RB_LENGTH;i++){
		SC1_T_RS232C_RCV.data[i] = 0;
		SC1_T_RS232C_TRN.data[i] = 0;
	}
	for(i=0;i<16;i++)	CODE[i] = 0;
	
	SC1_T_RS232C_RCV.iptr = 0;
	SC1_T_RS232C_RCV.optr = 0;
	SC1_T_RS232C_TRN.iptr = 0;
	SC1_T_RS232C_TRN.optr = 0;
	
	
	SCI3.SCR3.BYTE = 0;
	SCI3.SMR.BYTE = 0;
	SCI3.BRR = 47;			//9600bps
//	SCI3.BRR = 11;			//38400bps
//	SCI3.BRR = 3;			//115200bps
	
	for(i=0; i<(SCI3.BRR*10); i++)	nop();	//Wait 1bit
	
	SCI3.SCR3.BYTE = 0x70;		//受信割込み許可、送受信Enable
}

void cpu_sci2_init(){
	
	int i;
	
	/* ﾘﾝｸﾞﾊﾞｯﾌｧの入出力ﾎﾟｲﾝﾀの初期化 */
	for(i=0;i<RB_LENGTH;i++){
		SC2_T_RS232C_RCV.data[i] = 0;
		SC2_T_RS232C_TRN.data[i] = 0;
	}
	for(i=0;i<16;i++)	CODE[i] = 0;
	
	SC2_T_RS232C_RCV.iptr = 0;
	SC2_T_RS232C_RCV.optr = 0;
	SC2_T_RS232C_TRN.iptr = 0;
	SC2_T_RS232C_TRN.optr = 0;
	
	
	SCI3_2.SCR3.BYTE = 0;
	SCI3_2.SMR.BYTE = 0;
	SCI3_2.BRR = 47;		//9600bps
//	SCI3.BRR = 11;			//38400bps
//	SCI3.BRR = 3;			//115200bps
	
	for(i=0; i<(SCI3_2.BRR*10); i++)	nop();	//Wait 1bit
	
	SCI3_2.SCR3.BYTE = 0x70;		//受信割込み許可、送受信Enable
}



void SciByteTxo(unsigned char data){
	
	SCI3.SCR3.BIT.TE=1;
	while(SCI3.SSR.BIT.TDRE!=1);

	SCI3.TDR=data;
	
	while(SCI3.SSR.BIT.TEND!=1);
	SCI3.SCR3.BIT.TE=0;
}



