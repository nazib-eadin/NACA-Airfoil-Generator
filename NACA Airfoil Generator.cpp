#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<windows.h>

int main()
 {
    int gd=DETECT,gm,error;
    int j;
    float i;
    int x,y,radius=70;
    char message[80];


    initwindow(1350,700);

    error = graphresult();

 if (error != grOk)

{
    printf("Graphics error occurred");
    printf("Press any key to halt:");
    getch();
    exit(1);
}

    x=getmaxx()/2;
    y=getmaxy()/2;


    //welcome screen


    setcolor(RED);
    settextstyle(1,HORIZ_DIR,6);
    outtextxy(x-300,y-300,"GRAPHICAL");
    delay(2000);
    outtextxy(x-450,y-200,"REPRESENTATION of");
    delay(2000);
    outtextxy(x-100,y-100,"ILS");
    delay(2000);
    setcolor(WHITE);
    outtextxy(x-450,y+200,"Press any key to continue.");
    getch();
    cleardevice();


    //layout


    graphdefaults();
    rectangle(x-200,y-300,x+200,y-270);
    outtextxy(x-140,21,"");
    setbkcolor(BLUE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1.5);
    outtextxy(x-180,y-295,"GRAPHICAL REPRESENTATION OF ILS");

    circle(x,y-70,100);

    setfillstyle(SOLID_FILL,BLUE);
    circle(x-160,y+140,radius);
    floodfill(x-150,y+140,WHITE);

    setfillstyle(SOLID_FILL,YELLOW);
    circle(x,y+140,radius);
    floodfill(x,y+140,WHITE);

    setfillstyle(SOLID_FILL,RED);
    circle(x+160,y+140,radius);
    floodfill(x+150,y+140,WHITE);

    setbkcolor(BLACK);
    setlinestyle(3,15,1);
    line(x,y-70,x,y-170);

    setlinestyle(3,15,1);
    line(x,y-70,x,y+30);

    setlinestyle(3,15,1);
    line(x,y-70,x-100,y-70);

    setlinestyle(3,15,1);
    line(x,y-70,x+100,y-70);



    // show string

for(i=10;i>=7;i--)

{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
    sprintf(message, "Aircraft aproaching:\t  %.1f  NM",i);
    outtextxy( 100, 100,message);
    delay(1000);
}

    //flashing circles with sound


   //outer marker

    graphdefaults();

    i=7;

for(j=1;j<19;j++)

{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
    sprintf(message, "Aircraft aproaching:\t  %3.1f\tNM",i);
    outtextxy( 100, 100,message);

    i=i-0.15;

    setfillstyle(SOLID_FILL,BLUE);
    circle(x-160,y+140,radius);
    floodfill(x-160,y+140,WHITE);

    Beep(400,250);
    delay(250);

    setfillstyle(SOLID_FILL,BLACK);
    circle(x-160,y+140,radius);
    floodfill(x-160,y+140,WHITE);
    delay(100);

}
    setfillstyle(SOLID_FILL,BLUE);
    circle(x-160,y+140,radius);
    floodfill(x-160,y+140,WHITE);

    graphdefaults();

    //middle marker

    i=4;

for(j=1;j<19;j++)

{
    i=i-0.15;

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
    sprintf(message, "Aircraft aproaching:\t  %3.1f\tNM",i);
    outtextxy( 100, 100,message);

    setfillstyle(SOLID_FILL,YELLOW);
    circle(x,y+140,radius);
    floodfill(x,y+140,WHITE);

    Beep(1400,300);
    delay(300);

    setfillstyle(SOLID_FILL,BLACK);
    circle(x,y+140,radius);
    floodfill(x,y+140,WHITE);
    delay(100);

    setfillstyle(SOLID_FILL,YELLOW);
    circle(x,y+140,radius);
    floodfill(x,y+140,WHITE);

    Beep(1400,100);
    delay(100);

    setfillstyle(SOLID_FILL,BLACK);
    circle(x,y+140,radius);
    floodfill(x,y+140,WHITE);
    delay(100);


}

    setfillstyle(SOLID_FILL,YELLOW);
    circle(x,y+140,radius);
    floodfill(x,y+140,WHITE);

    graphdefaults();


    //inner marker

    i=1000;

for(j=1;j<21;j++)

{
    i=i-50;

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
    sprintf(message, "Aircraft aproaching:  %.0fmetre",i);
    outtextxy( 100, 100,message);

    setfillstyle(SOLID_FILL,RED);
    circle(x+160,y+140,radius);
    floodfill(x+160,y+140,WHITE);

    Beep(2500,90);
    delay(90);

    setfillstyle(SOLID_FILL,BLACK);
    circle(x+160,y+140,radius);
    floodfill(x+160,y+140,WHITE);
    delay(90);

}

    setfillstyle(SOLID_FILL,RED);
    circle(x+160,y+140,radius);
    floodfill(x+160,y+140,WHITE);


    //

    cleardevice();

    settextstyle(0,HORIZ_DIR,6);
    outtextxy(x-250,y-300,"Congrats.");
    outtextxy(x-450,y-200,"LANDING SUCCESSFULL");
    settextstyle(0,HORIZ_DIR,4);
    outtextxy(x-450,y+200,"Press any key to replay.");

getch();
closegraph();
return 0;

}
