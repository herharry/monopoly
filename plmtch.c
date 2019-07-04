#include<stdio.h>
struct places
{

 int pltno,cost,hcost,owner;
 char place[100];
 char color[10];
 int rent,house1,house2,house3,hotel1,hotel2;
}a,b;


int lmatch(char place[100])
{
	FILE *pbuf;
 
 	pbuf=fopen("places.bin","r+");
// int ch=1;

 while(fread(&a,sizeof(struct places),1,pbuf))
 {
//  cout<<a.pltno<<a.place<<a.color<<a.rent<<a.house1<<a.house2<<a.hotel1<<a.hotel2;
 // cout<<"\n";
  if(strcmp(place,a.place) == 0)
   break;
 }
 fclose(pbuf);

	return a.pltno;
}


void pmatch(int no)
{

 FILE *pbuf;
 
 pbuf=fopen("places.bin","r+");
// int ch=1;

 while(fread(&a,sizeof(struct places),1,pbuf))
 {
//  cout<<a.pltno<<a.place<<a.color<<a.rent<<a.house1<<a.house2<<a.hotel1<<a.hotel2;
 // cout<<"\n";
  if(no==a.pltno)
   break;
 }
 fclose(pbuf);

}



void filupd(int no)
{

 FILE *pbuf;
 
 pbuf=fopen("places.bin","r+");
// int ch=1;

 while(fread(&b,sizeof(struct places),1,pbuf))
 {
//  cout<<a.pltno<<a.place<<a.color<<a.rent<<a.house1<<a.house2<<a.hotel1<<a.hotel2;
 // cout<<"\n";
  if(no==b.pltno)
   break;
 }
 
 fseek(pbuf,-sizeof(struct places),SEEK_CUR);

 fwrite(&a,sizeof(struct places),1,pbuf);
 
 fclose(pbuf);
}
