#include<stdio.h>
#include<graphics.h>
#include"plmtch.c"
#include"string.h"
void card(int k)
{
	setcolor(BLACK);
	bar(58+36,58+66,58*7-36,58*7-36);
		
		if(k==4||k==1||k==3)
		{
			setcolor(BLUE);
		}
		else if(k==6||k==8||k==9)
		{
			setcolor(5);
		}
		else if(k==12||k==16||k==13)
		{
			setcolor(RED);
		}
		else if(k==20||k==22||k==18)
		{
			setcolor(YELLOW);
		}
		else if(k==24||k==26||k==27)
		{
			setcolor(GREEN);
		}
		else if(k==10||k==5||k==17||k==25)
		{
			setcolor(BROWN);
		}
		else if(k==2||k==11||k==15||k==6||k==23)
		{
			setcolor(WHITE);
		}
		
	int m=0;
	places a;
	FILE *pbuf;

 	pbuf=fopen("places.bin","r+");
	// int ch=1;

	 while(fread(&a,sizeof(struct places),1,pbuf))
 	{
		//  cout<<a.pltno<<a.place<<a.color<<a.rent<<a.house1<<a.house2<<a.hotel1<<a.hotel2;
		 // cout<<"\n";
	  if(k==a.pltno)
	   break;
	 }
 	fclose(pbuf);


	char place[50];
	strcpy(place,a.place);
	while(a.place[m])
	{
		place[m]=toupper(a.place[m]);
      		m++;
   	}
	rectangle(58*3,58*1+32+3,58*5+25,58*4+83);
	line(58*3,58*1+52+3,58*5+25,58*1+52+3);
	floodfill(58*3+5,58*1+50+3,BLUE);
	char c[50][50]={"RENT     :","HOUSE 1 :","HOUSE 2 :","HOUSE 3 :","HOTEL 1 :","HOTEL 2 :","HOUSE COST :","COST:",};
	outtextxy(58*3+55,58*1+36+3,place);

	char b[50][50];
	sprintf(b[0],"%d",a.rent);
	sprintf(b[1],"%d",a.house1);
	sprintf(b[2],"%d",a.house2);
	sprintf(b[3],"%d",a.house3);
	sprintf(b[4],"%d",a.hotel1);
	sprintf(b[5],"%d",a.hotel2);
	sprintf(b[6],"%d",a.hcost);
	sprintf(b[7],"%d",a.cost);

	for(int i=1;i<9;i++)
		outtextxy(58*3+10,58*1+(i*25)+30+3,c[i-1]);
	for(int i=1;i<=8;i++)
		outtextxy(58*3+105,58*1+(i*25)+30+3,b[i-1]);


}

/*int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	card(3);
	getch();
	return 0;
}*/
