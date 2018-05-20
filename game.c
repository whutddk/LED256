sbit up=P3^0;
sbit down=P3^1;



unsigned char *bird;
unsigned char map[8][8]={0};
void move();
void loader();

uchar code stone[8]={0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
unsigned char s;

void gamer()
{
	int i=0,keep,j,m=10;
	unsigned char *light=map;
	unsigned char *p;
	
	
	unsigned char code led[64]={	0x0e,0x1e,0x2e,0x3e,0x4e,0x5e,0x6e,0x7e,0x8e,0x9e,0xae,0xbe,0xce,0xde,0xee,0xfe,
															0x0d,0x1d,0x2d,0x3d,0x4d,0x5d,0x6d,0x7d,0x8d,0x9d,0xad,0xbd,0xcd,0xdd,0xed,0xfd,
															0x0b,0x1b,0x2b,0x3b,0x4b,0x5b,0x6b,0x7b,0x8b,0x9b,0xab,0xbb,0xcb,0xdb,0xeb,0xfb,
															0x07,0x17,0x27,0x37,0x47,0x57,0x67,0x77,0x87,0x97,0xa7,0xb7,0xc7,0xd7,0xe7,0xf7};
	
	bird=&map[7][0];
	*bird=1;
	
															
	while(1)
	{
		p=p_colour;
		
		RGB(p+1,p+2,p+3);
		keep=5000;


		
		while(keep)
		{
			//light=map;			//µØÖ·´«µÝ
			
			for(j=0;j<64;j++)						
			{
				if (*(light+j))			
				P1=led[j];
				P1=led[bird-map];
			}
			keep--;
		}
		
		
		if (*(bird+1))
				break;
		move();
		p_colour++;
	}
}

void move()
{
	unsigned char i,j;
	

	for (i=0;i<8;i++)
		for(j=0;j<7;j++)
		{
			map[i][j]=map[i][j+1];
		}
	
	loader();
}



void loader()
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		map[i][7]=((stone[s])&(0x01)<<(7-i));
	}
	s++;
}

void contrl_init()
{
	up=0;
	down=0;
	P3=0XFF;
	EX0=1;
	EX1=1;
	IT0=1;
	IT1=1;
	EA=0;
}

void uper() interrupt 0
{
	if (bird!=map)
	{
		bird-=8;
	}
}

void downer() interrupt 2
{
	if (bird!=(map+56))
	{
		bird+=8;
	}
}