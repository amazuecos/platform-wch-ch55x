/********************************** (C) COPYRIGHT *******************************
* File Name          : DEBUG.C
* Author             : WCH
* Version            : V1.3
* Date               : 2016/06/24
* Description        : CH559 DEBUG Interface
                     (1)������0�����ӡ��Ϣ�������ʿɱ�;
*******************************************************************************/
#include <stdint.h>
#include "DEBUG.h"
#define	 FREQ_SYS	12000000	                                                   //Ƶ12MHz
#ifndef  BUAD
#define  BUAD    57600
#endif

/*******************************************************************************
* Function Name  : CfgFsys( )
* Description    :

                   Fsys = (Fosc * ( PLL_CFG & MASK_PLL_MULT ))/(CLOCK_CFG & MASK_SYS_CK_DIV);

* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void	CfgFsys( )
{
    SAFE_MOD = 0x55;
    SAFE_MOD = 0xAA;
    CLOCK_CFG |= bOSC_EN_INT  ;       // Internal clock oscillator enabled
//    #if FREQ_SYS == 32000000
//        printf("Enable 32MHz");
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV | 0x07;  // 32MHz
//    #elif FREQ_SYS == 24000000
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV | 0x06;  // 24MHz
//    #elif FREQ_SYS == 16000000
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV | 0x05;  // 16MHz
//
//    #elif FREQ_SYS == 12000000   //Para la placa
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV | 0x04;  // 12MHz
//    #elif FREQ_SYS == 6000000
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV | 0x03;  // 6MHz
//    #elif FREQ_SYS == 3000000
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV | 0x02;  // 3MHz
//    #elif FREQ_SYS == 750000
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV | 0x01;  // 750KHz
//    #elif FREQ_SYS == 187500
//        CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_DIV   | 0x00;  // 187.5MHz
//    #else
//        #warning FREQ_SYS invalid or not set
//    #endif
    SAFE_MOD = 0xFF;

}

/*******************************************************************************
* Function Name  : mDelayus(UNIT16 n)
* Description    :
* Input          : UNIT16 n
* Output         : None
* Return         : None
*******************************************************************************/
void	mDelayuS( uint16_t n )
{
	while ( n ) {      // total = 12~13 Fsys cycles, 1uS @Fsys=12MHz
		++ SAFE_MOD;  // 2 Fsys cycles, for higher Fsys, add operation here
#ifdef	FREQ_SYS
#if		FREQ_SYS >= 14000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 16000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 18000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 20000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 22000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 24000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 26000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 28000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 30000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 32000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 34000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 36000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 38000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 40000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 42000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 44000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 46000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 48000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 50000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 52000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 54000000
		++ SAFE_MOD;
#endif
#if		FREQ_SYS >= 56000000
		++ SAFE_MOD;
#endif
#endif
		-- n;
	}
}

/*******************************************************************************
* Function Name  : mDelayms(UNIT16 n)
* Description    :
* Input          : UNIT16 n
* Output         : None
* Return         : None
*******************************************************************************/
void	mDelaymS( uint16_t n )                                                  // ��mSΪ��λ��ʱ
{
	while ( n )
	{
		mDelayuS( 1000 );
		-- n;
	}
}

/*******************************************************************************
* Function Name  : CH559UART0Alter()
* Description    : CH559 serial port 0 pin mapping, the serial port is mapped to P0.2 and P0.3
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CH559UART0Alter()
{
    PORT_CFG |= bP0_OC;
    P0_DIR |= bTXD_;
    P0_PU |= bTXD_ | bRXD_;
    PIN_FUNC |= bUART0_PIN_X;                                                  //Serial port is mapped to P0.2 and P0.3
}

/*******************************************************************************
* Function Name  : mInitSTDIO()
* Description    : CH559 serial port 0 is initialized, T1 is used as the baud rate generator of UART0 by default, and T2 can also be used
                   As a baud rate generator
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void	mInitSTDIO( )
{
    uint32_t x;
    uint8_t x2;

    SM0 = 0;
    SM1 = 1;
    SM2 = 0;                                                                   //Serial port 0 use mode 1
                                                                               //Use Timer1 as baud rate generator
    RCLK = 0;                                                                  //UART0 receive clock
    TCLK = 0;                                                                  //uarT0SendClock
    PCON |= SMOD;
    x = 10 * FREQ_SYS / BUAD / 16;                                             //If you change the main frequency, pay attention to the value of x not to overflow
    x2 = x % 10;
    x /= 10;
    if ( x2 >= 5 ) x ++;                                                       //rounding

    TMOD = TMOD & ~ bT1_GATE & ~ bT1_CT & ~ MASK_T1_MOD | bT1_M1;              //0X20, Timer1 as an 8-bit auto-reload timer
    T2MOD = T2MOD | bTMR_CLK | bT1_CLK;                                        //Timer1 clock selection
    TH1 = 0-x;                                                                 //12MHz crystal oscillator, buad/12 is the actual baud rate that needs to be set
    TR1 = 1;                                                                   //Start timer 1
    TI = 1;
    REN = 1;                                                                   //Serial 0 receive enable
}

/*******************************************************************************
* Function Name  : CH559UART0RcvByte()
* Description    : CH559UART0 receives a byte
* Input          : None
* Output         : None
* Return         : SBUF
*******************************************************************************/
uint8_t  uart0_read( )
{
    while(!RI);                                                            //Query receiving, interrupt mode is not necessary
    RI = 0;
    return SBUF;
}

/*******************************************************************************
* Function Name  : CH559UART0SendByte(UINT8 SendDat)
* Description    : CH559UART0 sends a byte
* Input          : UINT8 SendDat; the data to be sent
* Output         : None
* Return         : None
*******************************************************************************/
void uart0_write(uint8_t SendDat)
{
	while(!TI);
	TI = 0;
	SBUF = SendDat&0xFF;                                                              //Query sending, interrupt mode can not use the following 2 sentences, but TI=0 before sending
}

void Uart0SendString(char *msg){
    while(*msg){
        uart0_write(*msg++);
    }
}
