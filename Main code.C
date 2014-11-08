/*
Topic- Curve Expert

Group members
Rajat Jain(10103571)
Rajul Kukreja(10103509)
Ankit garg(10103623)
Batch-: B6

*/
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<alloc.h>
#include<math.h>
#include<dos.h>

struct stu
{
float x,y;
struct stu *nxt;
}*start,*end,*s1,*e1;

float maxx,minx,maxy,miny,xmean,ymean;
int n,values[10];
int xaxis=0,yaxis=0;//x cord f y axis n y coord f x axis



void input(int i)
{
struct stu *temp;
while(i>0)
{
temp=(struct stu *)malloc(sizeof(struct stu));
scanf("%f %f",&temp->x,&temp->y);
temp->nxt=NULL;
if(start==NULL)
{
start=temp;
end=temp;
}

else
{
end->nxt=temp;
end=temp;
}

i--;
}
}

void output()
{

struct stu *temp=start;
while(temp!=NULL)
{
printf("%f\t%f\n",temp->x,temp->y);
temp=temp->nxt;
}
}

void sort()
{
struct stu *temp=start,*temp1;
float a,b;
while(temp->nxt!=NULL)
{
temp1=temp->nxt;
while(temp1!=NULL)
{
	if(temp->x>temp1->x)
	{
	a=temp->x;
	temp->x=temp1->x;
	temp1->x=a;
	b=temp->y;
	temp->y=temp1->y;
	temp1->y=b;
	}
temp1=temp1->nxt;
}
temp=temp->nxt;
}
}

void scanfile()
{
char x[20];
struct stu *temp;
FILE *fp;
float a,b;
printf("Enter the filename to be opened(with extension included):\n");
flushall();
gets(x);
fp=fopen(x,"r");
if((fp)==NULL)
{
printf("\nCANNOT OPEN FILE %s !!!!!!\n",x);
getch();
return;
}

start=end=NULL;

temp=(struct stu *)malloc(sizeof(struct stu));

while(fscanf(fp,"%f\t%f\n",&a,&b)!=EOF)
{
temp->x=a;
temp->y=b;
temp->nxt=NULL;
if(start==NULL)
{
start=temp;
end=temp;
n++;
}

else
{
end->nxt=temp;
end=temp;
n++;

}



temp=(struct stu *)malloc(sizeof(struct stu));
}
fcloseall();
sort();
}


void write()
{

char x[20];
struct stu *temp=start;
FILE *fp;
float a,b;
printf("Enter the filename to be opened(with extension included)\n");
flushall();
gets(x);
fp=fopen(x,"w");
if((fp)==NULL)
{
printf("\nCANNOT OPEN FILE %s !!!!!!\n",x);
return;
}

while(temp!=NULL)
{
fprintf(fp,"%f\t%f\n",temp->x,temp->y);
temp=temp->nxt;
}
fcloseall();
}


void endscreen()
{
int gd,gm,errorcode;
    clrscr();
    detectgraph(&gd,&gm);
    initgraph(&gd, &gm, "" );
     errorcode=graphresult();
    if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
    setcolor(12);
    setfillstyle(11,2);
    bar(0, 0, 640, 480);
    setfillstyle(SOLID_FILL,2);
    bar(50, 50, 590, 430);
    setfillstyle(1,14);
    bar(100, 100, 540, 380);
    settextstyle(5,0,5);
    outtextxy(getmaxx()/2-40,getmaxy()/2,"THANK YOU");
    getch();
closegraph();
exit(1);
}


void bounds()
{
struct stu *temp;
temp=start;
maxx=minx=start->x;
maxy=miny=start->y;
while(temp!=NULL)
{
if(temp->x<minx)
minx=temp->x;
if(temp->y<miny)
miny=temp->y;
if(temp->x>maxx)
maxx=temp->x;
if(temp->y>maxy)
maxy=temp->y;

temp=temp->nxt;
}
getch();
}


void startpg()
{
int gdriver = DETECT, gmode, errorcode;
 int midx2,midy2,midx, midy,i,n,m,xmove1,xmove2,ymove1,ymove2;
 int stangle = 45, endangle = 135;
   int radius = 100;
int no1=24,no2=453,no3=48,no4=467;
   int a=50,b=457;

		/* initialize graphics and local variables */
		initgraph(&gdriver, &gmode, " ");

		 /* read result of initialization */
		errorcode = graphresult();
		/* an error occurred */

		if (errorcode != grOk)
		{
		 printf("Graphics error: %d\n", grapherrormsg(errorcode));
		 printf("Press any key to halt:");
		 getch();
		 exit(1);
		}

 midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());
   midy-=150;
   midx-=120;
 midx2=midx+65,midy2=midy;

   n=5,m=6;
   for(i=0;i<30;i++)
   /* draw arc */
  { setcolor(n);
   arc(midx-90, midy, stangle-10, endangle+10, radius-40);
   setcolor(m);

   arc(midx2-90,midy+=2,stangle-10,endangle+10,radius-40);//INCREASING MIDY BY 2

  }
  setcolor(10);
  settextstyle(0,0,2);
  outtextxy(midx-120,midy2-30,"CurvExpert");

  xmove1=getmaxx()/4,ymove1=getmaxy()/2,xmove2=(getmaxx()/2)+130,ymove2=getmaxy()-130;
  settextstyle(0,0,1);
  setlinestyle(0,0,3);
   rectangle(0,0,632,479);
   rectangle(getmaxx()/32,getmaxy()-30,getmaxx()-27,getmaxy()-8);
   rectangle(xmove1,ymove1,xmove2,ymove2);
   xmove1+=20;ymove1+=10;
   outtextxy(xmove1,ymove1,"welcome to CurvExpert");
   ymove1+=20;
   outtextxy(xmove1,ymove1,"MADE BY:");
   ymove1+=20;
   outtextxy(xmove1,ymove1,"        ANKIT GARG" );
   ymove1+=20;
   outtextxy(xmove1,ymove1,"        RAJUL KUKREJA");
   ymove1+=20;
   outtextxy(xmove1,ymove1,"        RAJAT JAIN");
   for(i=0;i<=28;i++)
   {
   setfillstyle(1,15);
    bar(no1,no2,no3,no4);
    setcolor(WHITE);
    outtextxy(a,b,"PLZ WAIT");
    setfillstyle(1,0);
    bar(630,470,615,435);
    delay(150);
    setcolor(0);
    outtextxy(a,b,"PLZ WAIT");
    setfillstyle(1,0);
    bar(630,470,615,435);
   // setcolor(0);
   // line(42,452,42,468);
    no3+=20;
  //  no1+=21;
    a+=20;

   }
   setcolor(RED);
   outtextxy(220,457,"press any key to continue");
   delay(100);
  // }

getch();
closegraph();
flushall();
}


//------------------------------------------------------------------------

void drawxy(int x,int y)
{
int gd, gm, errorcode;

flushall();
clrscr();
     detectgraph(&gd,&gm);
    initgraph(&gd, &gm, "" );
    errorcode=graphresult();
    if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
flushall();
line(10,x,getmaxx()-10,x);
line(y,10,y,getmaxy()-10);


line(10,x,10,x-5);
line(10,x-5,5,x);
line(5,x,10,x+5);
line(10,x+5,10,x);

line(y-5,10,y+5,10);
line(y+5,10,y,5);
line(y,5,y-5,10);

line(getmaxx()-10,x-5,getmaxx()-10,x+5);
line(getmaxx()-10,x-5,getmaxx()-5,x);
line(getmaxx()-5,x,getmaxx()-10,x+5);

line(y-5,getmaxy()-10,y+5,getmaxy()-10);
line(y+5,getmaxy()-10,y,getmaxy()-5);
line(y,getmaxy()-5,y-5,getmaxy()-10);
flushall();
}



void plus(int x,int y)
{
flushall();
line(x,y,x+3,y);
line(x,y,x,y+3);
line(x,y,x-3,y);
line(x,y,x,y-3);
flushall();
}



void drawpts(int y,int x,float xfactr,float yfactr)//reverse xaxis n yaxis pts to make it easier
{
int j=0,q;
char a[10];
float i=0;
int k=x;
while(k>10)//-ve x axis added + sign as a mark f place in all points
{
k=k-20;
i-=xfactr;

flushall();
sprintf(a,"%.2f",i);

for(q=0;q<sizeof(a);q++)
{
if(a[q]=='0' && a[q+1]=='0')
{
a[q]='\0';
break;
}
}
if(j==0)
{
j=1;
outtextxy(k-(sizeof(a)*2),y+15,a);
}
else if(j==1)
{
j=0;
outtextxy(k-(sizeof(a)),y+5,a);
}
plus(k,y);
}
i=0;
k=x;

while(k<getmaxx()-10)//+ve x axis
{
k+=20;
i+=xfactr;
flushall();
sprintf(a,"%.2f",i);
for(q=0;q<sizeof(a);q++)
{
if(a[q]=='0' && a[q+1]=='0')
{
a[q]='\0';
break;
}
}

if(j==0)
{
j=1;
outtextxy(k-(sizeof(a)),y+5,a);
}
else if(j==1)
{
j=0;
outtextxy(k-(sizeof(a)),y+15,a);
}
plus(k,y);
}

i=0;
k=y;

while(k>10)//+ve y axis
{
k-=20;
i+=yfactr;
flushall();
sprintf(a,"%.2f",i);
for(q=0;q<sizeof(a);q++)
{
if(a[q]=='0' && a[q+1]=='0' && a[q+2]=='0')
{
a[q]='\0';
break;
}
}
outtextxy(x-(sizeof(a)*4)-10,k,a);
plus(x,k);
}

i=0;
k=y;

while(k<getmaxy()-10)//-ve y axis
{
k+=20;
i-=yfactr;
flushall();
sprintf(a,"%.2f",i);
for(q=0;q<sizeof(a);q++)
{
if(a[q]=='0' && a[q+1]=='0')
{
a[q]='\0';
break;
}
}
outtextxy(x-(sizeof(a)*4)-10,k,a);
plus(x,k);
}

}




void minmax()
{
int px=0,py=0,nx=0,ny=0; //no f +ve x &y , -ve x &y's
float a,b;
struct stu *temp;
flushall();
/*
a=ceil(maxy);
//printf("\n%f",a);
b=ceil(miny);
//printf("\n%f",b);
*/
//printf("maxy=%f\n",maxy);
xmean=(fabs(ceil(maxx))+fabs(ceil(minx)))/29;
ymean=(fabs(ceil(maxy))+fabs(ceil(miny)))/21;

//printf("\nymean=%f\n",ymean);
/*
if(xmean>1)
{
xmean=ceil(xmean);
}
else if(xmean<-1)
{
xmean=floor(xmean);
}
if(ymean>1)
{
xmean=ceil(ymean);
}
else if(ymean<-1)
{
ymean=floor(ymean);
}

*/
//getch();
//printf("\nxmean=%f,ymean=%f",xmean,ymean);
//getch();
temp=start;
while(temp!=NULL)
{
if(temp->x>=0)
px++;
if(temp->x<0)
nx++;
if(temp->y>=0)
py++;
if(temp->y<0)
ny++;
temp=temp->nxt;
}
if(ny==0)
{
py=19;
}
if(nx==0)
{
nx=nx+1;
}


//printf("\nnx=%d,ny=%d,px=%d,py=%d",nx,ny,px,py);

yaxis=10+(nx+1)*20;//-ve x * no f divisions
xaxis=10+(py+1)*20;//+ve y * no f divisions
//printf("\nxaxis=%d,yaxis=%d",xaxis,yaxis);
//getch();
flushall();
drawxy(xaxis,yaxis);//draw both axis
flushall();
//getch();
drawpts(xaxis,yaxis,xmean,ymean);


getch();
//closegraph();


}



//------------------------------------------------------------------------
/*
void changelist()
{
struct stu *t1,*temp;
s1=e1=NULL;
while(temp!=NULL)
{
t1=(struct stu *)malloc(sizeof(struct stu));
t1->x=floor(temp->x*20/xmean);
t1->y=floor(temp->y*20/ymean);
t1->nxt=NULL;
if(s1==NULL)
{
s1=t1;
e1=t1;
}

else
{
e1->nxt=t1;
e1=t1;
}

temp=temp->nxt;
}


}


*/
void plotpts()
{
float a,b;
int i,j;
struct stu *t1;
a=20/xmean;
b=20/ymean;
t1=start;
setfillstyle(1,4);
setcolor(4)   ;

while(t1!=NULL)
{  delay(200);
i=(t1->x)*a;
j=(t1->y)*b;
pieslice(yaxis+i,xaxis-j,0,360,3);
t1=t1->nxt;
}
getch();
}

void curve()
{
float xline_val,yline_val,x1,y1,x2,y2;
struct stu *temp;
setcolor(15);
			xline_val=start->x/xmean;
			xline_val*=20;
			yline_val=start->y/ymean;
			yline_val*=20;

			x1=yaxis+xline_val;
			y1=xaxis-yline_val;
			temp=start->nxt;
			while(temp!=NULL)
			{
			xline_val=temp->x/xmean;
			xline_val*=20;
			yline_val=temp->y/ymean;
			yline_val*=20;

			x2=yaxis+xline_val;
			y2=xaxis-yline_val;
			line(x1,y1,x2,y2);
			delay(200);
			 x1=x2;y1=y2;
temp=temp->nxt;
}

}









//------------------------------------------------------------------------

char menu()
{
char ch;
int gd,gm,errorcode;
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd, &gm, "" );
errorcode=graphresult();
if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
 setcolor(14);
 settextstyle(5,0,3);
 outtextxy(110,120,"1.Enter data of graph");
 outtextxy(110,150,"2.Append data of graph");
 outtextxy(110,180,"3.Display data");
 outtextxy(110,210,"4.Save data to a file");
 outtextxy(110,240,"5. Plot graph..");
 outtextxy(110,270,"6. Plot a BAR graph");
 outtextxy(110,300,"0.EXIT ");
outtextxy(110,330,"ENTER YOUR CHOICE");
 setcolor(1);
 setlinestyle(0,2,1);
 rectangle(88,111,438,363);
 setcolor(5);
 rectangle(90,109,436,365);
 setcolor(9);
 rectangle(92,107,434,367);
 ch=getch();
 flushall();
 fflush(stdin);
 closegraph();
return ch;
}


void menu1()
{
char ch;
int gd,gm,errorcode;
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd, &gm, "" );
errorcode=graphresult();
if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
 setcolor(14);
 settextstyle(5,0,3);
 outtextxy(110,120,"1.Enter data Manually");
 outtextxy(110,150,"2.Enter data from a file");
 outtextxy(110,180,"0.Return to previous menu ");
outtextxy(110,300,"ENTER YOUR CHOICE");
 setcolor(1);
 setlinestyle(0,2,1);
 rectangle(88,111,438,213);
 setcolor(5);
 rectangle(90,109,436,215);
 setcolor(9);
 rectangle(92,107,434,217);
 ch=getch();
 flushall();
 closegraph();
switch(ch)
{
case '1':
{

	printf("\n\n\t\tEnter no.of values u want 2 enter:\n");
	flushall();
	n=0;
	scanf("%d",&n);
	start=end=NULL;
	flushall();
	clrscr();
	printf("Enter %d values \n X\t Y\n",n) ;
	input(n);
	sort();
	bounds();
	return;
}
case '2':
{
	start=end=NULL;
	n=0;
	scanfile();
	sort();
	bounds();
	return;
}
case '0':
	return;
default:
printf("Wrong choice entered...\nReturning to main screen..");
getch();
return;

}
}
//-----------------------------------------------------------------------------
void ingraph()
{
 float o;
    int i;
    char a[10];
    int q;
    setbkcolor(9);
    settextstyle(4,0,5);
    outtextxy(getmaxx()/2-20,5,"BAR GRAPH");
    settextstyle(3,0,2);
    outtextxy(280,450,"X-AXIS");
    settextstyle(3,1,2);
    outtextxy(50,200,"Y-AXIS");
    line(100,60,100,400);
    line(100,400,500,400);
    o=0;
    for(i=100;i<500;i+=20)
{
	line(i,400,i,405);
}
 settextstyle(3,0,2);

    for(i=400;i>60;i-=20)
    {	line(100,i,95,i);

o+=ymean;
flushall();
sprintf(a,"%.2f",o);
for(q=0;q<sizeof(a);q++)
{
if(a[q]=='0' && a[q+1]=='0' && a[q+2]=='0')
{
a[q]='\0';
break;
}
}
outtextxy(100-(sizeof(a)*4)-10,i,a);


    }
    line(500,398,500,402);
    line(504,400,500,398);
    line(500,402,504,400);
    line(98,60,102,60);
    line(100,56,98,60);
    line(100,56,102,60);
}

void drawgraph()
{
    int i,j;
    setfillstyle(1,15);
    for(i=0,j=120;i<n;j+=20,i++)
     bar(j,(400-(20/ymean*values[i])),(j+10),400);
}


void bargraph()
{
    int d=0,m=0,i;
    clrscr();
    initgraph(&d,&m,"");
    printf("ENTER NUMBER OF OBJECTS::\n");
    scanf("%d",&n);
    printf("ENTER THE VALUES::\n");
    for(i=0;i<n;i++)
{
	scanf("%d",&values[i]);
if(i==0)
maxy=values[i];
else if(maxy<values[i])
maxy=values[i];
}

ymean=maxy/15;

   cleardevice();
    ingraph(ymean);
    drawgraph();
    getch();
    closegraph();
}

//-----------------------------------------------------------------------------

void main()
{
char c;
int i;
int gd, gm, errorcode;
struct stu *t1;
startpg();
while(1)
{
clrscr();
flushall();
c=menu();
//printf("1. enter new values manualy\n2. append the list\n3. load values from a file(deleting all previous values)\n4. display values\n5. write values to a file\n6. plot graph \n7. exit...\n8. get max n min values of list of points saved\n");
//scanf("%c",&c);
switch(c)
{
case '1':
{

menu1();
	/*printf("enter no.of values u want 2 enter");
	flushall();
	n=0;
	scanf("%d",&n);
	start=end=NULL;
	flushall();
	input(n);
	sort();
	bounds();*/
}
break;

case '2':
{
	printf("Enter the no of values you want to add to main list...\n");
	scanf("%d",&i);
	flushall();
	clrscr();
	printf("Enter %d values \n X\t Y\n",i);
	input(i);
	n=n+i;
	sort();
	bounds();
}
break;

case '3':
{
clrscr();
printf("\n\nPoints of graph you last saved was:\n");
printf("\n   X\t\t   Y\n");
output();
getch();
}
break;

case '4':
{
write();
clrscr();
printf("DATA SAVED TO SPECIFIED FILE...\nPress any key to continue..");
getch();
break;
}

case '5':
{
bounds();
if(start==NULL)
{
		flushall();
		clrscr();
		detectgraph(&gd,&gm);
		initgraph(&gd, &gm, "" );
		errorcode=graphresult();
		if(errorcode!=grOk)
		{
		printf("graphics error %d", grapherrormsg(errorcode));
		getch();
		exit(0);
		}
		setcolor(3);
		setfillstyle(4,5);
		bar(0, 0, 640, 480);
		settextstyle(4,0,3);
		outtextxy(150,110,"Please enter data first in the link list");
		getch();
		closegraph();
		continue;




}



//printf("maxy=%f,maxx=%f,minx=%f,miny=%f\n",maxy,maxx,minx,miny);

//drawxy(320,240);
//flushall();
/*clrscr();
     detectgraph(&gd,&gm);
   initgraph(&gd, &gm, "" );
   errorcode=graphresult();
    if(errorcode!=grOk)
    {
    printf("graphics error %d", grapherrormsg(errorcode));
    getch();
    exit(0);
    }
*/
//changelist();
flushall();
minmax();
flushall();
plotpts();
flushall();
curve();
getch();
closegraph();
/*t1=s1;
while(t1!=NULL)
{
printf("\n%f",t1->x);
t1=t1->nxt;
}*/
getch();

break;
}
case '6':
	bargraph();
break;

case '0':
endscreen();
break;

default:
		flushall();
		clrscr();
		detectgraph(&gd,&gm);
		initgraph(&gd, &gm, "" );
		errorcode=graphresult();
		if(errorcode!=grOk)
		{
		printf("graphics error %d", grapherrormsg(errorcode));
		getch();
		exit(0);
		}
		setcolor(3);
		setfillstyle(4,5);
		bar(0, 0, 640, 480);
		settextstyle(4,0,3);
		outtextxy(150,110,"wrong key entered...");
		outtextxy(200,150,"Please enter a valid key");
		getch();
		closegraph();
		continue;
}
}
}