#include "CH559.h"
#include <stdio.h>

#include "config.h"
#include "DEBUG.h"
#include "nokialcd.h"
SBIT(P1_0,0xA0,0);
SBIT(P1_1,0xA0,1);
SBIT(P1_2,0xA0,2);
SBIT(P1_3,0xA0,3);
SBIT(P1_4,0xA0,4);
SBIT(P1_5,0xA0,5);

int putchar(int c) {
    uart0_write(c);
    return 0;
}
/*
 * Redirect stdin to UART0
 */
int getchar() {
    return uart0_read();
}
void main(void){

    CfgFsys();
    mDelaymS(10);
    mInitSTDIO();
    //ConfigOutputInputPin();
    Initialize_LCD();
    EnableExternalPinInterrupt();
    setCursor(0,0);
    stringDisp("HELLO");
    while(1){
        P1_0 = !P1_0;
        mDelaymS(100);
        P1_1 = !P1_1;
        mDelaymS(100);
        P1_2 = !P1_2;
        mDelaymS(100);
        P1_3 = !P1_3;
        mDelaymS(100);
        P1_4 = !P1_4;
        mDelaymS(100);
        IsPressBootloader();
    }
}