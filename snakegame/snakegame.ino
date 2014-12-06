#include <MeggyJrSimple.h>

int dir=270;  // possible values are 0, 90, 180, 270
int xapple=random(8); // apple variables
int yapple=random(8);
struct Point  // player dot coordinates
{
  int x;
  int y;
};
Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point snakeArray[64]= {p1, p2, p3};

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
   DrawPx(snakeArray[i].x, snakeArray[i].y, Green);
  }
}

void updateSnake()
{
  for (int i=marker-1; i>0; i--)
  {
    snakeArray[i]=snakeArray[i-1];
  }
}

void loop()  // runs over and over
              /*
              Draw snake
              Draw head
              DisplaySlate();
              delay();
              ClearSlate
              update the snake
              Check Buttons
              update direction if butoon is pressed
              update head based on direction
              correct for wrapping
              check to see if apple eaten
                if ture, spawn new apple
                increas marker by ONE
              
              */
{
  updateSnake();  // use to keep a green dot from appearing at bottom left
                  // corner when apple eaten
  Serial.print("x is ");
  Serial.println(snakeArray[0].x);
  Serial.print("y is ");
  Serial.println(snakeArray[0].y);
  Serial.println();
  drawSnake();
  DisplaySlate();
  delay(250);
  ClearSlate();
  
  //updateSnake();
   
  CheckButtonsPress();
  
  // code to expand snake from button
  /*if (Button_A)
  {
    marker++;
  }*/
    
  
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
    snakeArray[0].y++;
  }
  if (dir==90)
  {
    snakeArray[0].x++;
  }
  if (dir==180)
  {
    snakeArray[0].y--;
  }
  if (dir==270)
  {
    snakeArray[0].x--;
  }
  
  if (snakeArray[0].x>7)  // wrap arounds
  {
    snakeArray[0].x=0;
  }
  if (snakeArray[0].y>7)
  {
    snakeArray[0].y=0;
  }
  if (snakeArray[0].x<0)
  {
    snakeArray[0].x=7;
  }
  if (snakeArray[0].y<0)
  {
    snakeArray[0].y=7;
  }
  
  // apple code

DrawPx (xapple,yapple,Red);
  
 if (xapple==snakeArray[0].x)
 {
   if (yapple==snakeArray[0].y)
   {
     Tone_Start(ToneC6, 100);
     delay(200);
     xapple=random(8);
     yapple=random(8);
     marker++;
   }
 }
 
 /*if (xapple==snakeArray[0].x)
 {
   if (yapple==snakeArray[0].y)
   {
      marker++;
    }
 }*/
}
