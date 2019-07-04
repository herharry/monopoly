#include<stdio.h>
#include<string.h>

struct places
{

 int pltno,cost,hcost,owner;
 char place[100];
 char color[10];
 int rent,house1,house2,house3,hotel1,hotel2;
}a,b;



void main()
{
 a.pltno=7;
 a.place="jail";
 a.color="black";
 a.owner=-2;
 a.cost=0;
 a.rent=50;
 a.hcost=0;
 a.house1=0;
 a.house2=0;
 a.house3=0;
 a.hotel1=0;
 a.hotel2=0;

 FILE *pbuf;
 
 pbuf=fopen("main.bin","r+");
// int ch=1;

 while(fread(&b,sizeof(struct places),1,pbuf))
 {
//  cout<<a.pltno<<a.place<<a.color<<a.rent<<a.house1<<a.house2<<a.hotel1<<a.hotel2;
 // cout<<"\n";
  if(7==b.pltno)
   break;
 }
 
 fseek(pbuf,-sizeof(struct places),SEEK_CUR);

 fwrite(&a,sizeof(struct places),1,pbuf);
 
 fclose(pbuf);
}
