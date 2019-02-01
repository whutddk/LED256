#include <intrins.h> 
#include <reg52.h>

#define uchar unsigned char
  sbit load=P2^0;
sbit ldac=P2^1;
sbit  clk=P2^2;
sbit  DAT=P2^3;


void TLC5620(uchar dat)
{  
	uchar i=0,dat_=0; 
	
	clk=0;  
	load=1;  
	ldac=1;  
	_nop_();  
	_nop_();   
	for(i=0;i<3;i++)  
	{   
		clk=1;
		_nop_();
		_nop_();
          DAT=1;//0通道0增益  
		_nop_();   
		clk=0;
   _nop_();
   _nop_();
   }
	 //dat=(uchar)(date*256/5);//5V基准电压，0放大
   for(i=0;i<8;i++)
	 {   
		clk=1;
		_nop_();
		_nop_();
    dat_=dat&0x80;//从高位开始传送
		 
		if(dat_)
			DAT=1;
		else
			DAT=0;
		
		clk=0;
		_nop_();
		_nop_();
		dat<<=1;
	}
	_nop_();
	ldac=0;
	_nop_();
	load=0;
	_nop_();
	load=1;
	_nop_();
}