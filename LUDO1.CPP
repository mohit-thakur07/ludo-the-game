#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>

class ludo
{
   private:
     int sx[4],sy[4],pp[4],ppx1[66],ppx2[66],ppy1[66],ppy2[66],pth_col,move[4],posX[4],posY[4];

     int dice();
     void start_placement(int num);
     char arrow();
     int placement(int);
   public:
     void start_pos(int px1,int py1,int px2,int py2,int px3,int py3,int px4,int py4);
     void path(int col);
     void player();
}p[4];

void backGround();    // ludo board

int winner[3],win=0,play_num;

void main()
{
   int i=0,dd,dm=DETECT;
   char ch;
      clrscr();
      gotoxy(20,9);
      cout<<"Number of players:";
      gotoxy(20,10);
      cout<<"2 PLAYERS";
      gotoxy(20,11);
      cout<<"4 PLAYERS";
      gotoxy(20,12);
      cin>>play_num;
      if(play_num!=2&&play_num!=4)
      {
	 play_num=4;
      }
   initgraph(&dm,&dd,"C://TURBOC3//BGI");
   setbkcolor(9);
   setcolor(YELLOW);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   outtextxy((getmaxx()/2)-260,(getmaxy()/2)-20,"    LUDO THE GAME");
   setcolor(WHITE);
   outtextxy(0,50,"Use enter key to roll the dice");
   outtextxy(0,100,"Use letters on moves to move");
   outtextxy(0,150,"Press any  key to start");
   getch();
   cleardevice();
   backGround();
   p[0].path(RED);
   p[1].path(GREEN);
   p[2].path(BLUE);
   p[3].path(YELLOW);
   if(play_num==4)
   {
      p[0].start_pos(110,80,110,160,190,80,190,160),p[1].start_pos(110,330,110,410,190,330,190,410),p[2].start_pos(360,330,360,410,440,330,440,410),p[3].start_pos(360,80,360,160,440,80,440,160);
   }
   else
   {
      p[0].start_pos(110,80,110,160,190,80,190,160),p[2].start_pos(360,330,360,410,440,330,440,410);
   }
   do
   {
      while(!kbhit()&&i<4)
      {
	 p[i].player();
	 if((play_num==4&&win==3)||(play_num==2&&win==1))
	 {
	    goto win_lb;
	 }
	 i++;
	 if((i==1||i==3)&&play_num==2)
	 {
	   i++;
	 }
      }
      if(i<4)
      {
	 ch=getch();
      }
      else if(i==4)
      {
	 i=0;
      }
   }while(ch!=26);
   win_lb:
   if((play_num==4&&win==3)||(play_num==2&&win==1))
   {
	setcolor(8);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy((getmaxx()/2)-150,(getmaxy()/2)-20,"GAME OVER!");
	getch();
	cleardevice();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	for(int w=0;w<play_num-1;w++)
	{
	   setcolor(winner[w]);
	   outtextxy(250,(w+1)*100,"WINNER!");
	}
   }
   getch();
   closegraph();
}

void backGround()
{
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   outtextxy(0,0,"Pres ctrl+z to quit");
   rectangle(50,20,500,470); //outer box
   rectangle(70,40,480,450); //inner box
   rectangle(250,220,300,270); //most inner box
   line(230,200,250,220);
   line(230,290,250,270);
   line(320,200,300,220);
   line(320,290,300,270);
   settextstyle(TRIPLEX_FONT,VERT_DIR,1);
   outtextxy(50,40,"PLAYER 1");
   outtextxy(50,290,"PLAYER 2");
   outtextxy(480,40,"PLAYER 4");
   outtextxy(480,290,"PLAYER 3");
   setcolor(WHITE);
   setusercharsize(1,2,1,2);
   settextstyle(TRIPLEX_FONT,VERT_DIR,0);
   outtextxy(228,212,"H O M E");
   outtextxy(302,208,"H O M E");
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
   outtextxy(242,272,"H O M E");
   outtextxy(242,200,"H O M E");
   setcolor(WHITE);

   rectangle(70,40,230,200); //red box
   line(230,200,230,290);
   setfillstyle(SOLID_FILL,RED);
   line(70,230,230,230);
   line(70,260,230,260);
   floodfill(90,50,WHITE);
   floodfill(231,220,WHITE);
   setfillstyle(SOLID_FILL,6);
   circle(110,80,20);
   floodfill(110,80,WHITE);
   circle(110,160,20);
   floodfill(110,160,WHITE);
   circle(190,80,20);
   floodfill(190,80,WHITE);
   circle(190,160,20);
   floodfill(190,160,WHITE);

   rectangle(70,290,230,450); //green box
   line(230,290,320,290);
   setfillstyle(SOLID_FILL,GREEN);
   line(260,290,260,450);
   line(290,290,290,450);
   floodfill(90,300,WHITE);
   floodfill(260,280,WHITE);
   setfillstyle(SOLID_FILL,10);
   circle(110,330,20);
   floodfill(110,330,WHITE);
   circle(110,410,20);
   floodfill(110,410,WHITE);
   circle(190,330,20);
   floodfill(190,330,WHITE);
   circle(190,410,20);
   floodfill(190,410,WHITE);

   rectangle(320,290,480,450); //blue box
   line(320,290,320,200);
   setfillstyle(SOLID_FILL,BLUE);
   line(320,260,480,260);
   line(320,230,480,230);
   floodfill(330,300,WHITE);
   floodfill(310,260,WHITE);
   setfillstyle(SOLID_FILL,3);
   circle(360,330,20);
   floodfill(360,330,WHITE);
   circle(360,410,20);
   floodfill(360,410,WHITE);
   circle(440,330,20);
   floodfill(440,330,WHITE);
   circle(440,410,20);
   floodfill(440,410,WHITE);

   rectangle(320,40,480,200); //yellow box
   line(230,200,320,200);
   setfillstyle(SOLID_FILL,YELLOW);
   line(260,40,260,200);
   line(290,40,290,200);
   floodfill(330,50,WHITE);
   floodfill(290,210,WHITE);
   setfillstyle(SOLID_FILL,7);
   circle(360,80,20);
   floodfill(360,80,WHITE);
   circle(360,160,20);
   floodfill(360,160,WHITE);
   circle(440,80,20);
   floodfill(440,80,WHITE);
   circle(440,160,20);
   floodfill(440,160,WHITE);

   settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
   setcolor(RED);
   outtextxy(520,100,"RED ki hul:");
   setcolor(GREEN);
   outtextxy(520,150,"GREEN ki hul:");
   setcolor(BLUE);
   outtextxy(520,200,"BLUE ki hul:");
   setcolor(YELLOW);
   outtextxy(520,250,"YELLOW ki hul:");
   setcolor(WHITE);
}

void ludo::path(int col)
{
  pth_col=col;

  int x=0,y=0,i;
  if(col==RED)
  {
     for(i=0;i<66;i++)   //red part
     {
	 if(i+1>=1&&i+1<=6)  //first part
	 {
	    p[0].ppx1[i]=98+x;
	    p[0].ppx2[i]=120+x;
	    p[0].ppy1[i]=200;
	    p[0].ppy2[i]=230;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    x+=22;
	    if(i+1==1)
	    {
	       setfillstyle(SOLID_FILL,RED);
	       bar(p[0].ppx1[i]+1,p[0].ppy1[i]+1,p[0].ppx2[i]-1,p[0].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(RED);
	       pieslice((p[0].ppx1[i]+p[0].ppx2[i])/2,(p[0].ppy1[i]+p[0].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==6)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=7&&i+1<=12)//second part
	 {
	    p[0].ppx1[i]=230;
	    p[0].ppx2[i]=260;
	    p[0].ppy1[i]=178-y;
	    p[0].ppy2[i]=200-y;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    y+=22;
	    if(i+1==11)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[0].ppx1[i]+p[0].ppx2[i])/2-4,(p[0].ppy1[i]+p[0].ppy2[i])/2-10,"*");
	    }
	    if(i+1==12)
	    {
	      y=0;
	    }
	 }
	 else if(i+1>=13&&i+1<=15)//third part
	 {
	    p[0].ppx1[i]=230+x;
	    p[0].ppx2[i]=260+x;
	    p[0].ppy1[i]=40;
	    p[0].ppy2[i]=68;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    x+=30;
	    if(i+1==15)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=16&&i+1<=21)//fourth part
	 {
	    p[0].ppx1[i]=290;
	    p[0].ppx2[i]=320;
	    p[0].ppy1[i]=68+y;
	    p[0].ppy2[i]=90+y;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    y+=22;
	    if(i+1==16)
	    {
	       setfillstyle(SOLID_FILL,YELLOW);
	       bar(p[0].ppx1[i]+1,p[0].ppy1[i]+1,p[0].ppx2[i]-1,p[0].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[0].ppx1[i]+p[0].ppx2[i])/2,(p[0].ppy1[i]+p[0].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==21)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=22&&i+1<=27)//fifth part
	 {
	    p[0].ppx1[i]=320+x;
	    p[0].ppx2[i]=342+x;
	    p[0].ppy1[i]=200;
	    p[0].ppy2[i]=230;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    x+=22;
	    if(i+1==26)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[0].ppx1[i]+p[0].ppx2[i])/2-4,(p[0].ppy1[i]+p[0].ppy2[i])/2-10,"*");
	    }
	    if(i+1==27)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=28&&i+1<=30) //sixth part
	 {
	    p[0].ppx1[i]=452;
	    p[0].ppx2[i]=480;
	    p[0].ppy1[i]=200+y;
	    p[0].ppy2[i]=230+y;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    y+=30;
	    if(i+1==30)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=31&&i+1<=36)//seventh part
	 {
	    p[0].ppx1[i]=430-x;
	    p[0].ppx2[i]=452-x;
	    p[0].ppy1[i]=260;
	    p[0].ppy2[i]=290;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    x+=22;
	    if(i+1==31)
	    {
	       setfillstyle(SOLID_FILL,BLUE);
	       bar(p[0].ppx1[i]+1,p[0].ppy1[i]+1,p[0].ppx2[i]-1,p[0].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[0].ppx1[i]+p[0].ppx2[i])/2,(p[0].ppy1[i]+p[0].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==36)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=37&&i+1<=42)//eigth part
	 {
	    p[0].ppx1[i]=290;
	    p[0].ppx2[i]=320;
	    p[0].ppy1[i]=290+y;
	    p[0].ppy2[i]=312+y;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    y+=22;
	    if(i+1==41)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[0].ppx1[i]+p[0].ppx2[i])/2-4,(p[0].ppy1[i]+p[0].ppy2[i])/2-10,"*");
	    }
	    if(i+1==42)
	    {
	      y=0;
	    }
	 }
	 else if(i+1>=43&&i+1<=45)//ninth part
	 {
	    p[0].ppx1[i]=290-x;
	    p[0].ppx2[i]=320-x;
	    p[0].ppy1[i]=422;
	    p[0].ppy2[i]=450;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    x+=30;
	    if(i+1==45)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=46&&i+1<=51)//tenth part
	 {
	    p[0].ppx1[i]=230;
	    p[0].ppx2[i]=260;
	    p[0].ppy1[i]=400-y;
	    p[0].ppy2[i]=422-y;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    y+=22;
	    if(i+1==46)
	    {
	       setfillstyle(SOLID_FILL,GREEN);
	       bar(p[0].ppx1[i]+1,p[0].ppy1[i]+1,p[0].ppx2[i]-1,p[0].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[0].ppx1[i]+p[0].ppx2[i])/2,(p[0].ppy1[i]+p[0].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==51)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=52&&i+1<=57) //eleventh part
	 {
	    p[0].ppx1[i]=208-x;
	    p[0].ppx2[i]=230-x;
	    p[0].ppy1[i]=260;
	    p[0].ppy2[i]=290;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    x+=22;
	    if(i+1==56)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[0].ppx1[i]+p[0].ppx2[i])/2-4,(p[0].ppy1[i]+p[0].ppy2[i])/2-10,"*");
	    }
	    if(i+1==57)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=58&&i+1<=59)     //twelveth part
	 {
	    p[0].ppx1[i]=70;
	    p[0].ppx2[i]=98;
	    p[0].ppy1[i]=260-y;
	    p[0].ppy2[i]=290-y;
	    rectangle(p[0].ppx1[i],p[0].ppy1[i],p[0].ppx2[i],p[0].ppy2[i]);
	    y+=30;
	    if(i+1==59)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=60&&i+1<=65)   //thirteenth part
	 {
	    p[0].ppx1[i]=98+x;
	    p[0].ppx2[i]=120+x;
	    p[0].ppy1[i]=230;
	    p[0].ppy2[i]=260;
	    setfillstyle(SOLID_FILL,RED);
	    bar(98+x+1,230+1,120+x-1,260-1);
	    x+=22;
	    if(i+1==65)
	    {
	       x=0;
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
	       outtextxy(78,235,"-->");
	    }
	 }
     }
  }

  else if(col==GREEN)
  {
     for(i=0;i<66;i++)	//green part
     {
	 if(i+1>=1&&i+1<=6)     // first part
	 {
	    p[1].ppx1[i]=230;
	    p[1].ppx2[i]=260;
	    p[1].ppy1[i]=400-y;
	    p[1].ppy2[i]=422-y;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    y+=22;
	    if(i+1==1)
	    {
	       setfillstyle(SOLID_FILL,GREEN);
	       bar(p[1].ppx1[i]+1,p[1].ppy1[i]+1,p[1].ppx2[i]-1,p[1].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(GREEN);
	       pieslice((p[1].ppx1[i]+p[1].ppx2[i])/2,(p[1].ppy1[i]+p[1].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==6)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=7&&i+1<=12)               //second part
	 {
	    p[1].ppx1[i]=208-x;
	    p[1].ppx2[i]=230-x;
	    p[1].ppy1[i]=260;
	    p[1].ppy2[i]=290;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    x+=22;
	    if(i+1==11)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[1].ppx1[i]+p[1].ppx2[i])/2-4,(p[1].ppy1[i]+p[1].ppy2[i])/2-10,"*");
	    }
	    if(i+1==12)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=13&&i+1<=15)  //third part
	 {
	    p[1].ppx1[i]=70;
	    p[1].ppx2[i]=98;
	    p[1].ppy1[i]=260-y;
	    p[1].ppy2[i]=290-y;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    y+=30;
	    if(i+1==15)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=16&&i+1<=21)      //fourth part
	 {
	    p[1].ppx1[i]=98+x;
	    p[1].ppx2[i]=120+x;
	    p[1].ppy1[i]=200;
	    p[1].ppy2[i]=230;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    x+=22;
	    if(i+1==16)
	    {
	       setfillstyle(SOLID_FILL,RED);
	       bar(p[1].ppx1[i]+1,p[1].ppy1[i]+1,p[1].ppx2[i]-1,p[1].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[1].ppx1[i]+p[1].ppx2[i])/2,(p[1].ppy1[i]+p[1].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==21)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=22&&i+1<=27)    //fifith part
	 {
	    p[1].ppx1[i]=230;
	    p[1].ppx2[i]=260;
	    p[1].ppy1[i]=178-y;
	    p[1].ppy2[i]=200-y;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    y+=22;
	    if(i+1==26)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[1].ppx1[i]+p[1].ppx2[i])/2-4,(p[1].ppy1[i]+p[1].ppy2[i])/2-10,"*");
	    }
	    if(i+1==27)
	    {
	      y=0;
	    }
	 }
	 else if(i+1>=28&&i+1<=30)      // sixth part
	 {
	    p[1].ppx1[i]=230+x;
	    p[1].ppx2[i]=260+x;
	    p[1].ppy1[i]=40;
	    p[1].ppy2[i]=68;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    x+=30;
	    if(i+1==30)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=31&&i+1<=36) //seventh part
	 {
	    p[1].ppx1[i]=290;
	    p[1].ppx2[i]=320;
	    p[1].ppy1[i]=68+y;
	    p[1].ppy2[i]=90+y;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    y+=22;
	    if(i+1==31)
	    {
	       setfillstyle(SOLID_FILL,YELLOW);
	       bar(p[1].ppx1[i]+1,p[1].ppy1[i]+1,p[1].ppx2[i]-1,p[1].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[1].ppx1[i]+p[1].ppx2[i])/2,(p[1].ppy1[i]+p[1].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==36)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=37&&i+1<=42)               //eigth part
	 {
	    p[1].ppx1[i]=320+x;
	    p[1].ppx2[i]=342+x;
	    p[1].ppy1[i]=200;
	    p[1].ppy2[i]=230;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    x+=22;
	    if(i+1==41)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[1].ppx1[i]+p[1].ppx2[i])/2-4,(p[1].ppy1[i]+p[1].ppy2[i])/2-10,"*");
	    }
	    if(i+1==42)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=43&&i+1<=45)      //ninth part
	 {
	    p[1].ppx1[i]=452;
	    p[1].ppx2[i]=480;
	    p[1].ppy1[i]=200+y;
	    p[1].ppy2[i]=230+y;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    y+=30;
	    if(i+1==45)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=46&&i+1<=51)        //tenth part
	 {
	    p[1].ppx1[i]=430-x;
	    p[1].ppx2[i]=452-x;
	    p[1].ppy1[i]=260;
	    p[1].ppy2[i]=290;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    x+=22;
	    if(i+1==46)
	    {
	       setfillstyle(SOLID_FILL,BLUE);
	       bar(p[1].ppx1[i]+1,p[1].ppy1[i]+1,p[1].ppx2[i]-1,p[1].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[1].ppx1[i]+p[1].ppx2[i])/2,(p[1].ppy1[i]+p[1].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==51)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=52&&i+1<=57)         //eleventh part
	 {
	    p[1].ppx1[i]=290;
	    p[1].ppx2[i]=320;
	    p[1].ppy1[i]=290+y;
	    p[1].ppy2[i]=312+y;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    y+=22;
	    if(i+1==56)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[1].ppx1[i]+p[1].ppx2[i])/2-4,(p[1].ppy1[i]+p[1].ppy2[i])/2-10,"*");
	    }
	    if(i+1==57)
	    {
	      y=0;
	    }
	 }
	 else if(i+1>=58&&i+1<=59)          //twevelth part
	 {
	    p[1].ppx1[i]=290-x;
	    p[1].ppx2[i]=320-x;
	    p[1].ppy1[i]=422;
	    p[1].ppy2[i]=450;
	    rectangle(p[1].ppx1[i],p[1].ppy1[i],p[1].ppx2[i],p[1].ppy2[i]);
	    x+=30;
	    if(i+1==59)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=60&&i+1<=65)          //thirteenth part
	 {
	    p[1].ppx1[i]=260;
	    p[1].ppx2[i]=290;
	    p[1].ppy1[i]=400-y;
	    p[1].ppy2[i]=422-y;
	    setfillstyle(SOLID_FILL,GREEN);
	    bar(260+1,400-y+1,290-1,422-y-1);
	    y+=22;
	    if(i+1==65)
	    {
	       y=0;
	       settextstyle(TRIPLEX_FONT,VERT_DIR,0);
	       outtextxy(265,410,"-->");
	    }
	 }
     }
  }

  else if(col==BLUE)
  {
     for(i=0;i<66;i++)	//blue part
     {
	 if(i+1>=1&&i+1<=6)        //first part
	 {
	    p[2].ppx1[i]=430-x;
	    p[2].ppx2[i]=452-x;
	    p[2].ppy1[i]=260;
	    p[2].ppy2[i]=290;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    x+=22;
	    if(i+1==1)
	    {
	       setfillstyle(SOLID_FILL,BLUE);
	       bar(p[2].ppx1[i]+1,p[2].ppy1[i]+1,p[2].ppx2[i]-1,p[2].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(BLUE);
	       pieslice((p[2].ppx1[i]+p[2].ppx2[i])/2,(p[2].ppy1[i]+p[2].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==6)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=7&&i+1<=12)         //second part
	 {
	    p[2].ppx1[i]=290;
	    p[2].ppx2[i]=320;
	    p[2].ppy1[i]=290+y;
	    p[2].ppy2[i]=312+y;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    y+=22;
	    if(i+1==11)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[2].ppx1[i]+p[2].ppx2[i])/2-4,(p[2].ppy1[i]+p[2].ppy2[i])/2-10,"*");
	    }
	    if(i+1==12)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=13&&i+1<=15)          //third part
	 {
	    p[2].ppx1[i]=290-x;
	    p[2].ppx2[i]=320-x;
	    p[2].ppy1[i]=422;
	    p[2].ppy2[i]=450;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    x+=30;
	    if(i+1==15)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=16&&i+1<=21)     // fourth part
	 {
	    p[2].ppx1[i]=230;
	    p[2].ppx2[i]=260;
	    p[2].ppy1[i]=400-y;
	    p[2].ppy2[i]=422-y;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    y+=22;
	    if(i+1==16)
	    {
	       setfillstyle(SOLID_FILL,GREEN);
	       bar(p[2].ppx1[i]+1,p[2].ppy1[i]+1,p[2].ppx2[i]-1,p[2].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[2].ppx1[i]+p[2].ppx2[i])/2,(p[2].ppy1[i]+p[2].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==21)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=22&&i+1<=27)     //fifth part
	 {
	    p[2].ppx1[i]=208-x;
	    p[2].ppx2[i]=230-x;
	    p[2].ppy1[i]=260;
	    p[2].ppy2[i]=290;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    x+=22;
	    if(i+1==26)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[2].ppx1[i]+p[2].ppx2[i])/2-4,(p[2].ppy1[i]+p[2].ppy2[i])/2-10,"*");
	    }
	    if(i+1==27)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=28&&i+1<=30)  //sixth part
	 {
	    p[2].ppx1[i]=70;
	    p[2].ppx2[i]=98;
	    p[2].ppy1[i]=260-y;
	    p[2].ppy2[i]=290-y;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    y+=30;
	    if(i+1==30)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=31&&i+1<=36)      //seventh part
	 {
	    p[2].ppx1[i]=98+x;
	    p[2].ppx2[i]=120+x;
	    p[2].ppy1[i]=200;
	    p[2].ppy2[i]=230;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    x+=22;
	    if(i+1==31)
	    {
	       setfillstyle(SOLID_FILL,RED);
	       bar(p[2].ppx1[i]+1,p[2].ppy1[i]+1,p[2].ppx2[i]-1,p[2].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[2].ppx1[i]+p[2].ppx2[i])/2,(p[2].ppy1[i]+p[2].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==36)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=37&&i+1<=42)    //eigth part
	 {
	    p[2].ppx1[i]=230;
	    p[2].ppx2[i]=260;
	    p[2].ppy1[i]=178-y;
	    p[2].ppy2[i]=200-y;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    y+=22;
	    if(i+1==41)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[2].ppx1[i]+p[2].ppx2[i])/2-4,(p[2].ppy1[i]+p[2].ppy2[i])/2-10,"*");
	    }
	    if(i+1==42)
	    {
	      y=0;
	    }
	 }
	 else if(i+1>=43&&i+1<=45)      // ninth part
	 {
	    p[2].ppx1[i]=230+x;
	    p[2].ppx2[i]=260+x;
	    p[2].ppy1[i]=40;
	    p[2].ppy2[i]=68;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    x+=30;
	    if(i+1==45)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=46&&i+1<=51) //tenth part
	 {
	    p[2].ppx1[i]=290;
	    p[2].ppx2[i]=320;
	    p[2].ppy1[i]=68+y;
	    p[2].ppy2[i]=90+y;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    y+=22;
	    if(i+1==46)
	    {
	       setfillstyle(SOLID_FILL,YELLOW);
	       bar(p[2].ppx1[i]+1,p[2].ppy1[i]+1,p[2].ppx2[i]-1,p[2].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[2].ppx1[i]+p[2].ppx2[i])/2,(p[2].ppy1[i]+p[2].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==51)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=52&&i+1<=57)    //eleventh part
	 {
	    p[2].ppx1[i]=320+x;
	    p[2].ppx2[i]=342+x;
	    p[2].ppy1[i]=200;
	    p[2].ppy2[i]=230;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    x+=22;
	    if(i+1==56)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[2].ppx1[i]+p[2].ppx2[i])/2-4,(p[2].ppy1[i]+p[2].ppy2[i])/2-10,"*");
	    }
	    if(i+1==57)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=58&&i+1<=59)      //twelveth part
	 {
	    p[2].ppx1[i]=452;
	    p[2].ppx2[i]=480;
	    p[2].ppy1[i]=200+y;
	    p[2].ppy2[i]=230+y;
	    rectangle(p[2].ppx1[i],p[2].ppy1[i],p[2].ppx2[i],p[2].ppy2[i]);
	    y+=30;
	    if(i+1==59)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=60&&i+1<=65)     //thirteenth part
	 {
	    p[2].ppx1[i]=430-x;
	    p[2].ppx2[i]=452-x;
	    p[2].ppy1[i]=230;
	    p[2].ppy2[i]=260;
	    setfillstyle(SOLID_FILL,BLUE);
	    bar(430-x+1,230+1,452-x-1,260-1);
	    x+=22;
	    if(i+1==65)
	    {
	       x=0;
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
	       outtextxy(440,235,"<--");
	    }
	 }
     }
  }
  else if(col==YELLOW)
  {
     for(i=0;i<66;i++)	//yellow part
     {
	 if(i+1>=1&&i+1<=6) //first part
	 {
	    p[3].ppx1[i]=290;
	    p[3].ppx2[i]=320;
	    p[3].ppy1[i]=68+y;
	    p[3].ppy2[i]=90+y;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    y+=22;
	    if(i+1==6)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=7&&i+1<=12)    //second part
	 {
	    p[3].ppx1[i]=320+x;
	    p[3].ppx2[i]=342+x;
	    p[3].ppy1[i]=200;
	    p[3].ppy2[i]=230;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    x+=22;
	    if(i+1==11)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[3].ppx1[i]+p[3].ppx2[i])/2-4,(p[3].ppy1[i]+p[3].ppy2[i])/2-10,"*");
	    }
	    if(i+1==12)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=13&&i+1<=15)      //third part
	 {
	    p[3].ppx1[i]=452;
	    p[3].ppx2[i]=480;
	    p[3].ppy1[i]=200+y;
	    p[3].ppy2[i]=230+y;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    y+=30;
	    if(i+1==15)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=16&&i+1<=21)        //fourth part
	 {
	    p[3].ppx1[i]=430-x;
	    p[3].ppx2[i]=452-x;
	    p[3].ppy1[i]=260;
	    p[3].ppy2[i]=290;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    x+=22;
	    if(i+1==16)
	    {
	       setfillstyle(SOLID_FILL,BLUE);
	       bar(p[3].ppx1[i]+1,p[3].ppy1[i]+1,p[3].ppx2[i]-1,p[3].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[3].ppx1[i]+p[3].ppx2[i])/2,(p[3].ppy1[i]+p[3].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==21)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=22&&i+1<=27)         //fifth part
	 {
	    p[3].ppx1[i]=290;
	    p[3].ppx2[i]=320;
	    p[3].ppy1[i]=290+y;
	    p[3].ppy2[i]=312+y;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    y+=22;
	    if(i+1==26)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[3].ppx1[i]+p[3].ppx2[i])/2-4,(p[3].ppy1[i]+p[3].ppy2[i])/2-10,"*");
	    }
	    if(i+1==27)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=28&&i+1<=30)          //sixth part
	 {
	    p[3].ppx1[i]=290-x;
	    p[3].ppx2[i]=320-x;
	    p[3].ppy1[i]=422;
	    p[3].ppy2[i]=450;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    x+=30;
	    if(i+1==30)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=31&&i+1<=36)     // seventh part
	 {
	    p[3].ppx1[i]=230;
	    p[3].ppx2[i]=260;
	    p[3].ppy1[i]=400-y;
	    p[3].ppy2[i]=422-y;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    y+=22;
	    if(i+1==31)
	    {
	       setfillstyle(SOLID_FILL,GREEN);
	       bar(p[3].ppx1[i]+1,p[3].ppy1[i]+1,p[3].ppx2[i]-1,p[3].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[3].ppx1[i]+p[3].ppx2[i])/2,(p[3].ppy1[i]+p[3].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==36)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=37&&i+1<=42)     //eigth part
	 {
	    p[3].ppx1[i]=208-x;
	    p[3].ppx2[i]=230-x;
	    p[3].ppy1[i]=260;
	    p[3].ppy2[i]=290;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    x+=22;
	    if(i+1==41)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[3].ppx1[i]+p[3].ppx2[i])/2-4,(p[3].ppy1[i]+p[3].ppy2[i])/2-10,"*");
	    }
	    if(i+1==42)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=43&&i+1<=45)  //ninth part
	 {
	    p[3].ppx1[i]=70;
	    p[3].ppx2[i]=98;
	    p[3].ppy1[i]=260-y;
	    p[3].ppy2[i]=290-y;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    y+=30;
	    if(i+1==45)
	    {
	       y=0;
	    }
	 }
	 else if(i+1>=46&&i+1<=51)      //tenth part
	 {
	    p[3].ppx1[i]=98+x;
	    p[3].ppx2[i]=120+x;
	    p[3].ppy1[i]=200;
	    p[3].ppy2[i]=230;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    x+=22;
	    if(i+1==46)
	    {
	       setfillstyle(SOLID_FILL,RED);
	       bar(p[3].ppx1[i]+1,p[3].ppy1[i]+1,p[3].ppx2[i]-1,p[3].ppy2[i]-1);
	       setfillstyle(SOLID_FILL,9);
	       setcolor(9);
	       pieslice((p[3].ppx1[i]+p[3].ppx2[i])/2,(p[3].ppy1[i]+p[3].ppy2[i])/2,0,360,5);
	       setcolor(WHITE);
	    }
	    if(i+1==51)
	    {
	      x=0;
	    }
	 }
	 else if(i+1>=52&&i+1<=57)    //eleventh part
	 {
	    p[3].ppx1[i]=230;
	    p[3].ppx2[i]=260;
	    p[3].ppy1[i]=178-y;
	    p[3].ppy2[i]=200-y;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    y+=22;
	    if(i+1==56)
	    {
	       settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	       outtextxy((p[3].ppx1[i]+p[3].ppx2[i])/2-4,(p[3].ppy1[i]+p[3].ppy2[i])/2-10,"*");
	    }
	    if(i+1==57)
	    {
	      y=0;
	    }
	 }
	 else if(i+1>=58&&i+1<=59)      //twelveth part
	 {
	    p[3].ppx1[i]=230+x;
	    p[3].ppx2[i]=260+x;
	    p[3].ppy1[i]=40;
	    p[3].ppy2[i]=68;
	    rectangle(p[3].ppx1[i],p[3].ppy1[i],p[3].ppx2[i],p[3].ppy2[i]);
	    x+=30;
	    if(i+1==45)
	    {
	       x=0;
	    }
	 }
	 else if(i+1>=60&&i+1<=65)     //thirteenth part
	 {
	     p[3].ppx1[i]=260;
	     p[3].ppx2[i]=290;
	     p[3].ppy1[i]=68+y;
	     p[3].ppy2[i]=90+y;
	     setfillstyle(SOLID_FILL,YELLOW);
	     bar(260+1,68+y+1,290-1,90+y-1);
	    y+=22;
	    if(i+1==65)
	    {
	       y=0;
	       settextstyle(TRIPLEX_FONT,VERT_DIR,0);
	       outtextxy(265,45,"<--");
	    }
	 }
     }
  }
}

int ludo::placement(int mve)
{
   int hiT=0,hit_count=0,one,two,i,j;

   for(i=0;i<4;)
   {
      if(p[i].pth_col!=pth_col)
      {
	for(j=0;j<4;j++)
	{
	   if((p[i].pp[j]<59&&p[i].pp[j]!=-1)&&(ppx1[pp[mve]]==p[i].ppx1[p[i].pp[j]]&&ppy1[pp[mve]]==p[i].ppy1[p[i].pp[j]]))
	   {
	       if((pp[mve]!=0)&&(pp[mve]!=10)&&(pp[mve]!=15)&&(pp[mve]!=25)&&(pp[mve]!=30)&&(pp[mve]!=40)&&(pp[mve]!=45)&&(pp[mve]!=55))
	       {
		  hiT++;
		  one=i;
		  two=j;
	       }
	   }
	}
      }
      else
      {
	for(j=0;j<4;j++)
	{
	   if(pp[j]==-1)
	   {
	       start_placement(j);
	   }
	   else if(pp[j]==65)
	   {
	       posX[j]=510+((j+1)*20);
	       posY[j]= 80+((i+1)*50);
	       setcolor(8);
	       arc(posX[j],posY[j],0,180,8);
	       line(posX[j]-8,posY[j],posX[j],posY[j]+10);
	       line(posX[j]+8,posY[j],posX[j],posY[j]+10);
	       setfillstyle(SOLID_FILL,p[i].pth_col);
	       floodfill(posX[j],posY[j],8);
	       setfillstyle(SOLID_FILL,8);
	       pieslice(posX[j],posY[j]-5,0,360,2);
	   }
	}
      }
      i++;
      if(play_num==2&&(p[i].pth_col==GREEN||p[i].pth_col==YELLOW))
      {
	 i++;
      }
   }

   if(hiT==1&&pp[two]<65)
   {
      p[one].pp[two]=-1;
      p[one].start_placement(two);
   }

   p[0].path(RED);
   p[1].path(GREEN);
   p[2].path(BLUE);
   p[3].path(YELLOW);

   for(int m=0;m<4;)
   {
      for(int n=0;n<4;n++)
      {
	 hit_count=0;
	 if(p[m].pp[n]!=-1&&p[m].pp[n]<65)
	 {
	    for(i=0;i<4;)
	    {
	       for(j=0;j<4;j++)
	       {
		  if((p[m].ppx1[p[m].pp[n]]==p[i].ppx1[p[i].pp[j]]&&p[m].ppy1[p[m].pp[n]]==p[i].ppy1[p[i].pp[j]]))
		  {
		     hit_count++;
		  }
	       }
	       i++;
	       if(play_num==2&&(p[i].pth_col==GREEN||p[i].pth_col==YELLOW))
	       {
			i++;
	       }
	    }
	 }

	 if(hit_count==1&&(p[m].pp[n]!=-1&&p[m].pp[n]<=65))
	 {
		p[m].posX[n]=(p[m].ppx1[p[m].pp[n]]+p[m].ppx2[p[m].pp[n]])/2;
		p[m].posY[n]=(p[m].ppy1[p[m].pp[n]]+p[m].ppy2[p[m].pp[n]])/2;
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,p[m].pth_col);
		pieslice(p[m].posX[n],p[m].posY[n]+5,60,120,16);
		setcolor(8);
		setfillstyle(SOLID_FILL,8);
		pieslice(p[m].posX[n],p[m].posY[n]-5,0,360,2);
	 }
	 else if(hit_count>=2&&(p[m].pp[n]!=-1&&p[m].pp[n]<65))
	 {
		p[m].posX[n]=((p[m].ppx1[p[m].pp[n]]+p[m].ppx2[p[m].pp[n]])/2)-5+(m*3);
		p[m].posY[n]=((p[m].ppy1[p[m].pp[n]]+p[m].ppy2[p[m].pp[n]])/2)-4+(n*4);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,p[m].pth_col);
		pieslice(p[m].posX[n],p[m].posY[n]+5,60,120,12);
		setcolor(8);
		setfillstyle(SOLID_FILL,8);
		pieslice(p[m].posX[n],p[m].posY[n]-5,0,360,1);
	 }
      }
      m++;
      if(play_num==2&&(p[m].pth_col==GREEN||p[m].pth_col==YELLOW))
      {
	 m++;
      }
   }

   if(hiT==1)
   {
      return hiT;
   }
   else
      return 0;
}

void ludo::player()
{
   lb:
   if(pp[0]==65&&pp[1]==65&&pp[2]==65&&pp[3]==65)
   {
      for(int check=0;check<=win;check++)
      {
	  if(winner[check]==pth_col)
	  {
	     return;
	  }
      }
      winner[win]=pth_col;
      win++;
      return;
   }

   int d=0,i,hit=0,hul=0,sum=0;

   char ch;
   if(arrow()==26)
   {
     closegraph();
     exit(0);
   }
   d=dice();
   for(i=0;i<4;i++)
   {
      if(pp[i]<=65)
      {
      if((pp[i]==65)||((d+pp[i])>65)||(pp[i]==-1&&d!=6))
      {
	move[i]=0;
      }
      else
      {
	move[i]=1;
	sum++;
      }
      }
   }

   if(sum==0)
   {
     if(d==6)
     {
	goto lb;
     }
     return;
   }
   else if(sum==1)
   {
     for(i=0;i<4;i++)
     {
	if(move[i]==1)
	{
	   if(pp[i]==-1)
	   {
	     if(pth_col==RED)
	     {
		setfillstyle(SOLID_FILL,6);
		bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	     }
	     else if(pth_col==GREEN)
	     {
		setfillstyle(SOLID_FILL,10);
		bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	     }
	     else if(pth_col==BLUE)
	     {
		setfillstyle(SOLID_FILL,3);
		bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	     }
	     else if(pth_col==YELLOW)
	     {
		setfillstyle(SOLID_FILL,7);
		bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	     }
	     pp[i]=0;
	   }
	   else
	   {
	     setfillstyle(SOLID_FILL,9);
	     bar(ppx1[pp[i]],ppy1[pp[i]],ppx2[pp[i]],ppy2[pp[i]]);
	     if(pp[i]+d==65)
	     {
	       hul=1;
	     }
	     pp[i]+=d;
	     setfillstyle(SOLID_FILL,9);
	     bar(ppx1[pp[i]],ppy1[pp[i]],ppx2[pp[i]],ppy2[pp[i]]);
	   }
	   hit=placement(i);
	}
     }
   }
   else
   {
     if(move[0])
     {
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(posX[0]-8,posY[0]-8,"a");
     }
     if(move[1])
     {
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(posX[1]-8,posY[1]-8,"w");
     }
     if(move[2])
     {
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(posX[2]-8,posY[2]-8,"s");
     }
     if(move[3])
     {
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(posX[3]-8,posY[3]-10,"d");
     }
     ch=getch();
     if(ch!='a'&&ch!='w'&&ch!='s'&&ch!='d'||((move[0]!=1&&ch=='a')||(move[1]!=1&&ch=='w')||(move[2]!=1&&ch=='s')||(move[3]!=1&&ch=='d')))
     {
	if(move[0])
	{
	  ch='a';
	}
	else if(move[1])
	{
	  ch='w';
	}
	else if(move[2])
	{
	  ch='s';
	}
	else if(move[3])
	{
	  ch='d';
	}
     }

     for(i=0;i<4;i++)
     {
	if(pp[i]==-1&&move[i]==1)
	{
	   if(pth_col==RED)
	   {
	      setfillstyle(SOLID_FILL,6);
	      bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	   }
	   else if(pth_col==GREEN)
	   {
	      setfillstyle(SOLID_FILL,10);
	      bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	   }
	   else if(pth_col==BLUE)
	   {
	      setfillstyle(SOLID_FILL,3);
	      bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	   }
	   else if(pth_col==YELLOW)
	   {
	      setfillstyle(SOLID_FILL,7);
	      bar(sx[i]-15,sy[i]-15,sx[i]+15,sy[i]+15);
	   }
	}
	else if(move[i]==1)
	{
	  setfillstyle(SOLID_FILL,9);
	  bar(ppx1[pp[i]],ppy1[pp[i]],ppx2[pp[i]],ppy2[pp[i]]);
	}
     }

     if(ch=='a')
     {
	if(pp[0]==-1)
	   pp[0]=0;
	else
	{
	   if(pp[0]+d==65)
	   {
	     hul=1;
	   }
	   pp[0]+=d;
	   setfillstyle(SOLID_FILL,9);
	   bar(ppx1[pp[0]],ppy1[pp[0]],ppx2[pp[0]],ppy2[pp[0]]);
	}
	hit=placement(0);
     }
     else if(ch=='w')
     {
	if(pp[1]==-1)
	   pp[1]=0;
	else
	{
	   if(pp[1]+d==65)
	   {
	     hul=1;
	   }
	   pp[1]+=d;
	   setfillstyle(SOLID_FILL,9);
	   bar(ppx1[pp[1]],ppy1[pp[1]],ppx2[pp[1]],ppy2[pp[1]]);
	}
	hit=placement(1);
     }
     else if(ch=='s')
     {
	if(pp[2]==-1)
	   pp[2]=0;
	else
	{
	   if(pp[2]+d==65)
	   {
	     hul=1;
	   }
	   pp[2]+=d;
	   setfillstyle(SOLID_FILL,9);
	   bar(ppx1[pp[2]],ppy1[pp[2]],ppx2[pp[2]],ppy2[pp[2]]);
	}
	hit=placement(2);
     }
     else if(ch=='d')
     {
	if(pp[3]==-1)
	   pp[3]=0;
	else
	{
	   if(pp[3]+d==65)
	   {
	     hul=1;
	   }
	   pp[3]+=d;
	   setfillstyle(SOLID_FILL,9);
	   bar(ppx1[pp[3]],ppy1[pp[3]],ppx2[pp[3]],ppy2[pp[3]]);
	}
	hit=placement(3);
     }
   }

   if(d==6||hit==1||hul==1)
   {
      goto lb;
   }
}

char ludo::arrow()
{
  if(pth_col==RED)
  {
	while(!kbhit())
	{
	   setfillstyle(SOLID_FILL,RED);
	   setcolor(RED);
	   rectangle(0,50,30,65);
	   line(30,45,30,70);
	   line(30,45,40,57);
	   line(30,70,40,57);
	   floodfill(2,52,RED);
	   floodfill(32,50,RED);
	   setcolor(WHITE);
	   delay(20);
	   setfillstyle(SOLID_FILL,9);
	   bar(0,40,40,70);
	   delay(10);
	}return getch();
  }
  else if(pth_col==GREEN)
  {
	while(!kbhit())
	{
	   setfillstyle(SOLID_FILL,GREEN);
	   setcolor(GREEN);
	   rectangle(0,290,30,305);
	   line(30,285,30,310);
	   line(30,285,40,297);
	   line(30,310,40,297);
	   floodfill(2,292,GREEN);
	   floodfill(32,290,GREEN);
	   setcolor(WHITE);
	   delay(20);
	   setfillstyle(SOLID_FILL,9);
	   bar(0,280,40,310);
	   delay(10);
	}return getch();
  }
  else if(pth_col==BLUE)
  {
	while(!kbhit())
	{
	   setfillstyle(SOLID_FILL,BLUE);
	   setcolor(BLUE);
	   rectangle(520,310,550,325);
	   line(520,305,520,330);
	   line(520,305,510,317);
	   line(520,330,510,317);
	   floodfill(522,312,BLUE);
	   floodfill(518,310,BLUE);
	   setcolor(WHITE);
	   delay(20);
	   setfillstyle(SOLID_FILL,9);
	   bar(505,300,560,330);
	   delay(10);
	}return getch();
  }
  else if(pth_col==YELLOW)
  {
	while(!kbhit())
	{
	   setfillstyle(SOLID_FILL,YELLOW);
	   setcolor(YELLOW);
	   rectangle(520,50,550,65);
	   line(520,45,520,70);
	   line(520,45,510,57);
	   line(520,70,510,57);
	   floodfill(522,52,YELLOW);
	   floodfill(518,50,YELLOW);
	   setcolor(WHITE);
	   delay(20);
	   setfillstyle(SOLID_FILL,9);
	   bar(505,45,560,70);
	   delay(10);
	}return getch();
  }
  return 0;
}

int ludo::dice()         // game dice
{
  int d=0;
  {
   while(d<1||d>6)
   {
      time_t t;
      srand((unsigned) time(&t));
      d=rand()%10;
   }
   setcolor(7);
   setfillstyle(SOLID_FILL,WHITE);
   rectangle(260-1,230-1,290+1,260+1);
   bar(260,230,290,260);
   setfillstyle(SOLID_FILL,9);
   switch(d)
   {
     case 1:
	    circle(275,245,3);
	    floodfill(275,245,7);
	    break;
     case 2:
	    circle(270,240,3);
	    floodfill(270,240,7);
	    circle(280,250,3);
	    floodfill(280,250,7);
	    break;
     case 3:
	    circle(268,238,3);
	    floodfill(268,238,7);
	    circle(276,246,3);
	    floodfill(276,246,7);
	    circle(284,254,3);
	    floodfill(284,254,7);
	    break;
     case 4:
	    circle(270,240,3);
	    floodfill(270,240,7);
	    circle(280,240,3);
	    floodfill(280,240,7);
	    circle(270,250,3);
	    floodfill(270,250,7);
	    circle(280,250,3);
	    floodfill(280,250,7);
	    break;
     case 5:
	    circle(268,238,3);
	    floodfill(268,238,7);
	    circle(284,238,3);
	    floodfill(284,238,7);
	    circle(276,246,3);
	    floodfill(276,246,7);
	    circle(284,254,3);
	    floodfill(284,254,7);
	    circle(268,254,3);
	    floodfill(268,254,7);
	    break;
     case 6:
	    circle(268,240,3);
	    floodfill(268,240,7);
	    circle(276,240,3);
	    floodfill(276,240,7);
	    circle(268,250,3);
	    floodfill(268,250,7);
	    circle(276,250,3);
	    floodfill(276,250,7);
	    circle(284,250,3);
	    floodfill(284,250,7);
	    circle(284,240,3);
	    floodfill(284,240,7);
	    break;
   };
   delay(5);
  }
  setcolor(WHITE);
  return d;
}

void ludo::start_pos(int px1,int py1,int px2,int py2,int px3,int py3,int px4,int py4)
{
	sx[0]=px1;   	sy[0]=py1;
	sx[1]=px2;	sy[1]=py2;
	sx[2]=px3;	sy[2]=py3;
	sx[3]=px4;	sy[3]=py4;
	for(int i=0;i<4;i++)
	{
	  move[i]=1;
	  pp[i]=-1;
	}
	start_placement(4);
}

void ludo:: start_placement(int num)
{
  if(num==4)
  {
    for(int k=0;k<4;k++)
    {
       posX[k]=sx[k];
       posY[k]=sy[k];
       setcolor(8);
       arc(posX[k],posY[k],0,180,8);
       line(posX[k]-8,posY[k],posX[k],posY[k]+10);
       line(posX[k]+8,posY[k],posX[k],posY[k]+10);
       setfillstyle(SOLID_FILL,pth_col);
       floodfill(posX[k],posY[k],8);
       setfillstyle(SOLID_FILL,8);
       pieslice(posX[k],posY[k]-5,0,360,2);
    }
  }
  else
  {
       posX[num]=sx[num];
       posY[num]=sy[num];
       setcolor(8);
       arc(posX[num],posY[num],0,180,8);
       line(posX[num]-8,posY[num],posX[num],posY[num]+10);
       line(posX[num]+8,posY[num],posX[num],posY[num]+10);
       setfillstyle(SOLID_FILL,pth_col);
       floodfill(posX[num],posY[num],8);
       setfillstyle(SOLID_FILL,8);
       pieslice(posX[num],posY[num]-5,0,360,2);
  }
}