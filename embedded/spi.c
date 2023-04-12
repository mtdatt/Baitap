/*
 * File:   newmain.c
 * Author: ThanhDat
 *
 * Created on Ng�y 10 th�ng 4 n?m 2023, 16:02
 */


#include <xc.h>
#include<stdio.h>
#include<stdint.h>
#include<pic16f877a.h>
#define _XTAL_FREQ 20000000

#define SCK  RC3    // chân SCK
#define MOSI RC4   // Chân MOSI
#define SS   RE2     // Chân SS
#define MISO RC5  // chân MISO


void SPI_Soft_init();/*chương trình khởi tạo SPI*/ 
void Clock();  /*---chương trình khởi 1 xung clock---------*/
void SPI_Soft_Transmit(uint8_t mData);/*------chương trình gửi 1 byte---------*/
uint8_t SPI_Soft_Receive();   /*------chương trình nhận 1 byte---------*/

// ham khoi tao SPI
void SPI_Soft_init(){
  SCK   = 0;  /*sck = 0 chưa tạo xung clock */
  MOSI  = 0; /*chưa truyền data ở chân mosi*/
  SS    = 1;  /*chưa cho phép slave truyền*/
}

// ham tao xung clock
void Clock(){
  SCK = 1; 
  __delay_us(5); 
  SCK = 0; 
  __delay_us(5); 
}

/*------chương trình gửi 1 byte---------*/
void SPI_Soft_Transmit(uint8_t Data){ 
  uint8_t i = 0, x = 0;   
  SS = 0;   
  for(i = 0; i < 8; i++){ 
    x = Data&0x80; /*bit cao nhất của byte Data AND 0x80*/
    if(x!=0)      
    {
      MOSI = 1;  /*Nếu bit cao nhất của Data AND với 0x80 = 1 thì giá trị bit chân MOSI = 1*/
    }
    else
      MOSI=0;   
    Clock(); /* phát 1 xung clock gửi dữ liệu đi*/ 
    Data = Data<<1; /* dịch 1 bit Data sang trái*/   
  }  
  SS=1; /*Đã gửi xong,đưa chân SS lên mức 1*/
}

/*------chương trình master nhận về 1 byte từ slave---------*/

uint8_t SPI_Soft_Receive(){  
  uint8_t _data=0x00, i=0;  
  while(i<8){     
    _data = _data<<1;       /*dịch dữ liệu sang trái 1 bit*/  
    if(MISO)
      _data |= 0x01;    /* Nếu chân MISO ở mức 1 thì sẽ trả về giá trị _data = _data OR với 0x01 */ 
    Clock();                /*phát một xung clock để đọc bit */
  }   
  return _data;             /*trả về dữ liệu đọc được */
}
main()
{
    SPI_Soft_Transmit(01001101);
    SPI_Soft_Receive();
}