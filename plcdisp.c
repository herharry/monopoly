#include<stdio.h>
struct places
{

 int pltno,cost,hcost,owner;
 char place[100];
 char color[10];
 int rent,house1,house2,house3,hotel1,hotel2;
}a;



int main()
{

 FILE *pbuf;
 
 pbuf=fopen("places.bin","r");
// int ch=1;

 while(fread(&a,sizeof(struct places),1,pbuf))
 {
  printf(" %d\n %s\n %s\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n",a.pltno,a.place,a.color,a.owner,a.cost,a.rent,a.hcost,a.house1,a.house2,a.house3,a.hotel1,a.hotel2);
 }
 fclose(pbuf);
 return 0;
}
