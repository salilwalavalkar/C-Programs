/*
Program for Super Market Simulation
*/

#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

void border()
{
	setbkcolor(8);
	setfillstyle(1,6);
	bar(0,0,650,10);
	bar(0,0,10,480);
	bar(0,465,650,480);
	bar(630,0,650,480);
}

void menu()
{
	settextstyle(2,0,9);
	outtextxy(120,15,"Automated Shopping Cart");
	bar(0,60,650,70);
	rectangle(11,11,629,60);
	rectangle(11,71,629,465);
	settextstyle(2,0,7);
	outtextxy(235,80,"Select items...");
	bar(50,200,200,250);
	rectangle(51,201,199,249);
	bar(240,200,390,250);
	rectangle(241,201,389,249);
	bar(440,200,590,250);
	rectangle(441,201,589,249);
	setcolor(15);
	outtextxy(65,210,"ELECTRONICS");
	outtextxy(290,210,"BOOKS");
	outtextxy(465,210,"COMPUTER");
	bar(50,300,250,325);
	settextstyle(2,0,6);
	outtextxy(60,305,"Enter Your Choice: ");
	outtextxy(300,440,"Press Key other than 1-3 to Quit");
}


void department1()
{
	border();
	rectangle(11,11,629,49);
	rectangle(11,71,629,465);
	settextstyle(2,0,8);
	outtextxy(230,15,"Automated Shopping Cart");
	bar(0,50,650,70);
	rectangle(79,79,551,301);
	bar(80,80,550,300);
	settextstyle(2,0,6);
	outtextxy(90,85,"DEVICE ");
	outtextxy(280,85,"COMPANY  ");
	outtextxy(430,85,"PRICE  ");
	settextstyle(2,0,5);
	outtextxy(90,120,"1. Television ");
	outtextxy(90,145,"2. Television ");
	outtextxy(90,170,"3. VCD Player ");
	outtextxy(90,195,"4. MP3 Player ");
	outtextxy(90,220,"5. Speaker ");
	outtextxy(90,245,"6. Watch ");
	outtextxy(90,270,"7. VCP ");
	outtextxy(280,120,"ONIDA");
	outtextxy(280,145,"Panasonic");
	outtextxy(280,170,"Samsung");
	outtextxy(280,195,"Sony");
	outtextxy(280,220,"Mercury");
	outtextxy(280,245,"Titan");
	outtextxy(280,270,"LG");
	outtextxy(430,120,"11000");
	outtextxy(430,145,"8000");
	outtextxy(430,170,"3999");
	outtextxy(430,195,"2500");
	outtextxy(430,220,"1850");
	outtextxy(430,245,"1500");
	outtextxy(430,270,"5000");
}

void department2()
{
	border();
	rectangle(11,11,629,49);
	rectangle(11,71,629,465);
	settextstyle(2,0,9);
	outtextxy(120,15,"Automated Shopping Cart");
	bar(0,50,650,70);
	rectangle(79,79,551,301);
	bar(80,80,550,300);
	
	settextstyle(2,0,7);
	outtextxy(90,85,"Book Name ");
	outtextxy(285,85,"Author ");
	outtextxy(380,85,"Edition ");
	outtextxy(480,85,"Price ");
	
	settextstyle(2,0,5);
	outtextxy(90,120,"1. Let Us C ");
	outtextxy(90,145,"2. Let Us C++ ");
	outtextxy(90,170,"3. Java 2 ");
	outtextxy(90,195,"4. HTML 4 ");
	outtextxy(90,220,"5. VB 6.0 ");
	outtextxy(90,245,"6. Essential Com ");
	outtextxy(90,270,"7. Learn VB in 21 days ");
	outtextxy(285,120,"Kanetkar ");
	outtextxy(285,145,"Kanetkar ");
	outtextxy(285,170,"Java 2 ");
	outtextxy(285,195,"Molley E. ");
	outtextxy(285,220,"Nilesh A. ");
	outtextxy(285,245,"Don Box ");
	outtextxy(285,270,"Perry ");
	outtextxy(410,120,"4th        280 ");
	outtextxy(410,145,"4th        295");
	outtextxy(410,170,"3rd        345");
	outtextxy(410,195,"2nd        100");
	outtextxy(410,220,"3rd        340");
	outtextxy(410,245,"2nd        395");
	outtextxy(410,270,"4th        425");
}

void department3()
{
	border();
	rectangle(11,11,629,49);
	rectangle(11,71,629,465);
	settextstyle(2,0,8);
	outtextxy(120,15,"Automated Shopping Cart");
	bar(0,50,650,70);
	setcolor(15);
	rectangle(79,79,551,301);
	bar(80,80,550,300);
	
	settextstyle(2,0,7);
	outtextxy(260,85,"COMPUTERS ");
	
	settextstyle(2,0,5);
	outtextxy(90,120,"Device ");
	outtextxy(270,120,"Price ");
	outtextxy(340,120,"Device ");
	outtextxy(490,120,"Price ");
	outtextxy(90,145,"1. Front Case           999 ");
	outtextxy(90,170,"2. Motherboard         7550");
	outtextxy(90,195,"3. Processor Celeron   4350");
	outtextxy(90,220,"4. Processor P IV      6999  ");
	outtextxy(90,245,"5. Monitor 14          6500");
	outtextxy(90,270,"6. Monitor 15          7500");
	outtextxy(340,145,"7. Mouse            500");
	outtextxy(340,170,"8. Keyboard         500");
	outtextxy(340,195,"9. Modem           1500");
	outtextxy(340,220,"10. HardDisk 40GB  2500");
	outtextxy(340,245,"11. HardDisk 80GB  4000");
}

void thanks()
{
	int i;
	cleardevice();
	border();
	rectangle(10,10,630,465);
	settextstyle(1,0,6);
	outtextxy(270,170,"THANK YOU");
	settextstyle(2,0,15);
	outtextxy(240,200,"Please Visit Again");
}

void main()
{
	int i;
	float ch,no,copy,b[1],total,tot,a[18];
	char ans;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	
	border();
	rectangle(10,10,630,465);
	
	settextstyle(1,0,6);
	outtextxy(250,170,"WELLCOME TO");
	
	for(i=1;i<=14;i++)
	{
		setcolor(i);
		settextstyle(2,0,8);
		outtextxy(150,200,"Automated Shopping Cart");
		delay(500);
	}
	cleardevice();
	
	border();
	menu();
	
l4 : printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t");
	 border();
	 bar(50,340,80,370);
	 rectangle(11,71,629,465);
	 scanf("%f",&ch);
	 
	 if(ch==1)
	 {
		 clrscr();
		 cleardevice();
		 department1();
		 a[1]=11000;a[2]=8000;a[3]=3999;a[4]=2500;a[5]=1850;a[6]=1500;a[7]=5000;
		 b[1]=99;
		 total=0;
		 
l1 : {
		 department1();
		 outtextxy(80,320,"Enter The Product No");
		 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%f",&no);
		 outtextxy(80,350,"Enter The No. Of Set To Buy");
		 printf("\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%f",&copy);
		 outtextxy(80,380,"Total Amount To Paid");
		 tot=a[no] * copy;
		 total=total+tot;
		 rectangle(11,71,629,465);
		 printf("\n\t\t%.2f",total);
		 border();
		 outtextxy(80,415,"U Want To Buy Another Item");
		 border();
		 printf("\n\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%s",&ans);
		 clrscr();
		 cleardevice();
		 
		 if(ans=='y' || ans=='Y')
		 {
			 goto l1;
		 }
		 else
		 {
			 menu();
			 border();
			 goto l4;
		 }
	 }
	 }
	 
	 if(ch==2)
	 {
		 clrscr();
		 cleardevice();
		 department2();
		 a[1]=280;a[2]=295;a[3]=345;a[4]=100;a[5]=340;a[6]=395;a[7]=425;
		 total=0;
		 
l2 : {
		 department2();
		 outtextxy(80,320,"Enter The Book No");
		 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%f",&no);
		 outtextxy(80,350,"Enter The No. Of Copies");
		 printf("\n\t\t");
		 rectangle(11,71,629,465);
		 border();
		 scanf("%f",&copy);
		 outtextxy(80,380,"Total Amount To Paid");
		 tot=a[no] * copy;
		 total=total+tot;
		 printf("\n\t\t%.2f",total);
		 border();
		 rectangle(11,71,629,465);
		 outtextxy(80,415,"U Want To Buy Another Book");
		 border();
		 printf("\n\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%s",&ans);
		 clrscr();
		 cleardevice();
		 
		 if(ans=='y' || ans=='Y')
		 {
			 goto l2;
		 }
		 else
		 {
			 menu();
			 border();
			 goto l4;
		 }
	 }
	 }
	 
	 if(ch==3)
	 {
		 clrscr();
		 cleardevice();
		 department3();
		 a[1]=999;a[2]=7550;a[3]=4350;a[4]=6999;a[5]=6500;a[6]=7500;
		 a[7]=500;a[8]=500;a[9]=1500;a[10]=2500;a[11]=4000;
		 total=0;
		 
l3 : {
		 department3();
		 outtextxy(80,320,"Enter The Product No");
		 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%f",&no);
		 outtextxy(80,350,"Enter The No. Set");
		 printf("\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%f",&copy);
		 outtextxy(80,380,"Total Amount To Paid Is.");
		 tot=a[no] * copy;
		 total=total+tot;
		 printf("\n\t\t%.2f",total);
		 border();
		 rectangle(11,71,629,465);
		 outtextxy(80,415,"U Want To Buy Another Device.");
		 border();
		 printf("\n\n\t\t");
		 border();
		 rectangle(11,71,629,465);
		 scanf("%s",&ans);
		 clrscr();
		 cleardevice();
		 
		 if(ans=='y' || ans=='Y')
		 {
			 goto l3;
		 }
		 
		 else
		 {
			 menu();
			 border();
			 goto l4;
		 }
		 
	 }
	 }
	 else
		 thanks();
	 getch();
	 closegraph();
}