#include"ma.cpp"
#include<graphics.h>
#include"board.cpp"
#include<stdio.h>
#include"dice.cpp"

int bor(int a,int i)
{

	
		board b;
		setcolor(BLACK);
		bar3d(480,0,680,400,1,1);
		
		for (int z = 0;z<a;z++)
		{
			repeat(z,count[z]);
			color(z,color(z));
			back(z,count[z]);
		}
	//	b.player("simeon",5000,1,i-0);
	//	b.player("simeon",5000,2,i-1);
		
		int j;
		//j=getch()-'0';
		j = dice();
		
		for (int z = 0;z<a; z++ )
		{
			repeat(z,count[z]);
			color(z,0);
			back(z,count[z]);
		}

		mn[i].mans(j,color(i));

		for (int z = 0;z < a ;z++)
			if(z!=i)
				if(mn[i].x1 == mn[z].x1 && mn[i].y1 == mn[z].y1 )
					count[i]++;

		for (int z = 0;z<a;z++)
		{
			repeat(z,count[z]);
			color(z,color(z));
			back(z,count[z]);
		}
	
		
		
		
	
 	return j;
	
}
