
void breathled()
{
	int i,keep,j,k=100,m=10;
	
	uchar a,b=0,c=0,d=0;
	uchar *red,*green,*blue,*e;
	red=&a;
	green=&b;
	blue=&c;
	e=&d;
	while(m)
	{
		a=110;keep=64;
		while(keep)
		{
			j=1;
			while(j)
			{
				for(i=0;i<64;i++)
				{
					RGB(e,e,e);
					P1=led[i];
					RGB(red,green,blue);
					
				}
				j--;
			};
				a++;
				if(a>174)
				a=110;
				RGB(e,e,e);
		
			keep--;
		 };
		 a=174;keep=64;
		while(keep)
		{
			j=1;
			while(j)
			{
				for(i=0;i<64;i++)
				{
					RGB(e,e,e);
					P1=led[i];
					RGB(red,green,blue);
					
				}
				j--;
			};
				a--;
				if(a<110)
				a=174;
				RGB(e,e,e);
			keep--;
		 };
		 m--;
	 };
}