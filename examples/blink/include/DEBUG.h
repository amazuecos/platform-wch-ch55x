#include <stdint.h>
#include "CH559.h"
void	CfgFsys( );                        //CH559 clock selection and configuration
void	mDelayuS( uint16_t n );            // Delay in uS
void	mDelaymS( uint16_t n );            // Delay in mS
void  CH559UART0Alter();                   //CH559 serial port 0 pin is mapped to P0.2/P0.3.2/P0.3
void	mInitSTDIO( );                     //T1 as a baud rate generator
uint8_t uart0_read( );              //CH559 UART0 receiving one byte in query mode
void  uart0_write(uint8_t SendDat); //CH559UART0 sends a byte
void Uart0SendString(char *msg);
