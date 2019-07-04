#include "iostream"
#include<stdio.h>
#include<string.h>
#include "comb.c"
#include "card.c"

using namespace std;

int pid=0;

class player :public places
{
 char places[24][50];
 char color[24][10];
 int balance,pcount;
 int hotel[24],house[24];

 public:
  int platform;
  void addplace();
  void addhome();
  player();
  void trade(int,int);
  void tradk(int,int,int);
  int trades(int*,int);
  void change(int,int);

}pl[10];

void player :: change(int i,int pla)
{
	for(int k=i;k<pl[pla].pcount;k++)
	{
		strcpy(pl[pla].places[k],pl[pla].places[k+1]);
		strcpy(pl[pla].color[k],pl[pla].color[k+1]);
	}
	
	pl[pla].pcount--;
}

int player :: trades( int *k,int n)
{
	int pc=0,j;
	for(int i=0;i<pl[n].pcount;i++)
	{
		int ptn;
		ptn=lmatch(pl[n].places[i]);
		cout<<ptn<<"."<<pl[n].places[i]<<"\n";

	}
	cout<<pl[n].balance<<"\n";
	
	while(1)
	{	
		cin>>pc;
		if(pc == 0)
			break;
		*k=pc;
		cout<<*k;
		k++;	
	}
	cout<<"want money press 1";
	cin>>j;
	if (j==1)
	{
		cout<<"Enter amount";
		cin>>j;
		j*=1;
	}
	else
		cin>>j;

	return j;
}

void player :: tradk(int i,int n,int pid)
{
	if(i !=0 )
	{	
		int l=0;
		pmatch(i);
		while(1)
		{	
			if(strcmp(a.place,pl[n].places[l]) == 0)
				break;
			
			l++;
		}
		change(l,n);
		a.owner=pid;
		strcpy(pl[pid].places[pl[pid].pcount],a.place);
      	        strcpy(pl[pid].color[pl[pid].pcount++],a.color);
		filupd(i);
	}
}

void player :: trade(int pid,int as)
{
	int n,op[10]={0,0,0,0,0,0,0,0,0,0},mp[10]={0,0,0,0,0,0,0,0,0,0},oa=0,ma=0,y;
	cout<<"enter player no";
	cin>>n;
	if(n<as&&n!=pid)
	{
		
		oa=trades(&op[0],n);	
		ma=trades(&mp[0],pid);
		for(int s =0;s<10;s++){cout<<op[s]<<"\t"<<mp[s];}

		cout<<"\n"<<oa<<"\t"<<ma;
		cin>>y;
		
		if(y == 1)
		{
			if(oa !=0)
				if(oa<0)
				{
					pl[pid].balance-=oa;
					pl[n].balance+=oa;
				}
				else
				{
					pl[pid].balance+=oa;
					pl[n].balance-=oa;
				}
			
			if(ma !=0)
				if(ma>0)
				{
					pl[pid].balance-=ma;
					pl[n].balance+=ma;
				}
				else
				{
					pl[pid].balance+=ma;
					pl[n].balance-=ma;
				}

			for(int i=0;i<10;i++)
			{
				tradk(op[i],n,pid);
				tradk(mp[i],pid,n);
				
			}
		}		

	}
}
player ::  player()
{
   for(int i=0;i<24;i++)
   {
    hotel[i]=house[i]=0;
   }
   pcount=0;
   platform=0;
balance=1500;
}

void player :: addhome()
{
 int count=0,pos[2],flag=0, i;

 for(i=0;i<pcount;i++)
 {
  for(int j=i+1;j<pcount;j++)
  {
   if(color[j]==color[i])
   {
    pos[count]=j;
    count++;
   }
  }
  if(count==2)
  {
   cout<<color[i];
   cout<<places[i];
   cout<<places[pos[0]];
   cout<<places[pos[1]];
   flag=1;
  }
  count=0;
 }
 if(!flag)
  return;
 char plce[100],type[100];
 printf("enter place");
 cin>>plce;
 cout<<"enter hotel or house";
 cin>>type;

 if(places[i]==plce && type=="house")
  house[i]++;
 else if(places[pos[0]]==plce && type=="house")
  house[pos[0]]++;
 else if(places[pos[1]]==plce && type=="house")
  house[pos[1]]++;
 else if(places[i]==plce && type=="hotel" && house[i]==3)
 {
  hotel[i]++;
  house[i]=0;
 }
 else if(places[pos[0]]==plce && type=="hotel" && house[pos[0]]==3)
 {
  hotel[pos[0]]++;
  house[pos[0]]=0;
 }
 else if(places[pos[1]]==plce && type=="hotel" && house[pos[1]]==3)
 {
  hotel[pos[1]]++;
  house[pos[1]]=0;
 }
 else
  printf("error 404");

}

void whites()
{
	char s[20] = "cannot be bought";
	outtextxy(58*4+3,58*4+83,s);

}

void player :: addplace()
{
	
	char c[5][30] = {"someone else is owning it","place is owned by you","To buy press enter","place cannot be bought","Purchase sucessfull"};
	pmatch(platform);
		
	printf("%d\n",a.owner);

	 if(a.owner==-2)
	   whites();

	 else if(a.owner!=-1 && a.owner!=pid)
	 {
   		  outtextxy(58*4+3,58*4+83,c[0]);
		  pl[pid].balance-=a.rent;
		  pl[owner].balance+=a.rent;
	 }
	 else if(a.owner==pid)
		outtextxy(58*1+3,58*4+83,c[1]);


	 else if(a.owner==-1)
	 {
		
		outtextxy(58*2,58*4+83,c[2]);
		  char ch;
		  
		  ch=getch();

		  if(ch=='y')
		  {
			   if(pl[pid].balance<a.cost)
				outtextxy(58*1+3,58*4+83,c[3]);
			    	
			   else
			   {
				setcolor(BLACK);
					bar(58*1+3,58*4+83,58*7-5,58*4+90);
								setcolor(WHITE);
				outtextxy(58*1+3,58*4+83,c[4]);
				    strcpy(pl[pid].places[pcount],a.place);
				    strcpy(pl[pid].color[pcount],a.color);
				    pl[pid].balance-=a.cost;
				    a.owner=pid;
				    cout<<a.owner;
				    filupd(platform);
			     	    pcount++;
			   }
			   //addhome();
		  }

	 }

}

int main()
{

 int n;
 cout<<"enter the no. of players";
 cin>>n;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);

 while(1)
 {
  int roll=  bor(n,pid);

  pl[pid].platform+=roll;
  card(pl[pid].platform);
  pl[pid].addplace();
  getch();
  char choice;
  while(1)
  {
    cin>>choice;
    if( choice == 'n')
      break;
    pl[pid].trade(pid,n);
  } 
  pid++;
  if( pl[pid].platform > 24 )
  {
 	pl[pid].platform-=24;
  }
	
  if(pid==n)
   pid=0;
  
 }
 return 0;
}
