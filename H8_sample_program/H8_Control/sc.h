/********************************************************************/
/*																	*/
/* �t�@�C����	sc.h												*/
/*																	*/
/* �@�\�T��		�رْʐM�p�̃w�b�_�[�t�@�C��						*/
/* 																	*/
/*																	*/
/********************************************************************/
#ifndef _SC_H_
#define	_SC_H_


#include <machine.h>

/*------------------------------------------*/
/*		define								*/
/*------------------------------------------*/
#define		CR_CODE			0x0d		/* ��د�����݂̺��� */
#define		RB_LENGTH		128		/* �ݸ��ޯ̧��(�޲�) */



/*------------------------------------------*/
/*		�\���̥���p�̐錾					*/
/*------------------------------------------*/

/*------	�ݸ��ޯ̧�̍\����		  ------*/
struct SC_T_RB {
	unsigned char data[RB_LENGTH];	/* �ݸ��ޯ̧���ް� RB_LENGTH�޲� */
	unsigned char iptr;				/* �ް����͗p���߲�� */
	unsigned char optr;				/* �ް��o�͗p���߲�� */
};


/*------------------------------------------*/
/*		��۰��ٕϐ��̐錾					*/
/*------------------------------------------*/
#ifdef MAIN

struct SC_T_RB	SC1_T_RS232C_RCV;			/* RS232C ��M�ݸ��ޯ̧ */
struct SC_T_RB	SC1_T_RS232C_TRN;			/* RS232C ���M�ݸ��ޯ̧ */


struct SC_T_RB	SC2_T_RS232C_RCV;			/* RS232C ��M�ݸ��ޯ̧ */
struct SC_T_RB	SC2_T_RS232C_TRN;			/* RS232C ���M�ݸ��ޯ̧ */


//	SCI0�`�����l���i������|SCR�R���g���[���j
unsigned char sc0_rs232c_getc(unsigned char* );	/* RS232C��M�ޯ̧���ꕶ���擾 */
unsigned char sc0_rs232c_putc(unsigned char );	/* RS232C���M�ޯ̧�ֈꕶ���������� */
void sc0_rs232c_puts(unsigned char* );			/* RS232C���M�ޯ̧�֕����񏑂����� */


//	SCI1�`�����l���i������|HOST PC�j
unsigned char sc1_rs232c_getc(unsigned char* );	/* RS232C��M�ޯ̧���ꕶ���擾 */
unsigned char sc1_rs232c_putc(unsigned char );	/* RS232C���M�ޯ̧�ֈꕶ���������� */
void sc1_rs232c_puts(unsigned char* );			/* RS232C���M�ޯ̧�֕����񏑂����� */



unsigned char	sc_rb_write(struct SC_T_RB* , unsigned char );
unsigned char	sc_rb_read(struct SC_T_RB*, unsigned char*);


#else

extern struct SC_T_RB	SC1_T_RS232C_RCV;	/* RS232C ��M�ݸ��ޯ̧ */
extern struct SC_T_RB	SC1_T_RS232C_TRN;	/* RS232C ���M�ݸ��ޯ̧ */

extern struct SC_T_RB	SC2_T_RS232C_RCV;	/* RS232C ��M�ݸ��ޯ̧ */
extern struct SC_T_RB	SC2_T_RS232C_TRN;	/* RS232C ���M�ݸ��ޯ̧ */



//	SCI0�`�����l��
extern unsigned char sc0_rs232c_getc(unsigned char* );	/* RS232C��M�ޯ̧���ꕶ���擾 */
extern unsigned char sc0_rs232c_putc(unsigned char );	/* RS232C���M�ޯ̧�ֈꕶ���������� */
extern void sc0_rs232c_puts(unsigned char* );			/* RS232C���M�ޯ̧�֕����񏑂����� */


//	SCI1�`�����l��
extern unsigned char sc1_rs232c_getc(unsigned char* );	/* RS232C��M�ޯ̧���ꕶ���擾 */
extern unsigned char sc1_rs232c_putc(unsigned char );	/* RS232C���M�ޯ̧�ֈꕶ���������� */
extern void sc1_rs232c_puts(unsigned char* );			/* RS232C���M�ޯ̧�֕����񏑂����� */


extern	unsigned char	sc_rb_write(struct SC_T_RB* , unsigned char );
extern	unsigned char	sc_rb_read(struct SC_T_RB*, unsigned char*);

#endif

#endif