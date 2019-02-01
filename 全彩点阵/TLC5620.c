sbit load=P2^0;
sbit ldac=P2^1;
sbit  clk=P2^2;
sbit  DAT=P2^3;

void TLC5620();

void channel(uint *a)
{
	int i;
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
          DAT=*(a+i); 
		_nop_();   
		clk=0;
   _nop_();
   _nop_();
   }
}


void TLC5620(uchar m)
{  
	unsigned char i=0,dat_=0,dat; 
	 dat=m;
   for(i=0;i<8;i++)
	 {   
		clk=1;
		_nop_();
		_nop_();
    dat_=dat&0x80;
		 
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