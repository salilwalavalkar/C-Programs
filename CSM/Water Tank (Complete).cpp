/*
Program for Water Tank Simulation
*/

#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int count=1;
int level=250+215;//-count
char ch;

void GUI()
{
	setcolor((random(255)%16)+1);
	outtextxy(230,20,"WATER TANK SIMULATION");
	setcolor(15);
	outtextxy(465,80,"STATUS");
	setcolor(14);
	outtextxy(50,70,"F : PRESS F TO FILL THE TANK");
	outtextxy(50,80+5,"D : PRESS D TO DRAIN THE TANK");
	outtextxy(50,90+10,"Q : PRESS Q TO EXIT SIMULATION");
	outtextxy(50,100+15,"PRESS SPACEBAR OR KEY TO HALT OPERATION");
	setcolor(15);
}

void draw_ip()
{
	line(0,200,120,200);//-
	line(0,215,120,215);//=
	line(120,200,120,215);//|
	line(122,200,122,215);//|
	line(122,200,128,200); //-
	line(122,215,128,215);   //=
	line(122,200,122,215);//||
	line(124,200,124,215);//|||
	line(126,200,126,215);//|||
	line(128,200,128,215);//||||
	line(130,200,130,215);//||||
	line(130,200,182,200);//-
	line(130,215,170,215);  //=
	line(170,215,170,224);//|
	line(182,200,182,224);//||
	line(170,222,182,222);//close`
	line(170,224,182,224);//close``
}

void beaker()
{
	line(120-20,250,120-20,250+215);//|
	line(120-20,250+215,120+150,250+215);//-
	line(120+150,250+215,120+150,250);//||
}

void draw_op()
{
	line(120+150,250+215,120+150+165,250+215);//=
	line(120+150,250+215-15,120+150+150,250+215-15);//-
	line(120+150+165,250+215,120+150+165,250+215-50);//=|
	line(120+150+165,250+215-50,120+150+165-15,250+215-50);//
	line(120+150+165,250+215-48,120+150+165-15,250+215-48);//
	line(120+150+150,250+215-15,120+150+150,250+215-15-34);//tap hor-|
}

void draw()
{
	setcolor(15);
	GUI();
	draw_ip();
	beaker();
	draw_op();
}

void water_fill()
//keeps the tank filled upto a particular water
//level after animation is over
{
	line(120-20,level-count,120+150,level-count);
	setfillstyle(11,9);
	floodfill(121,250+215-count+1,WHITE);
}

void drain_wt()
{
	ch=NULL;
	int i,j,incr;
	for(i=0;i<=50 && !kbhit()&&count>=2;i++)
	{
		setcolor(random(112)%16);
		delay(10);
		cleardevice();
		draw();
		if(i==10) i=0;
		for(j=0;j<10;j++)
		{
			outtextxy(465,90,"DRAINING TANK");
			if(incr==20&&count<=150+66)
			{
				line(120-20,250+215+count,120+150,250+215+count);incr=0;
				setfillstyle(11,9);
				floodfill(121,250+215-count+1,WHITE);
			}//tank filler
		} //j
		if(count>=2)
		{
			count--;
			water_fill();
		}
		putpixel(120+150+165,250+215-random(150)%100,random(16));
		putpixel(120+150+165-3,250+215-random(250)%150,random(32)%16);
		putpixel(120+150+165-6,250+215-random(350)%100,random(48)%16);
		putpixel(120+150+165-8,250+215-random(250)%150,random(32)%16);
		putpixel(120+150+165-10,250+215-random(350)%100,random(48)%16);
		putpixel(120+150+165-12,250+215-random(350)%100,random(48)%16);
		putpixel(120+150+165-14,250+215-random(250)%150,random(32)%16);
		putpixel(120+150+165-16,250+215-random(350)%100,random(48)%16);
		putpixel(120+150+165,250+215-random(550)%100,random(48)%16);
		putpixel(120+150+167,250+215-random(950)%150,random(48)%16);
		putpixel(120+150+169,250+215-random(230)%100,random(48)%16);
		incr++;
		delay(15);
	}//i
}//end

void flow_wt()
{
	int i,incr=0,j;
	ch=NULL;
	for(i=0;i<=50 && !kbhit();i++)
	{
		setcolor(random(112)%16);
		draw();
		water_fill();
		putpixel(170+3,227+i+10,14);
		putpixel(170+9,227+i+10,14);
		putpixel(170+3,227+i+10+10,14);
		putpixel(170+9,227+i+10+10,14);
		delay(10);
		cleardevice();
		draw();
		if(i==10) i=0;
		for(j=0;j<10;j++)
		{
			outtextxy(465,90,"FILLING TANK");
			if(incr==20&&count<=150+66)
			{
				draw();
				line(120-20,250+215-count,120+150,250+215-count);incr=0;
				setfillstyle(11,9);
				floodfill(121,250+215-count+1,WHITE);
			}//tank filler
			else if(count>=150+66)
			{
				line(120-20,250+215-count,120+150,250+215-count);incr=0;
				floodfill(121,250+215-count+1,WHITE);
				//overflow right
				putpixel(120+153,250+random(200)%150,random(16));
				putpixel(120+156,250+random(250)%200,random(32)%16);
				putpixel(120+158,250+random(350)%200,random(48)%16);
				//overflow left
				putpixel(120-22,250+random(200)%150,random(16));
				putpixel(120-24,250+random(250)%200,random(32)%16);
				putpixel(120-26,250+random(350)%200,random(48)%16);
				outtextxy(465,100,"TANK FULL");
			}//keep tank filled 100%
			putpixel(170,227+random(200)%200,random(16));
			putpixel(176,227+random(250)%200,random(32)%16);
			putpixel(182,227+random(350)%200,random(48)%16);
			putpixel(170,227+i+50+random(200)%200-19,random(32)%16);
			putpixel(176,227+i+50+random(250)%200-19,random(48)%16);
			putpixel(182,227+i+50+random(350)%200-19,random(64)%16);
			incr++;
		}//j
		//tank fill
		if(incr==20&&count<=150+66)
		{
			draw();
			line(120-20,250+215-count,120+150,250+215-count);incr=0;
			setfillstyle(11,9);
			floodfill(121,250+215-count+1,WHITE);
			count+=i%2;
		}//if
		else if(count>=150+66)
		{
			line(120-20,250+215-count,120+150,250+215-count);incr=0;
			floodfill(121,250+215-count+1,WHITE);
			//overflow right
			putpixel(120+153,250+random(200)%150,random(16));
			putpixel(120+156,250+random(250)%200,random(32)%16);
			putpixel(120+158,250+random(350)%200,random(48)%16);
			//overflow left
			putpixel(120-22,250+random(200)%150,random(16));
			putpixel(120-24,250+random(250)%200,random(32)%16);
			putpixel(120-26,250+random(350)%200,random(48)%16);
			delay(15);
		}//keep tank filled 100%
	}//i
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
		case 'f':
			flow_wt();
			cleardevice();
			draw();
			water_fill();
			break;
		case 'd':
			drain_wt();
			cleardevice();
			draw();
			water_fill();
			if(count<=2)outtextxy(465,90,"TANK EMPTY");
			break;
		case 'q':
			cleardevice();
			draw();
			water_fill();
			getch();
			exit(0);
		}
	}
}