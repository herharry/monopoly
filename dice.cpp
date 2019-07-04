#include "iostream"
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include<time.h>
#include"d.c"

int printRandoms()
{
    int lower = 1, upper = 6, count = 1,c;
	
    srand(time(0));
    
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
 c=num;
}
    
    return c;
}


using namespace std;

 
int dice()
{
	int i,a=2,b=2,g,p,o,m=0,n=0;
	int d3[12],d4[12];
	
	
	o=printRandoms();
	while(o)
	{	
		for(p=0;p<12;p++)
		{
			while((d3[p]=rand()%10))
				if(d3[p]!=0&&d3[p]<=6)
					break;
			while((d4[p]=rand()%10))
				if(d4[p]!=0&&d4[p]<=6)
					break;
		}
	
	
		a=d3[m++];
		b=d4[n++];
		if(m==12)
			m=0;
		
		if(n==12)
			n=0;
		o--;

	}
	
	if(a<1)
	{
		a=1;
	}
	if(b<1)
	{
		b=1;
	}
	if(a>6)
	{
		a=6;
	}
	if(b>6)
	{
		b=6;
	}
	g=a+b;
	
	roll(125,150,a,b);
	
	return g;
}
/*int main()
{
	int a;
	
	a=dice();

	cout<<a;

	return 0;
}*/


