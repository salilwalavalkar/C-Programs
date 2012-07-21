/*
Program for ISO OSI Reference Model
*/

#include<conio.h>
#include<graphics.h>

char headers[][7]={"H1","H2","H3","H4","H5","H6","H7"};
char *hname;

void draw_model()
{
	int i;
	setcolor(WHITE);
	// Left Side
	rectangle(100,100,200,400);
	for(i=100;i<400;i=i+43)
		line(100,i,200,i);
	// Right Side
	rectangle(400,100,500,400);
	for(i=100;i<400;i=i+43)
		line(400,i,500,i);
	line(150,100,150,50);//|
	line(450,100,450,50);//|
	line(150,50,450,50); //=
	// Layer Names
	setcolor(GREEN);
	outtextxy(120,120,"Physical");
	outtextxy(120+300,120,"Physical");
	outtextxy(120,160,"DataLink");
	outtextxy(120+300,160,"DataLink");
	outtextxy(120,200,"Network");
	outtextxy(120+300,200,"Network");
	outtextxy(115,250,"Transport");
	outtextxy(115+300,250,"Transport");
	outtextxy(120,290,"Session");
	outtextxy(120+300,290,"Session");
	outtextxy(105,330,"Presentation");
	outtextxy(105+300,330,"Presentation");
	outtextxy(105,375,"Application");
	outtextxy(105+300,375,"Application");
}

add_headers()
{
	int i,j=1;
	setcolor(LIGHTBLUE);
	outtextxy(100,420,"Adding Headers");
	for(i=370;i>=120;i=i-40)
	{
		setcolor(WHITE);
		if(j==1)
			hname="H1";
		else if(j==2)
			hname="H1 H2";
		else if(j==3)
			hname="H1 H2 H3";
		else if(j==4)
			hname="H1 H2 H3 H4";
		else if(j==5)
			hname="H1 H2 H3 H4 H5";
		else if(j==6)
			hname="H1 H2 H3 H4 H5 H6";
		else if(j==7)
			hname="H1 H2 H3 H4 H5 H6 H7";
		outtextxy(205,i,hname);
		delay(1000);
		setcolor(BLACK);
		outtextxy(205,i,hname);
		j++;
	}
	clr_msg();
}

send_msg()
{
	int i;
	// Physical To Top
	for(i=90;i>=50;i=i-5)
	{
		setcolor(RED);
		circle(150,i,5);
		delay(200);
		setcolor(BLACK);
		circle(150,i,5);
		setcolor(WHITE);
		line(150,100,150,50);//|
	}
	// Left To Right
	for(i=150;i<=450;i=i+5)
	{
		line(150,100,150,50);//|
		setcolor(RED);
		circle(i,50,5);
		delay(200);
		setcolor(BLACK);
		circle(i,50,5);
		setcolor(WHITE);
		line(150,50,450,50); //=
	}
	// Top To Physical
	for(i=50;i<=90;i=i+5)
	{
		line(150,50,450,50); //=
		setcolor(RED);
		circle(450,i,5);
		delay(200);
		setcolor(BLACK);
		circle(450,i,5);
		setcolor(WHITE);
		line(450,100,450,50);//|
	}
}

del_headers()
{
	int i,j=7,k=220;
	setcolor(LIGHTBLUE);
	outtextxy(400,420,"Removing Headers");
	for(i=120;i<=370;i=i+40)
	{
		setcolor(WHITE);
		if(j==1)
			hname="H1";
		else if(j==2)
			hname="H1 H2";
		else if(j==3)
			hname="H1 H2 H3";
		else if(j==4)
			hname="H1 H2 H3 H4";
		else if(j==5)
			hname="H1 H2 H3 H4 H5";
		else if(j==6)
			hname="H1 H2 H3 H4 H5 H6";
		else if(j==7)
			hname="H1 H2 H3 H4 H5 H6 H7";
		outtextxy(k,i,hname);
		delay(1000);
		setcolor(BLACK);
		outtextxy(k,i,hname);
		k=k+25;
		j--;
	}
	clr_msg();
}

clr_msg()
{
	setfillstyle(1,BLACK);
	bar(100,410,550,430);
}

void main()
{
	char ch;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	setcolor(YELLOW);
	outtextxy(200,10,"ISO OSI Reference Model");
	draw_model();
	delay(1000);
	add_headers();
	setcolor(LIGHTBLUE);
	outtextxy(100,420,"Sending Message");
	send_msg();
	delay(1000);
	clr_msg();
	del_headers();
	setcolor(LIGHTBLUE);
	outtextxy(400,420,"Message Recieved");
	delay(1000);
	getch();
}