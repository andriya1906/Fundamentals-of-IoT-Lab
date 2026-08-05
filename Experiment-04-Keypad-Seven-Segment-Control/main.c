#include <reg51.h>

// ---------------------------
// Keypad Connections (Port 2)
// ---------------------------
sbit button_7 = P2^7;
sbit button_6 = P2^6;
sbit button_5 = P2^5;
sbit button_4 = P2^4;
sbit button_3 = P2^3;
sbit button_2 = P2^2;
sbit button_1 = P2^1;
sbit button_0 = P2^0;

// Decimal Point of Seven Segment Display
sbit DP = P0^7;

// LED Connections (Port 3)
sbit led1 = P3^0;
sbit led2 = P3^1;
sbit led3 = P3^2;
sbit led4 = P3^3;

// Stores the currently pressed key
// 10 indicates that no key is pressed
unsigned char key = 10;

// Function Prototypes
void delay(void);
void keypad_scan(void);
void display_digit(void);
void led_control(void);
void running_led(void);
void alternative_led(void);
void binary_counter(void);
void blink_all(void);
void led_off(void);

// -------------------------------------------------------
// Software delay with continuous keypad polling.
// If a different key is detected during the delay,
// the function exits immediately for quick response.
// -------------------------------------------------------
void delay(void)
{
    int i, j;

    for(i = 0; i < 125; i++)
    {
        for(j = 0; j < 125; j++)
        {
            unsigned char temp = key;

            keypad_scan();

            // Exit delay if the pressed key changes
            if(key != temp)
                return;
        }
    }
}

// -------------------------------------------------------
// Scans the 4x4 keypad by activating one row at a time
// and checking the corresponding column inputs.
// Updates the global variable 'key' with the detected key.
// -------------------------------------------------------
void keypad_scan(void)
{
    unsigned char newkey = 10;

    // Scan Row 1
    button_7 = 0;
    button_6 = 1;
    button_5 = 1;

    button_3 = 1;
    button_2 = 1;
    button_1 = 1;
    button_0 = 1;

    if(button_3 == 0)
        key = '1';
    else if(button_2 == 0)
        key = '2';
    else if(button_1 == 0)
        key = '3';
    else if(button_0 == 0)
        key = '4';

    // Scan Row 2
    if(newkey == 10)
    {
        button_7 = 1;
        button_6 = 0;
        button_5 = 1;

        if(button_3 == 0)
            key = '5';
        else if(button_2 == 0)
            key = '6';
        else if(button_1 == 0)
            key = '7';
        else if(button_0 == 0)
            key = '8';
    }

    // Scan Row 3
    if(newkey == 10)
    {
        button_7 = 1;
        button_6 = 1;
        button_5 = 0;

        if(button_3 == 0)
            key = '9';
        else if(button_2 == 0)
            key = '0';
    }

    if(newkey != 10)
        newkey = key;
}

// -------------------------------------------------------
// Displays the pressed key on the seven-segment display
// using common hexadecimal segment codes.
// -------------------------------------------------------
void display_digit(void)
{
    if(key=='0') { P0=0x3F; return; }
    if(key=='1') { P0=0x06; return; }
    if(key=='2') { P0=0x5B; return; }
    if(key=='3') { P0=0x4F; return; }
    if(key=='4') { P0=0x66; return; }
    if(key=='5') { P0=0x6D; return; }
    if(key=='6') { P0=0x7D; return; }
    if(key=='7') { P0=0x07; return; }
    if(key=='8') { P0=0x7F; return; }
    if(key=='9') { P0=0x6F; return; }
}

// -------------------------------------------------------
// Controls individual LEDs for keys 1-4.
// Only the corresponding LED remains ON.
// -------------------------------------------------------
void led_control(void)
{
    if(key=='1')
    {
        led1=1;
        led2=led3=led4=0;
        delay();
        if(key!='1') return;
    }

    else if(key=='2')
    {
        led2=1;
        led1=led3=led4=0;
        delay();
        if(key!='2') return;
    }

    else if(key=='3')
    {
        led3=1;
        led1=led2=led4=0;
        delay();
        if(key!='3') return;
    }

    else if(key=='4')
    {
        led4=1;
        led1=led2=led3=0;
        delay();
        if(key!='4') return;
    }
}

// -------------------------------------------------------
// Mode 1 - Running LED Pattern
// LEDs glow sequentially from LED1 to LED4.
// -------------------------------------------------------
void running_led()
{
    while(key=='5')
    {
        led2=led3=led4=0;
        led1=1;
        delay();
        if(key!='5') break;

        led1=led3=led4=0;
        led2=1;
        delay();
        if(key!='5') break;

        led2=led1=led4=0;
        led3=1;
        delay();
        if(key!='5') break;

        led2=led3=led1=0;
        led4=1;
        delay();
        if(key!='5') break;
    }
}

// -------------------------------------------------------
// Mode 2 - Alternating LED Pattern
// Displays 1010 and 0101 alternately.
// -------------------------------------------------------
void alternative_led()
{
    while(key=='6')
    {
        led1=led3=0;
        led2=led4=1;
        delay();
        if(key!='6') break;

        led1=led3=1;
        led2=led4=0;
        delay();
        if(key!='6') break;
    }
}

// -------------------------------------------------------
// Mode 3 - 4-bit Binary Counter
// Counts from 0 to 15 using the four LEDs.
// -------------------------------------------------------
void binary_counter()
{
    while(key=='7')
    {
        int i;

        for(i=0; i<16; i++)
        {
            P3=i;
            delay();

            if(key!='7')
                return;
        }
    }
}

// -------------------------------------------------------
// Mode 4 - Blink All LEDs
// Turns all LEDs ON and OFF repeatedly.
// -------------------------------------------------------
void blink_all()
{
    while(key=='8')
    {
        led1=led2=led3=led4=1;
        delay();
        if(key!='8') return;

        led1=led2=led3=led4=0;
        delay();
        if(key!='8') return;
    }
}

// -------------------------------------------------------
// Turns OFF all LEDs while key 9 is selected.
// -------------------------------------------------------
void led_off()
{
    while(key=='9')
    {
        led1=led2=led3=led4=0;
        delay();

        if(key!='9')
            return;
    }
}

// -------------------------------------------------------
// Main Function
// Continuously scans the keypad, updates the display,
// and executes the selected LED operation.
// -------------------------------------------------------
void main()
{
    // Initialize LEDs and seven-segment display
    led1=led2=led3=led4=0;
    P0=0;

    while(1)
    {
        // Wait until a valid key is pressed
        while(key==10)
        {
            keypad_scan();
        }

        // Display the pressed key
        display_digit();

        // Execute the corresponding operation
        switch(key)
        {
            case '1':
            case '2':
            case '3':
            case '4':
                led_control();
                break;

            case '5':
                running_led();
                break;

            case '6':
                alternative_led();
                break;

            case '7':
                binary_counter();
                break;

            case '8':
                blink_all();
                break;

            case '9':
                led_off();
                break;

            case '0':
                // Reset the system
                key=10;
                led1=led2=led3=led4=0;
                P0=0x3F;
                break;

            default:
                break;
        }
    }
}
