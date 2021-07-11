#include "CH559.h"
#include <stdio.h>
#include "DEBUG.h"



void main(void){

    CfgFsys();
    mDelaymS(10);
    mInitSTDIO();

    while(1){
        P1_0 = !P1_0;
        mDelaymS(1000);

    }
}