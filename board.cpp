#include<graphics.h>
#include<stdio.h>

#include<stdlib.h>

char p[24][10]={"MARINA","UBER","ECR","OMR","I.TAX","PARRYS","LICET","SRM","CHANCE","METRO","NH4","BESSY","CHEST","  AU","BUS","KASI","CHANCE","PVR","AGS","CHEST","ALSA","OLA","EA","FORUM"};
int k=0;

class board
{
public:
	
	void player(char a[],int b,int c,int k)
	{
		
		setcolor(WHITE);
		outtextxy(500,20*c,a);
		char d[100];
		sprintf(d,"%d",b);
		outtextxy(600,20*c,d);
		if(k==0)
		{
			setcolor(c+1);
			rectangle(480,20*c,490,(20*c)+10);
			floodfill(485,(20*c)+5,k+3);
		}
		else 
		{
			setcolor(BLACK);
			rectangle(480,20*c,490,(20*c)+10);
			floodfill(485,(20*c)+5,BLACK);
		}
	}



	void dbox(int x,int y)
	{
		if(k==5||k==2||k==3)
		{
			setcolor(BLUE);
		}
		else if(k==0||k==10||k==11)
		{
			setcolor(5);
		}
		else if(k==6||k==7||k==13)
		{
			setcolor(RED);
		}
		else if(k==15||k==17||k==18)
		{
			setcolor(YELLOW);
		}
		else if(k==20||k==22||k==23)
		{
			setcolor(GREEN);
		}
		else if(k==1||k==9||k==14||k==21)
		{
			setcolor(BROWN);
		}
		else if(k==4||k==8||k==12||k==16||k==19)
		{
			setcolor(WHITE);
		}

		rectangle(x,y,x+58,y+58);
		line(x,y+5,x+58,y+5);
		outtextxy(x+1,y+25,p[k++]);
		floodfill(x+1,y+2,RED);

	}
	void ubox(int x,int y)
	{
		if(k==5||k==2||k==3)
		{
			setcolor(BLUE);
		}
		else if(k==0||k==10||k==11)
		{
			setcolor(5);
		}
		else if(k==6||k==7||k==13)
		{
			setcolor(RED);
		}
		else if(k==15||k==17||k==18)
		{
			setcolor(YELLOW);
		}
		else if(k==20||k==22||k==23)
		{
			setcolor(GREEN);
		}
		else if(k==1||k==9||k==14||k==21)
		{
			setcolor(BROWN);
		}
		else if(k==4||k==8||k==12||k==16||k==19)
		{
			setcolor(WHITE);
		}

		rectangle(x,y,x+58,y+58);
		line(x,y+53,x+58,y+53);
		outtextxy(x+5,y+25,p[k++]);
		floodfill(x+5,y+55,RED);


	}

	void lbox(int x,int y)
	{
		if(k==5||k==2||k==3)
		{
			setcolor(BLUE);
		}
		else if(k==0||k==10||k==11)
		{
			setcolor(5);
		}
		else if(k==6||k==7||k==13)
		{
			setcolor(RED);
		}
		else if(k==15||k==17||k==18)
		{
			setcolor(YELLOW);
		}
		else if(k==20||k==22||k==23)
		{
			setcolor(GREEN);
		}
		else if(k==1||k==9||k==14||k==21)
		{
			setcolor(BROWN);
		}
		else if(k==4||k==8||k==12||k==6||k==19)
		{
			setcolor(WHITE);
		}

		rectangle(x,y,x+58,y+58);
		line(x+53,y,x+53,y+58);
		outtextxy(x,y+25,p[k++]);
		floodfill(x+55,y+55,RED);


}

	void rbox(int x,int y)
	{
		if(k==5||k==2||k==3)
		{
			setcolor(BLUE);
		}
		else if(k==0||k==10||k==11)
		{
			setcolor(5);
		}
		else if(k==6||k==7||k==13)
		{
			setcolor(RED);
		}
		else if(k==15||k==17||k==18)
		{
			setcolor(YELLOW);
		}
		else if(k==20||k==22||k==23)
		{
			setcolor(GREEN);
		}
		else if(k==1||k==9||k==14||k==21)
		{
			setcolor(BROWN);
		}
		else if(k==4||k==8||k==12||k==6||k==19)
		{
			setcolor(WHITE);
		}

		rectangle(x,y,x+58,y+58);
		line(x+5,y+58,x+5,y);
		outtextxy(x+9,y+25,p[k++]);
		floodfill(x+4,y+55,RED);


	}
int roll()
{
	int i,a,b,g,p,m=0,n=0;
	int d3[12],d4[12];
	while(getch()!=32)
	{
		for(p=0;p<12;p++)
			while((d3[p]=rand()%10)>6);
		
		for(p=0;p<12;p++)
			while((d4[p]=rand()%10)>6);

		m++;
		n++;
		if(m>11)
			m=0;
		
		if(n>11)
			n=0;
	}
	a=d3[m];
	b=d4[n];
	g=a+b;
	int d1[10]={1,5,2,6,4,3},d2[10]={6,3,1,2,5,4};
	char c[5];
	m=0;
	n=5;
	for(i=0;i<30;i++)
	{	
		setcolor(BLACK);
		bar3d(58*3+29,230,58*4+38,260,1,1);
		sprintf(c,"%d",d1[m]);
		setcolor(WHITE);
		outtextxy(58*3+29,230,c);
		sprintf(c,"%d",d2[n]);
		outtextxy(58*4+29,230,c);
		if(i<15)
		{
			delay(50);
		}
		else if(i<28)
		{
			delay(200);
		}
		else
		{
			delay(500);
		}
		m++;
		n--;	

		if(m==6)
			m=0;
		if(n==-1)
			n=5;
			
	}

		
		setcolor(BLACK);
		bar3d(58*3+29,230,58*4+38,260,1,1);
		sprintf(c,"%d",a);
		setcolor(WHITE);
		outtextxy(58*3+29,230,c);
		sprintf(c,"%d",b);
		outtextxy(58*4+29,230,c);

	return g;
	
}
	board()
	{
		cleardevice();
		setcolor(RED);
		rectangle(0,0,464,464);



		for(int k=58;k<7*58;)
		{

			dbox(k,464-58);
			k=k+58;
		}

		for(int k=58;k<7*58;)
		{

			lbox(0,k);
			k=k+58;
		}


		for(int k=58;k<7*58;)
		{

			ubox(k,0);
			k=k+58;
		}

		for(int k=58;k<7*58;)
		{

			rbox(464-58,k);
			k=k+58;
		}

		char c[5][10]={"Jail","start","parking","go to","jail"};
		outtextxy(5,424,c[0]);
		outtextxy(464-53,424,c[1]);
		outtextxy(5,15,c[2]);
		outtextxy(464-53,15,c[3]);
		outtextxy(464-53,23,c[4]);

	}

};
