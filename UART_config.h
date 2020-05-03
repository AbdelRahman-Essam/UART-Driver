#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
/*** Oscillator Frequencies ***/
/*
 * UART_1_Mega_Hertz
 * UART_4_Mega_Hertz
 * UART_8_Mega_Hertz
 * UART_16_Mega_Hertz
 */
#define OSCIL_FREQ	UART_8_Mega_Hertz


/*** Double Transmission ***/
/*
 *  DOUBLE_TRANS_ENABLE
 *  DOUBLE_TRANS_DISABLE
 */
#define UART_DOUBLE_TRANS	DOUBLE_TRANS_DISABLE



/*** Baud Rate ***/
/* BAUD_RATE_4800
 * BAUD_RATE_9600
 * BAUD_RATE_14400
 * BAUD_RATE_19200
 * BAUD_RATE_28800
 * BAUD_RATE_38400
 * BAUD_RATE_57600
 * BAUD_RATE_115200
 */
#define UART_BAUD_RATE  BAUD_RATE_9600

/*** Parity mode ***/
/* NO_PARITY
 * EVEN_PARITY
 * ODD_PARITY
 */
#define UART_PARITY     EVEN_PARITY

/*** Stop Bit ***/
/*
 *STOP_BIT_1
 *STOP_BIT_2
 */
#define UART_STOP_BIT   STOP_BIT_1









#endif /* UART_CONFIG_H_ */
