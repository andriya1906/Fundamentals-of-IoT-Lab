#include <reg51.h>
sbit E=P3^3;

void delay(int n) {
	int i;
	int j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
		}
	}
	E=0;
}

void main() {
	// Function Set 
	P3=0x28;
	delay(250);
	P3=0x08;
	delay(250);
	
	// Display, Cursor
	P3=0x08;
	delay(250);
	P3=0xF8;
	delay(250);

	
	// Incrementing 
	P3=0x08;
	delay(250);
	P3=0x68;
	delay(250);
	
	// Clear Display
	P3=0x08;
	delay(500);
	P3=0x18;
	delay(500);
	
  while(1) {
  	P3=0x4C;
  	delay(100);
  	P3=0x3C;
  	delay(100);
  }
}
