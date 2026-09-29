#include <reg51.h>

void main() {
	PCON=0x00;       // Clear SMOD bit for normal baud rate
	SM0=0;           // UART Mode 1
	SM1=1;           // UART Mode 1
	
	TH1=0xFD;        // Timer 1 reload value for 9600 baud
	TMOD=0x20;       // Timer 1, Mode 2 (8-bit auto-reload)
	TR1=1;           // Start Timer 1
	
	while(1) {
		SBUF='X';            // Load character X into transmit buffer
		while(TI==0);        // Wait until transmission is complete
		TI=0;                 // Clear transmit interrupt flag
	}
}
