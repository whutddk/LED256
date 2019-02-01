void micpic()
{
	int n=192;//n代表帧数
	int i,j;
	int keep=10;

	int cc[1][64]={0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,};//决定灯亮不亮
	uchar a=130,b=140,c=150,d=0;
	uchar *red,*green,*blue,*e;
	red=&a;
	green=&b;
	blue=&c;
	e=&d;
	i++;
		RGB(red,green,blue);
		while(keep)
		{
			for(j=0;j<64;j++)
			{
				if(cc[1][j]==1)
				P1=led[j];
				P1=0XFF;
			}
			keep--;
		};
		a++;b++;c++;
		if(a>240) a=130;
		if(b>240) b=140;
		if(c>240) c=150;
}
		
