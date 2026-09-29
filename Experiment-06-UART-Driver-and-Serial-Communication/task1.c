#include <reg51.h>

void main() {
	PCON=0x00;
	SM0=0;
	SM1=1;
	TH1=0xFD;
	TMOD=0x20;
	TR1=1;
	while(1) {
		SBUF='X';
		while(TI==0);
		TI=0;
	}
}
