#include <reg52.h>
#include <intrins.h>
#include <led.h>
#include <game.c>
#include <model.c>
#include <TLC5620.c>
#include <breathled.c>
#include <peng.c>
#include <player.c>
void show(uchar scene,uchar *remain ,uchar *group_red,uchar *group_green,uchar *group_blue);
void main()
{
	  while(1)
	  {
	   	uchar p=71,q=40;
		play();
		show(p,showremain,showred,showgreen,showblue);
		show(q,showremain1,showred1,showgreen1,showblue1);
		breathled();
		gamer();
	  }
}

void show(uchar scene,uchar  *remain,uchar  *group_red,uchar  *group_green,uchar  *group_blue)
{
	int i=0,shot,keep,j;
	uchar d=0;

	uchar *red=group_red,*green=group_green,*blue=group_blue,*e;
	e=&d;
	for (shot=0;shot<scene;shot++)
	{
		keep=remain[i];
		i++;
		while(keep)
		{
			for(j=0;j<64;j++)
			{
				P1=led[j];
			
			
				RGB((red+64*shot+j),(green+64*shot+j),(blue+64*shot+j));
				 	RGB(e,e,e);	 
			}
			keep--;
		}
	}
}  
void RGB(uchar *x,uchar *y,uchar *z)
{

	
	uint ared[]={0,0,0};
	uint bgreen[]={0,1,0};
	uint dblue[]={1,1,0};
	channel(ared);
	TLC5620(*x);
	channel(bgreen);
	TLC5620(*y);
	channel(dblue);
	TLC5620(*z);
}
