/********************************************************************/
/*																	*/
/* ファイル名	appli.h												*/
/*																	*/
/* 機能概略		アプリケーション用のヘッダーファイル				*/
/*																	*/
/*																	*/
/********************************************************************/
#ifndef  _APPLI_H_
#define  _APPLI_H_

/********************************************************************/
/*		define														*/
/********************************************************************/

typedef signed char SBYTE;
typedef unsigned char UBYTE;
typedef unsigned char BYTE;
typedef signed short SWORD;
typedef unsigned short UWORD;
typedef signed int SINT;
typedef unsigned int UINT;
typedef signed long SDWORD;
typedef unsigned long UDWORD;


#define		M_CS1		IO.PDR7.BIT.B4
#define		M_CS2		IO.PDR7.BIT.B5
#define		M_CS3		IO.PDR2.BIT.B3
#define		M_CS4		IO.PDR7.BIT.B0

#define		M_TXD		IO.PDR2.BIT.B2
#define		M_SCK		IO.PDR2.BIT.B0
#define		M_RXD		IO.PDR2.BIT.B1

#define		LED1		IO.PDR3.BIT.B0
#define		LED2		IO.PDR3.BIT.B1
#define		LED3		IO.PDR3.BIT.B2
#define		LED4		IO.PDR3.BIT.B3

#define		M_ENABLE	IO.PDR2.BIT.B4
#define		M_ALM		IO.PDRB.BIT.B6

#define		SW1			IO.PDR1.BIT.B7
#define		SW2			IO.PDR1.BIT.B6
#define		SW3			IO.PDR1.BIT.B5

#define		SCL			IO.PDR5.BIT.B7
#define		SDA			IO.PDR5.BIT.B6


#define		MCW1		IO.PDR5.BIT.B0
#define		MCCW1		IO.PDR5.BIT.B1
#define		MCW2		IO.PDR3.BIT.B4
#define		MCCW2		IO.PDR3.BIT.B5
#define		MCW3		IO.PDR3.BIT.B6
#define		MCCW3		IO.PDR3.BIT.B7
#define		MCW4		IO.PDR5.BIT.B2
#define		MCCW4		IO.PDR5.BIT.B3



//GAME_PAD
#define PS_SEL_raise	IO.PDR1.BIT.B1 = 1
#define PS_SEL_fall		IO.PDR1.BIT.B1 = 0
#define PS_CLK_raise	IO.PDR1.BIT.B2 = 1
#define PS_CLK_fall		IO.PDR1.BIT.B2 = 0
#define PS_CMD_raise	IO.PDR5.BIT.B5 = 1
#define PS_CMD_fall		IO.PDR5.BIT.B5 = 0
#define PS_DAT			IO.PDR5.BIT.B4
#define PS_CLK_BIT		IO.PDR1.BIT.B2


/*
		b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0
B1：	左 | 下 | 右 | 上 |ｽﾀｰﾄ| R3 | L3 |ｾﾚｸﾄ
B2：	□ | × | ○ | △ | R1 | L1 | R2 | L2 
AN_*X：	左:00h,中心:80h,右:FFh
AN_*Y：	上:00h,中心:80h,下:FFh
*/
enum PADDATA{
PAD_B1,			//ボタン1バイト目
PAD_B2,			//ボタン2バイト目
PAD_AN_RX,		//右アナログスティック左右
PAD_AN_RY,		//右アナログスティック上下
PAD_AN_LX,		//左アナログスティック左右
PAD_AN_LY		//左アナログスティック上下
};



/********************************************************************/
/*		APﾓｼﾞｭｰﾙのｸﾞﾛｰﾊﾞﾙ変数宣言									*/
/********************************************************************/

#ifdef	MAIN
		
		unsigned short	CLOCK_1MSEC_COUNTER, CLOCK_100MSEC_COUNTER;		/* 1msecｶｳﾝﾀ */
		unsigned char	B1DATE, B2DATE, B1DATE2, B2DATE2;
		unsigned char	Code_flg, CODE[16];
		short			XSPEED, YSPEED, XSPEED2, YSPEED2,TURN;
		unsigned short	LIPO[10], PC_CNT;
		char			AD_CNT, AD_FLG, SENSOR, LOW_FLG, MDIR[4];
		float			TARGET_SPD[4], CURRENT_SPD[4], VSP, MSP_UP;


	
#endif

#ifndef	MAIN
		
		extern unsigned short	CLOCK_1MSEC_COUNTER, CLOCK_100MSEC_COUNTER;		/* 1msecｶｳﾝﾀ */
		extern unsigned char	B1DATE, B2DATE, B1DATE2, B2DATE2;
		extern unsigned char	Code_flg, CODE[16];
		extern short			XSPEED, YSPEED, XSPEED2, YSPEED2;
		extern unsigned short	LIPO[10], PC_CNT;
		extern char				AD_CNT, AD_FLG, SENSOR, LOW_FLG, MDIR[4];
		extern float			TARGET_SPD[4], CURRENT_SPD[4], VSP, MSP_UP;
	
#endif

#endif

