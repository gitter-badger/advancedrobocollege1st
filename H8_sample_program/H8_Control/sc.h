/********************************************************************/
/*																	*/
/* ファイル名	sc.h												*/
/*																	*/
/* 機能概略		ｼﾘｱﾙ通信用のヘッダーファイル						*/
/* 																	*/
/*																	*/
/********************************************************************/
#ifndef _SC_H_
#define	_SC_H_


#include <machine.h>

/*------------------------------------------*/
/*		define								*/
/*------------------------------------------*/
#define		CR_CODE			0x0d		/* ｷｬﾘｯｼﾞﾘﾀｰﾝのｺｰﾄﾞ */
#define		RB_LENGTH		128		/* ﾘﾝｸﾞﾊﾞｯﾌｧ長(ﾊﾞｲﾄ) */



/*------------------------------------------*/
/*		構造体･共用体宣言					*/
/*------------------------------------------*/

/*------	ﾘﾝｸﾞﾊﾞｯﾌｧの構造体		  ------*/
struct SC_T_RB {
	unsigned char data[RB_LENGTH];	/* ﾘﾝｸﾞﾊﾞｯﾌｧのﾃﾞｰﾀ RB_LENGTHﾊﾞｲﾄ */
	unsigned char iptr;				/* ﾃﾞｰﾀ入力用のﾎﾟｲﾝﾀ */
	unsigned char optr;				/* ﾃﾞｰﾀ出力用のﾎﾟｲﾝﾀ */
};


/*------------------------------------------*/
/*		ｸﾞﾛｰﾊﾞﾙ変数の宣言					*/
/*------------------------------------------*/
#ifdef MAIN

struct SC_T_RB	SC1_T_RS232C_RCV;			/* RS232C 受信ﾘﾝｸﾞﾊﾞｯﾌｧ */
struct SC_T_RB	SC1_T_RS232C_TRN;			/* RS232C 送信ﾘﾝｸﾞﾊﾞｯﾌｧ */


struct SC_T_RB	SC2_T_RS232C_RCV;			/* RS232C 受信ﾘﾝｸﾞﾊﾞｯﾌｧ */
struct SC_T_RB	SC2_T_RS232C_TRN;			/* RS232C 送信ﾘﾝｸﾞﾊﾞｯﾌｧ */


//	SCI0チャンネル（統括基板－SCRコントローラ）
unsigned char sc0_rs232c_getc(unsigned char* );	/* RS232C受信ﾊﾞｯﾌｧより一文字取得 */
unsigned char sc0_rs232c_putc(unsigned char );	/* RS232C送信ﾊﾞｯﾌｧへ一文字書き込み */
void sc0_rs232c_puts(unsigned char* );			/* RS232C送信ﾊﾞｯﾌｧへ文字列書き込み */


//	SCI1チャンネル（統括基板－HOST PC）
unsigned char sc1_rs232c_getc(unsigned char* );	/* RS232C受信ﾊﾞｯﾌｧより一文字取得 */
unsigned char sc1_rs232c_putc(unsigned char );	/* RS232C送信ﾊﾞｯﾌｧへ一文字書き込み */
void sc1_rs232c_puts(unsigned char* );			/* RS232C送信ﾊﾞｯﾌｧへ文字列書き込み */



unsigned char	sc_rb_write(struct SC_T_RB* , unsigned char );
unsigned char	sc_rb_read(struct SC_T_RB*, unsigned char*);


#else

extern struct SC_T_RB	SC1_T_RS232C_RCV;	/* RS232C 受信ﾘﾝｸﾞﾊﾞｯﾌｧ */
extern struct SC_T_RB	SC1_T_RS232C_TRN;	/* RS232C 送信ﾘﾝｸﾞﾊﾞｯﾌｧ */

extern struct SC_T_RB	SC2_T_RS232C_RCV;	/* RS232C 受信ﾘﾝｸﾞﾊﾞｯﾌｧ */
extern struct SC_T_RB	SC2_T_RS232C_TRN;	/* RS232C 送信ﾘﾝｸﾞﾊﾞｯﾌｧ */



//	SCI0チャンネル
extern unsigned char sc0_rs232c_getc(unsigned char* );	/* RS232C受信ﾊﾞｯﾌｧより一文字取得 */
extern unsigned char sc0_rs232c_putc(unsigned char );	/* RS232C送信ﾊﾞｯﾌｧへ一文字書き込み */
extern void sc0_rs232c_puts(unsigned char* );			/* RS232C送信ﾊﾞｯﾌｧへ文字列書き込み */


//	SCI1チャンネル
extern unsigned char sc1_rs232c_getc(unsigned char* );	/* RS232C受信ﾊﾞｯﾌｧより一文字取得 */
extern unsigned char sc1_rs232c_putc(unsigned char );	/* RS232C送信ﾊﾞｯﾌｧへ一文字書き込み */
extern void sc1_rs232c_puts(unsigned char* );			/* RS232C送信ﾊﾞｯﾌｧへ文字列書き込み */


extern	unsigned char	sc_rb_write(struct SC_T_RB* , unsigned char );
extern	unsigned char	sc_rb_read(struct SC_T_RB*, unsigned char*);

#endif

#endif