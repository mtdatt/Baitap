// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 20000000 //define crystal frequency to 20MHz
void timer1delay(void){     //?? tr? 100ms 
    T1CON=0x31;           //Timer-1 v?i Prescaler 1:8 
    TMR1H=0x0B;             //??m ?? tr? Byte cao 100ms @20Mhz
    TMR1L=0xDB;             //??m s? byte th?p 
    GIE=1;          //Kích ho?t ng?t toàn c?c
    PEIE=1;         //Kích ho?t ng?t ngo?i vi 
    TMR1ON =1;     //Kh?i ??ng Timer1    
    for(int i=1; i<=5;i++){  //ch?y vòng l?p for 5 l?n ?? có 0,5 giây
    while(!TMR1IF);
		TMR1IF = 0;		//B?t Timer sau khi tràn // Xóa ng?t 
    }
}

void main(void) 
{
//TRISC0 = 1; //Define PORTC pin 0 is used as input for push button.
TRISD = 0x00; //H??ng d?n MCU r?ng t?t c? các chân ??u là ??u ra 
PORTD=0x00; //Xác ??nh PORT D là ??u ra 
while(1) //xác ??nh vòng l?p While ?? ho?t ??ng liên t?c 
{
    PORTD=0xFF; //Turn ON all LEDs
    timer1delay();
    PORTD=0x00; //Turn OFF all LEDs
    timer1delay();

}
}
