﻿#include <micpic.c>
#define M 192


long pulse;//节拍长度目标
int tone;//音调目标


/****{190,170,152,143,127,114,101},{96,85,76,72,64,57,50},{48,42,37,35,31,28,25}****/

int code music[M]={	37,					42,																				48,					50,																					57,					 64,										57,					50,//8
					48,					50,																				57,					64,																					72,					 76,										72,					85,//8
					48,50,48,96,101,64,85,76,															96,48,50,57,50,37,31,28,																35,37, 42,35,35,37,48,50,						57,64,72,76,85,72,76,85,//32
					96,85,76,72,64,	85,64,72,															76,57,64,72,64,72,76,85,																96,114,57,50,48,50,57,64,						72,76,85,57,64,57,64,72,//32
					/*76,		37,		42,																				48,					42,																					48,		 42,	 42,	 35,//9*/
					31,37,35,	31,37,35,	31,64,57,50,	48,42,37,35,				37,48,42,	37,76,72,	64,57,64,72,	64,76,72,64,					72,57,64,	72,76,85,	76,85,96,85,		76,72,64,57,//42
					72,57,64,	57,50,48,	64,57,50,48,	42,37,35,31,				37,48,42,	37,42,48,	42,50,48,42,	37,42,48,50,					48,57,50,	48,96,85,	76,72,76,85,		76,48,50,48,//42
					57,48,50,	57,64,72,	64,72,76,72,	64,57,50,48,				57,48,50,	48,50,57,	50,48,42,48,	50,48,57,50};//28						/*37,76,72,85,	85,42,37,42,														48,76,96,57,	64,127,143,127,														114,57,50,57,		50,127,143,127,			114,57,64,57,	50,50,57,50}//32*/

	
	
	
	
	
	
long code pu[M]=	{	80000,80000,														80000,80000,																			80000,80000,																					80000,80000,								
						80000,80000,														80000,80000,																			80000,80000,																					80000,80000,								
			20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,
			20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,
			/*40000,40000,				80000,														80000,80000,																			40000,40000,40000,40000,*/
			20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000,				20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000,				20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000,
			20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000,				20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000,				20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000,
			20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000,				20000,10000,10000,	20000,10000,10000,	10000,10000,10000,10000,	10000,10000,10000,10000};
			/*20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,		20000,20000,20000,20000,20000,20000,20000,20000,*/

unsigned char color_r[M]={1};
unsigned char color_g[M]={1};
unsigned char color_b[M]={1};
	
	
	
	 long time_pulse=0;//节拍计数
int time_tone=0;//音调计数
	long *p=pu;
int *m=music;

char cls=1;
char *d=&cls;

sbit voice=P3^4;

/*void show_play()
{
	int i=0,j;
	int keep;
	unsigned char group_red,group_green,group_blue;				
	unsigned char *red=&group_red,*green=&group_green,*blue=&group_blue;
	{
		group_red=254;
		group_green=254;
		group_blue=150;
		keep=500;		
		RGB(red,green,blue);
		while(keep)
		{
			for(j=0;j<64;j++)						//问题函数
			{
																															
				P1=led[j];
			
																															
				
				//RGB(d,d,d);	 
				
								
			}
			keep--;
		}
		P1=0XFF;
	}	 
}*/  


	
	
void timerInit()		//1微秒24.000MHz
{
	
	
	TMOD &= 0xF0;		//???????
	TMOD |= 0x02;		//???????
	TL0 = 0xfe;		//??????
	TH0 = 0xfe;		//???????
	TF0 = 0;		//??TF0??
	TR0 = 1;		//???0????//自动装填
	
	ET0=1;
	EA=1;
	
}

void control()
{
	unsigned char j=0;
			for(j=0;j<30;j++)						//问题函数
			{
				RGB(d,d,d);	 
			}
			
}  


//*******************以400毫秒为一拍///////
void player_0() interrupt 1
{
	
	time_tone++;
	time_pulse++;
	if (time_pulse==pulse)//节拍，换音控制
	{
		time_pulse=0;//节拍计数清零
		time_tone=0;
		pulse=*(++p);//节拍目标后移
		tone=*(++m);//音调目标后移
		EA=0;//show_play();
			
		micpic();
		
		EA=1;
	}
	if(time_tone==tone)//到达频率控制时间
	{
		voice=~voice;
		time_tone=0;
	}
}

void play()
{
	timerInit();
	pulse=*(p);
	tone=*m;
	voice=0;
	control();

}