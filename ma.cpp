#include<graphics.h>
#include<stdio.h>
void delay(){
	for(int i = 0 ; i<1000; i++)
		for(int j = 0 ; j<1000 ; j++ )
			for(int  k = 0 ; k<200;k++)
			{}
}

class man{
	public:
		int x1,y1;
		int flag ,pos;
		man(){
			x1=435;
			y1=435;
			flag = 0;
			pos = 0;
		}
		void bman1(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x,y+6,x,y+20);
			line(x,y+7,x-4,y+15);
			line(x,y+7,x+4,y+15);
			y=y+13;
			line(x,y+7,x-5,y+15);
			line(x,y+7,x+5,y+15);
		}
		void bman2(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x,y+6,x,y+20);
			line(x,y+7,x-5,y+15);
			line(x,y+7,x+5,y+15);
			y=y+13;
			line(x,y+7,x-3,y+15);
			line(x,y+7,x+3,y+15);
		}
		void bman(int z){
			bman1(x1,y1,z);
			delay();
			bman1(x1,y1,0);
			x1=x1-29;
			bman2(x1+1,y1,z);
			delay();
			bman2(x1+1,y1,0);
			x1=x1-29;
		}
		void lman1(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x-6,y,x-20,y);
			line(x-7,y,x-15,y+4);
			line(x-7,y,x-15,y-4);
			x=x-13;
			line(x-7,y,x-15,y+5);
			line(x-7,y,x-15,y-5);
		}
		void lman2(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x-6,y,x-20,y);
			line(x-7,y,x-15,y+5);
			line(x-7,y,x-15,y-5);
			x=x-13;
			line(x-7,y,x-15,y+3);
			line(x-7,y,x-15,y-3);
		}
		void lman(int z){
				lman1(x1,y1,z);
				delay();
				lman1(x1,y1,0);
				y1=y1-29;
				lman2(x1,y1+1,z);
				delay();
				lman2(x1,y1+1,0);
				y1=y1-29;
			}
		void uman1(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x,y-6,x,y-20);
			line(x,y-7,x+4,y-15);
			line(x,y-7,x-4,y-15);
			y=y-13;
			line(x,y-7,x+5,y-15);
			line(x,y-7,x-5,y-15);
		}
		void uman2(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x,y-6,x,y-20);
			line(x,y-7,x+5,y-15);
			line(x,y-7,x-5,y-15);
			y=y-13;
			line(x,y-7,x+3,y-15);
			line(x,y-7,x-3,y-15);
		}
		void uman(int z){
			uman1(x1,y1,z);
			delay();
			uman1(x1,y1,0);
			x1=x1+29;
			uman2(x1+1,y1,z);
			delay();
			uman2(x1+1,y1,0);
			x1=x1+29;
			}
		void rman1(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x+6,y,x+20,y);
			line(x+7,y,x+15,y-4);
			line(x+7,y,x+15,y+4);
			x=x+13;
			line(x+7,y,x+15,y-5);
			line(x+7,y,x+15,y+5);
		}
		void rman2(int x,int y,int z){
			setcolor(z);
			circle(x,y,6);
			line(x+6,y,x+20,y);
			line(x+7,y,x+15,y-5);
			line(x+7,y,x+15,y+5);
			x=x+13;
			line(x+7,y,x+15,y-3);
			line(x+7,y,x+15,y+3);
		}
		void rman(int z){
			rman1(x1,y1,z);
			delay();
			rman1(x1,y1,0);
			y1=y1+29;
			rman2(x1,y1+1,z);
			delay();
			rman2(x1,y1+1,0);
			y1=y1+29;
		}
		void mans(int x,int c){
			if(flag == 0){
				x1=377;
				y1=377;
				flag = 8 ;
			}
			while(x--){
				if(y1 == 377 && x1 != 87 && flag != 7 ){
						rman1(435,435,0);
						if(flag == 8){
								x1=377;
								y1=377;
								bman1(x1,y1,c);
								flag = 1;
								pos = 1;
						}
						else{
							bman1(x1,y1,0);
							bman(c);
							bman1(x1,y1,c);
							pos = 2;
						}
				}
				else if(y1 == 377 && x1 == 87 && flag == 1){
						delay();
						bman1(x1,y1,0);
					  bman1(29,435,c);
						flag = 2;
						delay();
						pos = 4;
				}
				else if(x1 == 87 && y1 != 87){
						bman1(29,435,0);
						if(flag == 2){
							lman1(87,377,c);
							flag = 3;
							pos = 5;
						}
						else{
							lman1(87,377,0);
							lman(c);
							lman1(x1,y1,c);
							pos = 6;
						}
				}
				else if(x1 == 87 && y1 == 87 && flag == 3){
						delay();
					  lman1(29,29,c);
						lman1(x1,y1,0);
						flag = 4;
						delay();
						pos =7;
				}
				else if(y1 == 87 && x1 != 377){
						lman1(29,29,0);
						if(flag == 4){
							uman1(87,87,c);
							flag = 5;
							pos =8;
						}
						else{
							uman1(87,87,0);
							uman(c);
							uman1(x1,y1,c);
							pos =9;
						}
				}
				else if(y1 == 87 && x1 == 377 && flag == 5){
						delay();
						uman1(x1,y1,0);
					  uman1(435,29,c);
						flag = 6;
						delay();
						pos =10;
				}
				else if(x1 == 377 && y1 != 377){
						uman1(435,29,0);
						if(flag == 6){
							rman1(377,87,c);
							flag = 7;
							pos = 11;
						}
						else{
							rman1(377,87,0);
							rman(c);
							rman1(x1,y1,c);
							pos = 12;
						}
				}
				else if(x1 == 377){
						delay();
					  rman1(435,435,c);
						rman1(x1,y1,0);
						flag = 8;
						delay();
						pos = 13;
				}
			}
		}
};
int color(int i)
{
	switch (i) {
		case 1:
			return 2;
		case 2:
			return 3;
		case 3:
			return 4;
		case 4:
			return 5;
		case 5:
			return 6;
		case 6:
			return 7;
	}
}
man mn[5];
static int count[6]={0,0,0,0,0,0};
void color(int j , int c)
{
	switch(mn[j].pos)
	{
		case 0:
			mn[j].bman1(mn[j].x1,mn[j].y1,c);
			break;
		case 1:
				mn[j].bman1(mn[j].x1,mn[j].y1,c);
				break;
		case 2:
				mn[j].bman1(mn[j].x1,mn[j].y1,c);
				break;
		case 4:
				mn[j].bman1(29,435,c);
				break;
		case 5:
				mn[j].lman1(87,377,c);
				break;
		case 6:
				mn[j].lman1(mn[j].x1,mn[j].y1,c);
				break;
		case 7:
				mn[j].lman1(29,29,c);
				break;
		case 8:
				mn[j].uman1(87,87,c);
				break;
		case 9:
				mn[j].uman1(mn[j].x1,mn[j].y1,c);
				break;
		case 10:
				mn[j].uman1(435,29,c);
				break;
		case 11:
				mn[j].rman1(377,87,c);
				break;
		case 12:
				mn[j].rman1(mn[j].x1,mn[j].y1,c);
				break;
		case 13:
				mn[j].rman1(435,435,c);
				break;
	}
}
void repeat(int j , int c)
{
	switch(mn[j].pos)
	{
		case 0:
			mn[j].x1-=c*5;
			break;
		case 1:
				mn[j].x1-=c*5;
				break;
		case 2:
				mn[j].x1-=c*5;
				break;
		case 4:
				mn[j].x1-=c*5;
				break;
		case 5:
				mn[j].y1-=c*5;
				break;
		case 6:
				mn[j].y1-=c*5;
				break;
		case 7:
				mn[j].y1-=c*5;
				break;
		case 8:
				mn[j].x1+=c*5;
				break;
		case 9:
				mn[j].x1+=c*5;
				break;
		case 10:
				mn[j].x1+=c*5;
				break;
		case 11:
				mn[j].y1+=c*5;
				break;
		case 12:
				mn[j].y1+=c*5;
				break;
		case 13:
				mn[j].y1+=c*5;
				break;
	}
}
void back(int j , int c)
{
	switch(mn[j].pos)
	{
		case 0:
			mn[j].x1-=c*5;
			break;
		case 1:
				mn[j].x1+=c*5;
				break;
		case 2:
				mn[j].x1+=c*5;
				break;
		case 4:
				mn[j].x1+=c*5;
				break;
		case 5:
				mn[j].y1+=c*5;
				break;
		case 6:
				mn[j].y1+=c*5;
				break;
		case 7:
				mn[j].y1+=c*5;
				break;
		case 8:
				mn[j].x1-=c*5;
				break;
		case 9:
				mn[j].x1-=c*5;
				break;
		case 10:
				mn[j].x1-=c*5;
				break;
		case 11:
				mn[j].y1-=c*5;
				break;
		case 12:
				mn[j].y1-=c*5;
				break;
		case 13:
				mn[j].y1-=c*5;
				break;
	}
}
/*
int a ;
a = 6;//no of players
for(int i =0;i<a;i++){
		count[i] = 0;
		int j;
		j = getch()-'0';
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

		for (int z = 0;z<a; z++ )
		{
			repeat(z,count[z]);
			color(z,color(z));
			back(z,count[z]);
		}
}
*/
