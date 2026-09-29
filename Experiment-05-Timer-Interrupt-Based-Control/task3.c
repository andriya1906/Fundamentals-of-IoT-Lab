#include <reg51.h>

int count=0;
int step=0;
int key=0;
sbit bit0=P3^0;
sbit bit1=P3^1;
sbit bit2=P3^2;
sbit bit3=P3^3;

sbit ROW=P2^7;
sbit slow=P2^3;
sbit medium=P2^2;
sbit fast=P2^1;

void timer_0() interrupt 1 {
	count++;
	TF0=0;
	TH0=0xFC;
	TL0=0x66;
}

void delay() {
	int i;
	int j;
	for(i=0; i<50; i++) {
		for(j=0; j<50; j++) {
		}
	}
}

void movement(){
	if(step==0) {
		bit0=1;
		bit1=bit2=bit3=0;
	}
	if(step==1) {
		bit1=1;
		bit0=bit2=bit3=0;
	}
	if(step==2) {
		bit2=1;
		bit1=bit0=bit3=0;
	}
	if(step==3) {
		bit3=1;
		bit1=bit2=bit0=0;
	}
}

void mode_1() {
			if(count==99) {
				movement();
				count=0;
				step++;
				if(step==4) step=0;
			}
			
}

void mode_2() {
			if(count==49) {
				movement();
				count=0;
				step++;
				if(step==4) step=0;
			}
}


void mode_3() {
			if(count==9) {
				movement();
				step++;
				count=0;
				if(step==4) step=0;
			}
}

int keypad_scan() {
	ROW=0;
	slow=medium=fast=1;
	
	if(slow==0) {
		delay();
		if(slow==0) {
			while(!slow);
			return 1;
		}
	}
	
	if(medium==0) {
		delay();
		if(medium==0) {
			while(!medium);
			return 2;
		}
	}
	
	if(fast==0) {
		delay();
		if(fast==0) {
			while(!fast);
			return 3;
		}
	}
	return 0;
}	

void main() {
	int newkey;
	int previous_key=0;
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	EA=1;
	ET0=1;
	TR0=1;
	while(1) {
		newkey=keypad_scan();
		if(newkey != 0 && previous_key == 0) {
        key = newkey;
				count = 0;
    }
    previous_key = newkey;
		switch(key) {
			case 1:
				mode_1();
				break;
			
			case 2:
				mode_2();
				break;
			
			case 3:
				mode_3();
				break;
		}
	}
}
