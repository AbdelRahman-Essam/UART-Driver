#include "std_types.h"
#include "utils.h"

#include "UART_priv.h"
#include "UART_config.h"
#include "UART_int.h"
void __vector_15 (void) __attribute__ ((signal,used, externally_visible));
void __vector_13 (void) __attribute__ ((signal,used, externally_visible));

void (*TX_COMPLETE_ISR)(void)  = '\0';
void (*RX_COMPLETE_ISR)(void)  = '\0';

void UART_voidInit(void)
{
    /*** Double the transmission speed ***/
#if(UART_DOUBLE_TRANS==DOUBLE_TRANS_ENABLE)
    SETBIT(UCSRA, U2X);
#elif(UART_DOUBLE_TRANS==DOUBLE_TRANS_DISAPLE)
    CLRBIT(UCSRA, U2X);
#endif

    /*** Enable Tx and Rx ***/
    SETBIT(UCSRB, RXEN);
    SETBIT(UCSRB, TXEN);

    /*** Enable Tx and Rx Complete Interrupts ***/
    SETBIT(UCSRB, RXCIE);
    SETBIT(UCSRB, TXCIE);


    /*** Select UCSRC Register ***/
    SETBIT(UCSRC, URSEL);


    /*** Set 8-bit mode ***/
    SETBIT(UCSRC, UCSZ0);
    SETBIT(UCSRC, UCSZ1);
    CLRBIT(UCSRB, UCSZ2);


    /*** Set Parity mode ***/
    #if (UART_PARITY == NO_PARITY)
        CLRBIT(UCSRC, UPM0);
        CLRBIT(UCSRC, UPM1);
    #elif (UART_PARITY == EVEN_PARITY)
        CLRBIT(UCSRC, UPM0);
        SETBIT(UCSRC, UPM1);
    #elif (UART_PARITY == ODD_PARITY)
        SETBIT(UCSRC, UPM0);
        SETBIT(UCSRC, UPM1);
    #endif

    /*** Set Stop bit ***/
    #if (UART_STOP_BIT == STOP_BIT_1)
        CLRBIT(UCSRC,USBS);
    #elif (UART_STOP_BIT == STOP_BIT_2)
        SETBIT(UCSRC, USBS);
    #endif


        /*** Set Baud Rate ***/
#if(OSCIL_FREQ== UART_1_Mega_Hertz)
	#if(UART_DOUBLE_TRANS==DOUBLE_TRANS_ENABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 0;
        	UBRRL = 25;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 12;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 8;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 6;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 3;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 2;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)

    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 0;
        	UBRRL = 0;
    	#endif
	#elif(UART_DOUBLE_TRANS==DOUBLE_TRANS_DISABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 0;
        	UBRRL = 12;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 6;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 3;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 2;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 1;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 1;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)
        	UBRRH = 0;
        	UBRRL = 0;
    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 0;
        	UBRRL = 0;
    	#endif
	#endif
#elif(OSCIL_FREQ== UART_4_Mega_Hertz)
	#if(UART_DOUBLE_TRANS==DOUBLE_TRANS_ENABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 0;
        	UBRRL = 103;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 51;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 34;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 25;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 16;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 12;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)
        	UBRRH = 0;
        	UBRRL = 8;
    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 0;
        	UBRRL = 3;
    	#endif
	#elif(UART_DOUBLE_TRANS==DOUBLE_TRANS_DISABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 0;
        	UBRRL = 51;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 25;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 16;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 12;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 8;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 6;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)
        	UBRRH = 0;
        	UBRRL = 3;
    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 0;
        	UBRRL = 1;
    	#endif
	#endif
#elif(OSCIL_FREQ== UART_8_Mega_Hertz)
	#if(UART_DOUBLE_TRANS==DOUBLE_TRANS_ENABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 0;
        	UBRRL = 207;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 103;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 68;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 51;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 34;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 25;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)
        	UBRRH = 0;
        	UBRRL = 16;
    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 0;
        	UBRRL = 8;
    	#endif
	#elif(UART_DOUBLE_TRANS==DOUBLE_TRANS_DISABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 0;
        	UBRRL = 103;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 51;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 34;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 25;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 16;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 12;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)
        	UBRRH = 0;
        	UBRRL = 8;
    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 0;
        	UBRRL = 3;
    	#endif
	#endif
#elif(OSCIL_FREQ== UART_16_Mega_Hertz)
	#if(UART_DOUBLE_TRANS==DOUBLE_TRANS_DISABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 0;
        	UBRRL = 207;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 103;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 68;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 51;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 34;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 25;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)
        	UBRRH = 0;
        	UBRRL = 16;
    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 0;
        	UBRRL = 8;
    	#endif
	#elif(UART_DOUBLE_TRANS==DOUBLE_TRANS_ENABLE)
    	#if (UART_BAUD_RATE == BAUD_RATE_4800)
        	UBRRH = 1;
        	UBRRL = 160;
    	#elif (UART_BAUD_RATE == BAUD_RATE_9600)
        	UBRRH = 0;
        	UBRRL = 207;
		#elif (UART_BAUD_RATE == BAUD_RATE_14400)
        	UBRRH = 0;
        	UBRRL = 138;
    	#elif (UART_BAUD_RATE == BAUD_RATE_19200)
        	UBRRH = 0;
        	UBRRL = 103;
    	#elif (UART_BAUD_RATE == BAUD_RATE_28800)
        	UBRRH = 0;
        	UBRRL = 68;
		#elif (UART_BAUD_RATE == BAUD_RATE_38400)
        	UBRRH = 0;
        	UBRRL = 51;
    	#elif (UART_BAUD_RATE == BAUD_RATE_57600)
        	UBRRH = 0;
        	UBRRL = 34;
    	#elif (UART_BAUD_RATE == BAUD_RATE_115200)
        	UBRRH = 16;
        	UBRRL = 3;
    	#endif
	#endif
#endif
    }
void UART_voidSetDataRegister(u8 Local_Data)
{
while(!(GET_BIT(UCSRA,5)));
    UDR = Local_Data;
}
u8 UART_u8GetDataRegister(void)
{
	while ( !(UCSRA & (1<<RXC)) );
    return UDR;
}
void UART_voidSetTxComplete_ISR(void (*Local_ISR)(void))
{
    TX_COMPLETE_ISR = Local_ISR;
}
void UART_voidSetRxComplete_ISR(void (*Local_ISR)(void))
{
    RX_COMPLETE_ISR = Local_ISR;
}
void __vector_15 (void)
{
    TX_COMPLETE_ISR();
}
void __vector_13 (void)
{
	RX_COMPLETE_ISR();
}







