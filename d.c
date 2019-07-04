#include<graphics.h>
#include<stdio.h>
void dcircle(int x,int y)
{
	setcolor(BLACK);
	circle(x,y,3);
	floodfill(x,y,BLACK);
}
void fd(int x,int y,int v)
{
	if(v==1)
		dcircle(x+25,y+25);
	else if(v==2)
	{
		dcircle(x+40,y+10);
		dcircle(x+10,y+40);
	}
	else if(v==3)
	{
		dcircle(x+40,y+10);
		dcircle(x+10,y+40);
		dcircle(x+25,y+25);
	}
	else if (v==4)
	{
		dcircle(x+40,y+10);
		dcircle(x+10,y+40);
		dcircle(x+10,y+10);
		dcircle(x+40,y+40);

	}
	else if(v==5)
	{
		dcircle(x+25,y+25);
		dcircle(x+40,y+10);
		dcircle(x+10,y+40);
		dcircle(x+10,y+10);
		dcircle(x+40,y+40);

	}
	else if(v==6)
	{
		dcircle(x+10,y+25);
		dcircle(x+40,y+10);
		dcircle(x+10,y+40);
		dcircle(x+10,y+10);
		dcircle(x+40,y+40);
		dcircle(x+40,y+25);
	}
}


void td(int x,int y,int v)
{

	if(v==1)
	{
		dcircle(x+35,y-10);
	}
	else if(v==2)
	{
		dcircle(x+8,y-3);
		dcircle(x+65,y-17);


	}
	else if(v==3)
	{
		dcircle(x+8,y-3);
		dcircle(x+65,y-17);
		dcircle(x+35,y-10);
	}
	else if(v==4)
	{
		dcircle(x+8,y-3);
		dcircle(x+65,y-17);
		dcircle(x+32,y-17);
		dcircle(x+47,y-5);
	}
	else if(v==5)
	{
		dcircle(x+8,y-3);
		dcircle(x+65,y-17);
		dcircle(x+32,y-17);
		dcircle(x+47,y-5);
		dcircle(x+38,y-10);

	}
	else if(v==6)
	{
		dcircle(x+8,y-3);
		dcircle(x+65,y-17);
		dcircle(x+32,y-17);
		dcircle(x+47,y-5);
		dcircle(x+56,y-12);
		dcircle(x+20,y-10);


	}
}

void rd(int x,int y ,int v)
{
		if(v==1)
		{
				dcircle(x+65,y+17);
		}
		else if(v==2)
		{
			dcircle(x+55,y+3);
			dcircle(x+72,y+27);
		}else if(v==3)
		{
			dcircle(x+63,y+15);
			dcircle(x+55,y+3);
			dcircle(x+72,y+27);
		}
		else if(v==4)
		{
				dcircle(x+55,y+3);
				dcircle(x+72,y+27);
				dcircle(x+53,y+44);
				dcircle(x+71,y-12);
		}
		else if(v==5)
		{
			dcircle(x+63,y+15);
			dcircle(x+55,y+03);
			dcircle(x+72,y+27);
			dcircle(x+53,y+44);
			dcircle(x+71,y-12);

		}
		else if(v==6)
		{
			dcircle(x+55,y+3);
			dcircle(x+72,y+27);
			dcircle(x+53,y+44);
			dcircle(x+71,y-12);
			dcircle(x+55,y+20);
			dcircle(x+72,y+10);

		}
}
void roll(int x,int y,int a,int b)
{
	getch();
	int i,j=3,p1[20]={x+50,y+50,x+75,y+30,x+75,y-20,x+50,y,x,y,x+30,y-20,x+75,y-20}, p2[20]={x+50,y+50,x+75,y+30,x+75,y-20,x+51,y,x+51,y+50};
	int x1=x+155;
	int p3[20]={x1+50,y+50,x1+75,y+30,x1+75,y-20,x1+50,y,x1,y,x1+30,y-20,x1+75,y-20}, p4[20]={x1+50,y+50,x1+75,y+30,x1+75,y-20,x1+51,y,x1+51,y+50};
	while(j>0)
	{
	for(i=1;i<=6;i++)
	{

		setcolor(BLACK);
		bar3d(x,y,x+100,y+100,1,1);
		setcolor(i+2);
		bar(x,y,x+50,y+50);

		setcolor(i+3);


		drawpoly(7,p1);
		floodfill(x+20,y-5,i+3);
		setcolor(i+4);

		drawpoly(5,p2);
		floodfill(x+70,y+25,i+4);
		if(i<4)
		{
			fd(x,y,i);
			td(x,y,i+1);
			rd(x,y,i+2);
		}
		else
		{
			fd(x,y,i);
			td(x,y,i-1);
			rd(x,y,i-2);
		}
		x=x+155;

		setcolor(BLACK);
		bar3d(x,y,x+70,y+7,1,1);
 		setcolor(i+2);
		bar(x,y,x+50,y+50);
		setcolor(i+3);


		drawpoly(7,p3);
		floodfill(x+20,y-5,i+3);
		setcolor(i+4);

		drawpoly(5,p4);
		floodfill(x+70,y+25,i+4);

		if(i<4)
		{
			fd(x,y,i);
			td(x,y,i+2);
			rd(x,y,i+3);
		}
		else
		{
			fd(x,y,i);
			td(x,y,i-2);
			rd(x,y,i-3);
		}
		x=x-155;
		delay(200);
	}

	j--;
	}
	setcolor(BLACK);
	bar3d(x,y,x+100,y+100,1,1);
	setcolor(a+2);
	bar(x,y,x+50,y+50);
	setcolor(a+3);
	drawpoly(7,p1);
	floodfill(x+20,y-5,a+3);
	setcolor(a+4);
	drawpoly(5,p2);
	floodfill(x+70,y+25,a+4);

	fd(x,y,a);
	if (a>1&&a<6 )
	{
		td(x,y,a+1);
		rd(x,y,a-1);
	}
	else if(a==1)
	{
		td(x,y,a+3);
		rd(x,y,a+5);
	}
	else if(a==6)
	{
		td(x,y,a-3);
		rd(x,y,a-5);
	}
	x=x+155;

	setcolor(BLACK);
	bar3d(x,y,x+100,y+100,1,1);
	setcolor(b+2);
	bar(x,y,x+50,y+50);
	setcolor(b+3);
	drawpoly(7,p3);
	floodfill(x+20,y-5,b+3);
	setcolor(b+4);
	drawpoly(5,p4);
	floodfill(x+70,y+25,b+4);
	fd(x,y,b);
	if (b>1&&b<6 )
	{
		td(x,y,b+1);
		rd(x,y,b-1);
	}
	else if(b==1)
	{
		td(x,y,b+3);
		rd(x,y,b+5);
	}
	else if(b==6)
	{
		td(x,y,b-3);
		rd(x,y,b-5);
	}

}
/*
int main()
{int gd=DETECT,gm,i=0;
initgraph(&gd,&gm,NULL);

	roll(200,200,3,4);
	return 0;

}*/
