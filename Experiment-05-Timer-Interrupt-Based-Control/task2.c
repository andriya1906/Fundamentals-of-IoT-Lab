#include <reg51.h>

int count=0;
int brightness_counter=0;
int level=0;
int dir=1;
sbit led=P2^0;

void main() {
	TMOD=0x01;
	TH0=0xFF;
	TL0=0xA4;
	TR0=1;
	led=0;
	while(1) {
		if(TF0==1) {
			if(brightness_counter==999) {
				if(level==10) dir=-1;
				if(level==0) dir=1;
				if(dir==1) level++;
				else if(dir==-1) level--;
				brightness_counter=0;
			}
			else brightness_counter++;
			if(level==0) {
				led=0;
				TF0=0;
				TH0=0xFF;
				TL0=0xA4;
				continue;
			}
			if(level==10) {
				led=1;
				TF0=0;
				TH0=0xFF;
				TL0=0xA4;
				continue;
			}
			if(count < level)
					led = 1;
			else
					led = 0;

			if(count == 9)
					count = 0;
			else
					count++;
			TF0=0;
			TH0=0xFF;
			TL0=0xA4;
		}	
	}
}
