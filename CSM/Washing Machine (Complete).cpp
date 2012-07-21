/*
Program for Washing Machine Simulation
*/

#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int num_of_clothes=0;
char ch;

void clear_bar()
{
	setfillstyle(1,BLACK);
	bar(400,90,600,120);
	setcolor(WHITE);
}

void GUI()
{
	outtextxy(230,20,"WASHING MACHINE SIMULATION");
	outtextxy(465,80,"STATUS");
	setcolor(14);
	outtextxy(50,70,"A : PRESS A TO ADD CLOTHES");
	outtextxy(50,80+5,"W : PRESS W TO WASH CLOTHES");
	outtextxy(50,90+10,"Q : PRESS Q TO EXIT SIMULATION");
	setcolor(15);
}

void machine()
{
	rectangle(200,250,400,450);
	circle(300,360,50);
	line(200,280,400,280);//=
}

void draw()
{
	setcolor(15);
	GUI();
	machine();
}

void add_clothes()
{
	int i;
	if(num_of_clothes==5)
		outtextxy(460,100,"MACHINE FULL");
	else
	{
		outtextxy(440,100,"ADDING CLOTHES");
		num_of_clothes++;
		for(i=150;i<=199;i++)
		{
			setfillstyle(num_of_clothes+5,WHITE);
			rectangle(220,i,270,i+50);
			floodfill(225,i+5,WHITE);
			delay(50);
			setfillstyle(1,BLACK);
			bar(220,i,270,i+50); // Clear
		}
		clear_bar();
	}
}

void wash_clothes()
{
	if(num_of_clothes==0)
	{
		outtextxy(440,100,"ADD CLOTHES FIRST");
		delay(1000);
		clear_bar();
	}
	else
	{
		outtextxy(460,100,"WASHING");
		for(int i=0;i<20;i++)
		{
			setfillstyle(2,BLUE); // Blue Lines
			floodfill(300,360,WHITE);
			delay(50);
			setfillstyle(1,BLACK); // Clear
			floodfill(300,360,WHITE);
			delay(50);
		}
		clear_bar();
		outtextxy(450,100,"CLOTHES WASHED");
		delay(1500);
		cleardevice();
		draw();
	}
}

void main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	draw();
	ch=getch();
	while(1)
	{
		ch=getch();
		switch(ch)
		{
		case 'a':
			draw();
			add_clothes();
			break;
		case 'w':
			cleardevice();
			draw();
			wash_clothes();
			num_of_clothes=0;
			break;
		case 'q':
			cleardevice();
			exit(0);
		}
	}
}