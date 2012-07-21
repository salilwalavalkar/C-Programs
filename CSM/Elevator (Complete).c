/*
Program for Elevator Simulation
*/

#include<conio.h>
#include<graphics.h>

// Global Paramenters
int x1=251,x2=329,y1=371,y2=451,x11=271,x22=309,y11=70,y22=110;
int i,start,end,end1;

void draw_building()
{
	line(250,130,250,450);  /* Plot left hand side of the Building */
	line(170,130,250,130);
	line(170,130,170,450);
	line(170,210,250,210);
	line(170,290,250,290);
	line(170,370,250,370);
	line(170,450,250,450);
	
	line(330,130,330,450);  /* Plot right hand side of the Building */
	line(330,130,410,130);
	line(330,210,410,210);
	line(330,290,410,290);
	line(330,370,410,370);
	line(330,450,410,450);
	line(410,50,410,450);
	
	setfillstyle(4,6);    /* Left Hatch */
	bar(150,50,260,130);
	
	setfillstyle(5,6);    /* Right Hatch */
	bar(320,50,430,130);
	
	setfillstyle(2,6);    /* Middle Hatch */
	bar(262,50,318,70);
	
	setfillstyle(7,9);  /* Left side Windows */
	bar(200,160,230,190);
	bar(200,240,230,270);
	bar(200,320,230,350);
	bar(200,400,230,430);
	
	setfillstyle(7,9);  /* Right side Windows */
	bar(350,160,380,190);
	bar(350,240,380,270);
	bar(350,320,380,350);
	bar(350,400,380,430);
	
	setfillstyle(1,4);    /* Ground floor Block */
	bar(251,370,329,450);
	setcolor(0);
	line(290,50,290,450);
	
	setfillstyle(2,4);    /* Weight Block */
	bar(271,70,309,110);
	line(290,50,290,450);
	
	setfillstyle(11,7);    /* Ground Block */
	bar(160,450,420,460);
}

void open_close() /* Function to Open and Close the Door */
{
	int a1=290,a2=290;
	delay(500);
	while(a1!=265)	// Open Door
	{
		setfillstyle(1,1);
		setcolor(0);
		line(a1,y1,a1,y2);
		line(a2,y1,a2,y2);
		delay(100);
		a1=a1-1;
		a2=a2+1;
	}
	delay(500);
	
	while(a1!=290)	// Close Door
	{
		setcolor(4);
		line(a1,y1+1,a1,y2);
		line(a2,y1+1,a2,y2);
		delay(100);
		a1=a1+1;
		a2=a2-1;
	}
}

void draw_center_bar()
{
	setfillstyle(1,7);     // Center Bar Style
	bar(280,70,300,450);  // Center Bar
}

void move_elevator()
{
	if(start > end)			// Move Up
	{
		for(i=start;i>=end;i--)
		{
			draw_center_bar();
			setfillstyle(2,4);
			bar(x11,y11,x22,y22);
			setfillstyle(1,4);
			bar(x1,y1,x2,y2);
			setcolor(0);
			line(290,50,290,450);
			delay(50);
			line(x1,y2,x2,y2);
			line(x11,y11,x22,y11);
			y1=y1-1;
			y2=y2-1;
			y11=y11+1;
			y22=y22+1;
		}
		open_close();
	}
	
	else                   // Move Down
	{
		for(i=start;i<=end;i++)
		{
			draw_center_bar();
			setfillstyle(2,4);
			bar(x11,y11,x22,y22);
			setfillstyle(1,4);
			bar(x1,y1,x2,y2);
			setcolor(0);
			line(290,50,290,450);
			delay(50);
			line(x1,y1,x2,y1);
			line(x11,y22,x22,y22);
			y1=y1+1;
			y2=y2+1;
			y11=y11-1;
			y22=y22-1;
		}
		open_close();
	}
	start = end;
}

void draw_panel()
{
	//setfillstyle(1,15);
	setcolor(15);
	rectangle(50,50,100,150);
	// Floor 1
	setfillstyle(1,0);
	fillellipse(62,70,7,7);
	circle(62,70,7);
	outtextxy(59,67,"1");
	// Floor 2
	setfillstyle(1,0);
	fillellipse(85,70,7,7);
	circle(85,70,7);
	outtextxy(82,67,"2");
	// Floor 3
	setfillstyle(1,0);
	fillellipse(62,95,7,7);
	circle(62,95,7);
	outtextxy(59,92,"3");
	// Floor 0
	setfillstyle(1,0);
	fillellipse(85,95,7,7);
	circle(85,95,7);
	outtextxy(82,92,"0");
	// Open Door
	setfillstyle(1,0);
	rectangle(58,112,95,125);
	floodfill(59,113,WHITE);
	outtextxy(61,115,"0pen");
}

void light_on(char ch)
{
	switch(ch)
	{
	case '1':
		setfillstyle(1,4);
		fillellipse(62,70,7,7);
		setcolor(15);
		outtextxy(59,67,"1");
		break;
	case '2':
		setfillstyle(1,4);
		fillellipse(85,70,7,7);
		setcolor(15);
		outtextxy(82,67,"2");
		break;
	case '3':
		setfillstyle(1,4);
		fillellipse(62,95,7,7);
		setcolor(15);
		outtextxy(59,92,"3");
		break;
	case '0':
		setfillstyle(1,4);
		fillellipse(85,95,7,7);
		setcolor(15);
		outtextxy(82,92,"0");
		break;
	case 'o':
		setfillstyle(1,4);
		rectangle(58,112,95,125);
		floodfill(59,113,WHITE);
		setcolor(15);
		outtextxy(61,115,"0pen");
		break;
	}
}

void main()
{
	char ch;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	draw_center_bar();
	draw_building();
	setcolor(14);
	outtextxy(220,10,"Elevator Simulation");
	setcolor(2);
	outtextxy(470,20,"Press Q to Quit");
	outtextxy(470,50,"Press O to Open Door");
	start=450;
	end=0;
	draw_panel();
	while(ch!='q')
	{
		setcolor(15);
		outtextxy(20,20,"Select Option: ");
		gotoxy(18,2);
		scanf("%s",&ch);
		
		switch(ch)
		{
		case '0' :
			end=450;
			end1=390;
			light_on(ch);
			move_elevator();
			draw_panel();
			break;
		case '1' :
			end=370;
			end1=70;
			light_on(ch);
			move_elevator();
			draw_panel();
			break;
		case '2' :
			end=290;
			end1=150;
			light_on(ch);
			move_elevator();
			draw_panel();
			break;
			
		case '3' :
			end=210;
			end1=230;
			light_on(ch);
			move_elevator();
			draw_panel();
			break;
			
		case 'o':
			light_on(ch);
			open_close();
			draw_panel();
			break;
		default : exit(0);
		}
	}
	getch();
}