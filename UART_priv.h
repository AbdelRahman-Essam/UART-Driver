#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define UCSRA (*(volatile u8 *)(0x2B))
#define UCSRB (*(volatile u8 *)(0x2A))
#define UCSRC (*(volatile u8 *)(0x40))
#define UBRRL (*(volatile u8 *)(0x29))
#define UBRRH (*(volatile u8 *)(0x40))
#define UDR   (*(volatile u8 *)(0x2C))

#define MPCM 	0
#define U2X 	1
#define PE		2
#define DOR		3
#define FE		4
#define UDRE	5
#define TXC		6
#define RXC		7

#define TXB8 	0
#define RXB8 	1
#define UCSZ2	2
#define TXEN	3
#define RXEN	4
#define UDRIE	5
#define TXCIE	6
#define RXCIE	7

#define UCPOL 	0
#define UCSZ0 	1
#define UCSZ1	2
#define USBS	3
#define UPM0	4
#define UPM1	5
#define UMSEL	6
#define URSEL	7

/*** Oscillator Frequencies ***/
#define UART_1_Mega_Hertz	0
#define UART_4_Mega_Hertz	1
#define UART_8_Mega_Hertz	2
#define UART_16_Mega_Hertz	3


/*** Baud Rate ***/
#define BAUD_RATE_4800    1
#define BAUD_RATE_9600    2
#define BAUD_RATE_14400   3
#define BAUD_RATE_19200   4
#define BAUD_RATE_28800   5
#define BAUD_RATE_38400   6
#define BAUD_RATE_57600   7
#define BAUD_RATE_115200  8

/*** Parity mode ***/
#define NO_PARITY         9
#define EVEN_PARITY       10
#define ODD_PARITY        11

/*** Stop Bit ***/
#define STOP_BIT_1        12
#define STOP_BIT_2        13

/*** Double Transmission ***/

#define  DOUBLE_TRANS_ENABLE	1
#define  DOUBLE_TRANS_DISABLE	2


#endif /* UART_PRIV_H_ */
