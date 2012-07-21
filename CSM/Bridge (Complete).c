/*
Program for Bridge Simulation
*/

#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

int x, y, i;
int d = 500; // Delay

void draw_road(int x,int y)
{
	// Left Road
	bar(0,100,x,110);
	bar(0,250,x,260);
	bar(0,400,x,410);
	// Right Road
	bar(y,100,600,110);
	bar(y,250,600,260);
	bar(y,400,600,410);
}

void open_bridge()
{
	// Open Bridge
	line(300,100,300,410);
	delay(d);
	for(i=0;i<5;i++)
	{
		setfillstyle(1,15);
		bar(x-10,100,x,410);
		bar(y,100,y+10,410);
		
		//Move Bars
		draw_road(x,y);
		
		delay(d);
		
		// Avoid Clearing
		if(x==260)
			break;
		
		// Clear
		setfillstyle(1,0);
		bar(x-10,100,x,410);
		bar(y,100,y+10,410);
		x=x-10;
		y=y+10;
	}
}

void close_bridge()
{
	// Clear part of Bridge
	setfillstyle(1,0);
	bar(x-10,100,x,410);
	bar(y,100,y+10,410);
	
	// Close Bridge
	for(i=0;i<5;i++)
	{
		setfillstyle(1,15);
		bar(x+10,100,x,410);
		bar(y,100,y-10,410);
		
		//Move Bars
		draw_road(x,y);
		
		delay(d);
		
		// Avoid clearing at end
		if(x==290 && y==310)
			break;
		
		// Clear
		setfillstyle(1,0);
		bar(x+10,100,x,410);
		bar(y,100,y-10,410);
		x=x+10;
		y=y-10;
	}
	delay(d);
	setfillstyle(1,0);
	bar(x+10,100,x,410);
	bar(y,100,y-10,410);
	setfillstyle(1,15);
	draw_road(300,300);
	line(300,100,300,410);
	delay(d);
	cleardevice();
	draw_road(300,300);
}

void move_ship()
{
	int shipy=20;
	for(shipy=0;shipy<=400;shipy=shipy+10)
	{
		// Ship appear
		setfillstyle(1,15);
		setcolor(15);
		rectangle(290,shipy,310,shipy+40);
		line(290,shipy,300,shipy-10);
		line(310,shipy,300,shipy-10);
		bar(295,shipy+5,305,shipy+15);
		circle(300,shipy+30,5);
		line(290,shipy+40,300,shipy+70);
		line(310,shipy+40,300,shipy+70);
		delay(500);
		// Ship clear
		setfillstyle(1,0);
		setcolor(0);
		rectangle(290,shipy,310,shipy+40);
		line(290,shipy,300,shipy-10);
		line(310,shipy,300,shipy-10);
		bar(295,shipy+5,305,shipy+15);
		circle(300,shipy+30,5);
		line(290,shipy+40,300,shipy+70);
		line(310,shipy+40,300,shipy+70);
	}
}

void main()
{
	int carl1,carl2,carr1,carr2;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	x=300;y=300;
	draw_road(x,y);
	while(1)
	{
		switch(random(6))
		{
		case 0:
			// Car Left 1
			for(carl1=0;carl1!=550;carl1++)
			{
				setfillstyle(1,15);
				bar(carl1,140,carl1+50,160);
				delay(10);
				setfillstyle(1,0);
				bar(carl1,140,carl1+50,160);
			}
			break;
		case 1:
			// Car Left 2
			for(carl2=0;carl2!=550;carl2++)
			{
				setfillstyle(1,15);
				bar(carl2,200,carl2+50,220);
				delay(10);
				setfillstyle(1,0);
				bar(carl2,200,carl2+50,220);
			}
			break;
		case 2:
			// Car Left 1 and 2
			for(carl1=0,carl2=20;carl1!=550,carl2!=550;carl1++,carl2++)
			{
				setfillstyle(1,15);
				bar(carl1,140,carl1+50,160);
				bar(carl2,200,carl2+50,220);
				delay(10);
				setfillstyle(1,0);
				bar(carl1,140,carl1+50,160);
				bar(carl2,200,carl2+50,220);
			}
			break;
		case 3:
			x=300;y=300;
			open_bridge();
			move_ship();
			delay(1000);
			close_bridge();
			break;
		case 4:
			// Car Right 1
			for(carr1=550;carr1!=0;carr1--)
			{
				setfillstyle(1,15);
				bar(carr1,290,carr1+50,310);
				delay(10);
				setfillstyle(1,0);
				bar(carr1,290,carr1+50,310);
			}
			break;
		case 5:
			// Car Right 2
			for(carr2=550;carr2!=0;carr2--)
			{
				setfillstyle(1,15);
				bar(carr2,350,carr2+50,370);
				delay(10);
				setfillstyle(1,0);
				bar(carr2,350,carr2+50,370);
			}
			break;
		}
	}
}