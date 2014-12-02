#include <MeggyJrSimple.h>

int xplayer=3;  //corrdinates of player dot
int yplayer=4;
int dir=0;  // possible values are 0, 90, 180, 270
int xapple=random(8); // apple variables
int yapple=random(8);
struct Point
{
  int x;
  int y;
};
Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point snakeArray{64}= {p1, p2, p3};

int marker=3;
void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void drawSnake()
{
  for (int i=0; i<marker; i++)
  {
   DrawPx(snakeArray{i}.x, snakeArray{i}.y, Red)
  }
}

void loop()  // runs over and over
              /*
              Draw plaer
              DisplaySlate();
              Chck Buttons
              update direction if butoon is pressed
              update player based on direction
              correct for wrapping
              
              */
{
  Serial.print("x is ");
  Serial.println(xplayer);
  Serial.print("y is ");
  Serial.println(yplayer);
  Serial.println();
  DrawPx (xplayer,yplayer,Green);
  //DrawPx (xapple,yapple,Red);
  DisplaySlate();
  delay(100);
   
  CheckButtonsPress();
  
  if (Button_Up)  // changing directions
  {
    dir=0;
  }
  if (Button_Right)
    {
     dir=90;
    }
  if (Button_Down)
  {
   dir=180;
  }
  if (Button_Left)
  {
    dir=270;
  } 
  
  if (dir==0)  // contiued directions
  {
    yplayer++;
  }
  if (dir==90)
  {
    xplayer++;
  }
  if (dir==180)
  {
    yplayer--;
  }
  if (dir==270)
  {
    xplayer--;
  }
  
  if (xplayer>7)  // wrap arounds
  {
    xplayer=0;
  }
  if (yplayer>7)
  {
    yplayer=0;
  }
  if (xplayer<0)
  {
    xplayer=7;
  }
  if (yplayer<0)
  {
    yplayer=7;
  }
  
  // apple code
  if (xapple==xplayer)
  {
    if (yapple==yplayer)
    {
      xapple=random(8);
      yapple=random(8);
    }
  }
}
