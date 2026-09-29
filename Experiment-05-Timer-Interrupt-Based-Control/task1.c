#include <reg51.h>

int count=0;
sbit led=P2^0;

void toggle_led(){
	led=!led;
}

void main() {
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	TR0=1;
	while(1) {
		if(TF0==1) {
			if(count==500) {
				toggle_led();
				count=0;
			}
			else count++;
			TF0=0;
			TH0=0xFC;
			TL0=0x66;
		}
	}
}
