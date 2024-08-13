
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<fstream>
#include<algorithm>
//#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<cmath>      
using namespace std;


void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); 
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}



//               we are going to define global variables



int a[65][50],d1,d2,d3,d4,d5,score=0;
int counter=0;
int highscore=0;
int highscore1=0;
int length=5;
int starthead=3;
int body1=4;	
char direction='q';
bool gameover=false;
int horitemp=24;
int verttemp=25;
int xfood1=10,xfood2=20,xfood3=30,xfood4=40,xfood5=50,yfood1=15,yfood2=15,yfood3=15,yfood4=15,yfood5=15,yfood6=15,xfood6=25;
int hori[60]={30,30,30,30,30};
int vert[60]={20,19,18,17,16};
bool endmenu=false;
bool runningstate=false,speedmenu=false,colormenu=false,difficultmenu=false;
char temp='d';
int speed=750;
int option=2;
int level=1;
bool timerbool1=true,timerbool2=true,timerbool3=true,timerbool4=true,timerbool5=true,timerbool6=true;
int counter1=0,counter2=0,counter3=0,counter4=0,counter5=0,counter6=0;
int timescale=60;
int difficulty=0;
void food();



void boolreset(){
counter1=0,counter2=0,counter3=0,counter4=0,counter5=0,counter6=0;
timerbool1=true,timerbool2=true,timerbool3=true,timerbool4=true,timerbool5=true,timerbool6=true;
}




//     this is the function through which everythihng is being displayed

void Display(){
   
if(gameover==false)
	{
	glClearColor(0.2, 0.2,
            0.2, 0);
    glClear(GL_COLOR_BUFFER_BIT);   
    }
    else
    {glClearColor(0.0, 0.0,
            0.0, 0);
    glClear(GL_COLOR_BUFFER_BIT); }
   
   
   //   these will draw the menus of different types
 	
    
	if(gameover==false&&endmenu==false&&runningstate==false)
	{
	   	if(speedmenu==true)
	   	 {
	   		
	   		
	   		int snape[7][31]={{1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  	  		  {1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  			  {1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
	  			  {0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
		     	   	  {1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1}};
		     	   	  
		for(int x=0;x<7;x++)
		{
			for( int  y=0;y<31;y++)    	   	  
	  		{
	  			if(snape[x][y]==1)
	  			DrawSquare( 80+y*15 , 500-x*15 ,15,colors[RED]);	
	  			else
	  			  DrawSquare( 80+y*15 , 500-x*15 ,15,colors[WHITE]);
	  		}
	  	}		
	   		
	   		
	   		
	   		
	   		 DrawString( 230, 300, "Press 1 for LOW", colors[RED]);	
	   		 DrawString( 230, 200, "PRESS 2 for MEDIUM", colors[RED]);
	   		 DrawString( 230, 150, "PRESS 3 for FAST", colors[RED]);
	   		 DrawString( 230, 100, "PRESS 4 for FASTEST", colors[RED]);
	   	 }
	   	else if(colormenu==true)
	   	{
	   		 
	   		 int snape[7][31]={{1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  	  		  {1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  			  {1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
	  			  {0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
		     	   	  {1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1}};
		     	   	  
		for(int x=0;x<7;x++)
		{
			for( int  y=0;y<31;y++)    	   	  
	  		{
	  			if(snape[x][y]==1)
	  			DrawSquare( 80+y*15 , 500-x*15 ,15,colors[RED]);	
	  			else
	  			  DrawSquare( 80+y*15 , 500-x*15 ,15,colors[WHITE]);
	  		}
	  	}		
	   		 
	   		 
	   		 
	   		 DrawString( 230, 300, "Press 1 for RED", colors[RED]);
	   		 DrawString( 230, 200, "PRESS 2 for BLUE", colors[BLUE]);
	   		 DrawString( 230, 150, "PRESS 3 for GREEN", colors[GREEN]);
	   		 DrawString( 230, 100, "PRESS 4 for YELLOW", colors[YELLOW]);
	   	}
	  	else  if(difficultmenu==true)
	  	{	
	  	int snape[7][31]={{1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  	  		  {1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  			  {1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
	  			  {0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
		     	   	  {1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1}};
		     	   	  
		for(int x=0;x<7;x++)
		{
			for( int  y=0;y<31;y++)    	   	  
	  		{
	  			if(snape[x][y]==1)
	  			DrawSquare( 80+y*15 , 500-x*15 ,15,colors[RED]);	
	  			else
	  			  DrawSquare( 80+y*15 , 500-x*15 ,15,colors[WHITE]);
	  		}
	  	}	
	  	 	 DrawString( 230, 350, "Press 1 for No Hurdles", colors[RED]);
	   		 DrawString( 230, 250, "PRESS 2 for Easy Hurdles", colors[RED]);
	   		 DrawString( 230, 200, "PRESS 3 for Hard Hurdles", colors[RED]);
	   	
	  	}
	  	else
	  	{
	  	int snape[7][31]={{1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  	  		  {1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  			  {1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
	  			  {0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
		     	   	  {1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1}};
		     	   	  
		for(int x=0;x<7;x++)
		{
			for( int  y=0;y<31;y++)    	   	  
	  		{
	  			if(snape[x][y]==1)
	  			DrawSquare( 80+y*15 , 500-x*15 ,15,colors[RED]);	
	  			else
	  			  DrawSquare( 80+y*15 , 500-x*15 ,15,colors[WHITE]);
	  		}
	  	}		
	  	
	  	DrawString( 180, 300, "Press 1 to Start Game", colors[RED]);
	  	DrawString( 180, 200, "PRESS 2 to Change Speed", colors[WHITE]);
	  	DrawString( 180, 150, "PRESS 3 to Change Difficulty", colors[WHITE]);
		DrawString( 180, 100, "PRESS 4 to Change Snake Colour", colors[WHITE]);
		DrawString( 180, 50, "PRESS ESC to QUIT", colors[RED]);
	 	}
	}
	else if(gameover==false&&endmenu==false&&runningstate==true)
	{
		 
		 
		 int snape[7][31]={{1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  	  		  {1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
	  			  {1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1},
	  			  {0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
	  			  {0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0},
		     	   	  {1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1}};
		     	   	  
		for(int x=0;x<7;x++)
		{
			for( int  y=0;y<31;y++)    	   	  
	  		{
	  			if(snape[x][y]==1)
	  			DrawSquare( 80+y*15 , 500-x*15 ,15,colors[RED]);	
	  			else
	  			  DrawSquare( 80+y*15 , 500-x*15 ,15,colors[WHITE]);
	  		}
	  	}		
	  	
		 
		 
		 
		 
		 
		 DrawString( 200, 250, "Press 1 to Continue", colors[WHITE]);
   		 DrawString( 200, 200, "PRESS 2 for NEW GAME", colors[RED]);
   		 DrawString( 200, 150, "PRESS 3 for MENU", colors[RED]);
   		 DrawString( 200, 100, "PRESS ESC to QUIT", colors[RED]);
   	}
   	else if(gameover==false&&endmenu==true)
   	{
   		 
   		 
	  		
	  		if(highscore1<highscore)
	  		DrawString( 170, 200, "NEW HIGH SCORE MADE!!!", colors[YELLOW]);
   		 
   		 DrawString( 200, 300, "!!!  GAME OVER   !!!", colors[RED]);
   		 DrawString( 200, 150, "Press 1 to PLAY AGAIN", colors[WHITE]);
   		 DrawString( 200, 100, "PRESS 2 for MENU", colors[WHITE]);
   		 DrawString( 200, 50, "PRESS ESC to QUIT", colors[WHITE]);
   	}
   	
   	
   	
   	//     this will draw the game while it is running
   	
   	
   		
    	else if(gameover==true)
    	{
    	for(int i=0;i<65;i++)
    	{
    		for(int j=0;j<50;j++)
    		{
    			if(a[i][j]==1)
    				DrawSquare( 0+i*10 , 0+j*10 ,10,colors[BLACK]);
    			switch(option)
    			{
    			case 1:
    			{
    				if(a[i][j]==0)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[WHITE]);
    				if(a[i][j]==4)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[50]);
    				if(a[i][j]==5)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[RED]);
    				if(a[i][j]==6)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[PINK]);
    				if(a[i][j]==7)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[YELLOW]);		
    				break;
    			}
    			case 2:
    			{
    				if(a[i][j]==0)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[WHITE]);
    				if(a[i][j]==4)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[50]);
    				if(a[i][j]==5)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[BLUE]);
    				if(a[i][j]==6)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[PINK]);	
    				if(a[i][j]==7)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[YELLOW]);
    				break;
    			}
    			case 3:
    			{
    				if(a[i][j]==0)
    				DrawSquare( 0+i*10 , 0+j*10 ,10,colors[WHITE]);
    				if(a[i][j]==4)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[50]);
    				if(a[i][j]==5)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[GREEN]);
    				if(a[i][j]==6)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[PINK]);	
    				if(a[i][j]==7)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[YELLOW]);	
    				break;
    			}	
    			case 4:
    			{
    				if(a[i][j]==0)
    				DrawSquare( 0+i*10 , 0+j*10 ,10,colors[WHITE]);
    				if(a[i][j]==4)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[50]);
    				if(a[i][j]==5)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[YELLOW]);
    				if(a[i][j]==6)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[PINK]);	
    				if(a[i][j]==7)
    					DrawSquare( 0+i*10 , 0+j*10 ,10,colors[YELLOW]);	
    				break;
    			}
    			}		
    		}
    	}	
    
    
    
    
    //   this draws the head of the snake
    
    
    for(int i=0;i<65;i++)
    {
    	for(int j=0;j<50;j++)
    	{
    		if(a[i][j]==3)	
    			DrawCircle( 5+i*10 , 5+j*10 ,8,colors[GRAY]);
    	}
    }
    
    
    
    
    //   this draws the lines for the obstacles
    
    switch(difficulty)
    {
    	case 0:
    	{break;}
    	case 1:
    	{
    		DrawLine(150, 150, 150, 350, 10, colors[WHITE]);
    		DrawLine(500, 150, 500, 350, 10, colors[WHITE]);
    		break;
    	}
    	case 2:
    	{
    		DrawLine(100-10, 200-5, 250-10, 200-5, 10, colors[WHITE]);	
    		DrawLine(100-10, 300-5, 250-10, 300-5, 10, colors[WHITE]);	
    		DrawLine(400-10, 200-5, 550, 200-5, 10, colors[WHITE]);		
    		DrawLine(400-10, 300-5, 550, 300-5, 10, colors[WHITE]);	
    		DrawLine(250-5, 50-10, 250-5, 200, 10, colors[WHITE]);	
    		DrawLine(250-5, 300-10, 250-5, 450, 10, colors[WHITE]);	
    		DrawLine(400-5, 50-10, 400-5, 200-10, 10, colors[WHITE]);	
    		DrawLine(400-5, 300-10, 400-5, 450, 10, colors[WHITE]);
    		break;	
    		
    
    
    }}
    
    
    
    }
    
    
    //this draws the strings and bars on the top
    
    
    if(gameover==true&&runningstate==true)
    {			
	string scoring="SCORE :";
	string highscoring="HIGHSCORE :";
	highscoring+=to_string(highscore);
	scoring += to_string(score);
    DrawString( 450,520 , scoring, colors[WHITE]);
     DrawString( 250,520 , highscoring, colors[WHITE]);	
    int barlength=(score/5)*2;
    
    DrawLine(20, 520,  20+barlength, 520,10, colors[RED]);
    DrawLine(20+barlength, 520, 140 , 520 ,10, colors[WHITE]);
    
    }
    
     
     
   glutSwapBuffers(); 
}







void NonPrintableKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT&& direction!='d'&&gameover==true ) {
	
	direction='a';						
      
      
    } else if (key == GLUT_KEY_RIGHT && direction!='a'&&gameover==true ) {
    
    	direction='d';
		
    } else if (key == GLUT_KEY_UP&& direction!='s'&&gameover==true ) {
        
        direction='w';
    }
    else if (key == GLUT_KEY_DOWN&& direction!='w'&&gameover==true ) {
	direction='s';
    }
     glutPostRedisplay();

}





// this function includes printable keys. It controls what keys do during the different states of the menus

void PrintableKeys(unsigned char key, int x, int y) {
    if (key == 'r' && runningstate==true&&gameover==true) {
        gameover=false;
        temp=direction;
        direction='q';
        endmenu=false;
        
    }
    
    
     if(gameover==false&&endmenu==false&&runningstate==false)
    {
   	if(speedmenu==true)
   	 {
   		 
   		 if(key==49)
        	{
			speed=1000;
			timescale=45;
			speedmenu=false;
		}
		if(key==50)
		{
			speed=650;
			timescale=69;
			speedmenu=false;
		}
		if(key==51)
		{
			speed=400;
			timescale=111;
			speedmenu=false;	
		}
		if(key==52)
		{
			speed=250;
			timescale=180;
			speedmenu=false;
		}	
		if (key == KEY_ESC)
		{
			speedmenu=false;
		}
   	 }
   	else if(colormenu==true)
   	{
   		 
   		 if(key==49)
        	{
			option=1;
			colormenu=false;
		}
		if(key==50)
		{
			option=2;
			colormenu=false;
		}
		if(key==51)
		{
			option=3;	
			colormenu=false;
		}
		if(key==52)
		{
			option=4;
			colormenu=false;
		}	
		if (key == KEY_ESC)
		{
			colormenu=false;
		}
   		 
   		 
   	}
  	else  if(difficultmenu==true)
  	{	 if(key==49)
        	{
			difficulty=0;
			difficultmenu=false;
		}
		if(key==50)
		{
			difficulty=1;
			difficultmenu=false;
		}	
		if(key==51)
		{
			difficulty=2;
			difficultmenu=false;
		}
		
		if (key == KEY_ESC)
		{
			difficultmenu=false;
		}}
  	  else
  	  {
	  
	  	if(key==49)
        	{
		highscore1=highscore;
		runningstate=true;	
		endmenu=false;
		
			hori[0]=30;
			hori[1]=30;
			hori[2]=30;
			hori[3]=30;
			hori[4]=30;
			food();
			vert[0]=20;
			vert[1]=19;
			vert[2]=18;
			vert[3]=17;
			vert[4]=16;
			boolreset();
			length=5;
			
				
		}
		if(key==50)
		{
			speedmenu=true;
		}
		if(key==51)
		{
			difficultmenu=true;	
		}
		if(key==52)
		{
			colormenu=true;
		}	
		if (key == KEY_ESC)
		{
			exit(1);
		}
 	  }
	}
	
	
	if(gameover==false&&endmenu==false&&runningstate==true)
	{
		if(key==49)
		{
			gameover=true;
			direction=temp;
		}
		if(key==50)
		{
			gameover=true;
			direction='d';
			score=0;
			food();
			hori[0]=30;
			hori[1]=30;
			hori[2]=30;
			hori[3]=30;
			hori[4]=30;
			boolreset();
			vert[0]=20;
			vert[1]=19;
			vert[2]=18;
			vert[3]=17;
			vert[4]=16;
			
			length=5;
		}
		if(key==51)
		{
			gameover=false;
			direction='q';
			score=0;
			runningstate=false;
			endmenu=false;
			food();
			hori[0]=30;
			hori[1]=30;
			hori[2]=30;
			hori[3]=30;
			hori[4]=30;
			boolreset();
			vert[0]=20;
			vert[1]=19;
			vert[2]=18;
			vert[3]=17;
			vert[4]=16;
			
			length=5;
		}
		if (key == KEY_ESC)
		{
			exit(1);
		}
		}
		else if(gameover==false&&endmenu==true)
   		{
			if(key==49)
			{
				gameover=true;
				direction='d';
				score=0;
				runningstate=true;
				food();
				hori[0]=30;
				hori[1]=30;
				hori[2]=30;
				hori[3]=30;
				hori[4]=30;
			boolreset();
				vert[0]=20;
				vert[1]=19;
				vert[2]=18;
				vert[3]=17;
				vert[4]=16;
			
				length=5;
   			}
   			if(key==50)
			{
				direction='q';
				endmenu=false;
				score=0;
				runningstate=false;
				gameover=false;
				food();
				hori[0]=30;
				hori[1]=30;
				hori[2]=30;
				hori[3]=30;
				hori[4]=30;
			boolreset();
				vert[0]=20;
				vert[1]=19;
				vert[2]=18;
				vert[3]=17;
				vert[4]=16;
			
				length=5;
			}
			if (key == KEY_ESC)
			{
				exit(1);
			}
   		}

    glutPostRedisplay();
}




//  these are two functions to write and read highscore of the game. I don't understand filehandling too good, so I got them from the internet. They work finr

void saveScore(){
ofstream outfile("highscore.txt");
outfile<<highscore;
outfile.close();
}
int readScore() {
ifstream infile("highscore.txt");
if(infile.is_open()){
infile>>highscore;
infile.close();
return highscore;
}
else{
return 0;
}
}






//This is the timer function and here I have implemented all my logic.

void Timer(int m) {
 

//for controlling the score and highscore relations	
	
	if(gameover==false)
		saveScore();
	
	
	if(gameover==true)
	{
	if(score>highscore)
		highscore=score; 
	for(int b=0;b<65;b++)
	{
			for(int j=0;j<50;j++)
			{
				if(b==0||b==64||j==0||j==49)
				a[b][j]=0;
				else
				a[b][j]=1;
			}
	}


// for printing food and also for making the snake's interaction with food and the respawning of eaten food



//food1
if((hori[0]==xfood1&&vert[0]==yfood1)||(timerbool1==false))
{
if(timerbool1==true)
{
	length++;
	score+=5;
	counter1=0;
}
	
timerbool1=false;
a[xfood1][yfood1]=1;
counter1++;
if(counter1%timescale==0)
{
do
{
xfood1=1+rand()%49;
yfood1=1+rand()%49;
}
while((((xfood1==9|| xfood1==10 ||xfood1==11 ||xfood1==12 ||xfood1==13 ||xfood1==14 ||xfood1==15 ||xfood1==16 ||xfood1==17 ||xfood1==18 ||xfood1==19 ||xfood1==20 ||xfood1==21 ||xfood1==22 ||xfood1==23 ||xfood1== 24)&&(yfood1==19||yfood1==29))||((xfood1==39|| xfood1==40 ||xfood1==41 ||xfood1==42 ||xfood1==43 ||xfood1==44 ||xfood1==45 ||xfood1==46 ||xfood1==47 ||xfood1==48 ||xfood1==49 ||xfood1==50 ||xfood1==51 ||xfood1==52 ||xfood1==53 ||xfood1== 54)&&(yfood1==19||yfood1==29))||((yfood1==4 ||yfood1==5 ||yfood1==6 ||yfood1==7 ||yfood1==8 ||yfood1==9 ||yfood1==10 ||yfood1==11 ||yfood1==12 ||yfood1==13 ||yfood1==14 ||yfood1==15 ||yfood1==16 ||yfood1==17 ||yfood1==18||yfood1== 19 )&&(xfood1==24||xfood1==39))||((yfood1==29 ||yfood1==30 ||yfood1==31 ||yfood1==32 ||yfood1==33 ||yfood1==34 ||yfood1==35 ||yfood1==36 ||yfood1==37 ||yfood1==38 ||yfood1==39 ||yfood1==40 ||yfood1==41 ||yfood1==42 ||yfood1==43||yfood1==44 )&&(xfood1==24||xfood1==39)))||((xfood1==15||xfood1==50)&&(yfood1==14||yfood1==15||yfood1==16||yfood1==17||yfood1==18||yfood1==19||yfood1==20||yfood1==21||yfood1==22||yfood1==23||yfood1==24||yfood1==25||yfood1==26||yfood1==27||yfood1==28||yfood1==29||yfood1==30||yfood1==31||yfood1==32||yfood1==33||yfood1==34)))	;
timerbool1=true;	
}
}
else
a[xfood1][yfood1]=6;	


	





//food2
	
if((hori[0]==xfood2&&vert[0]==yfood2)||(timerbool2==false))
{
if(timerbool2==true)
{
	length++;
	score+=5;
	counter2=0;
}
	
timerbool2=false;
a[xfood2][yfood2]=1;
counter2++;
if(counter2%timescale==0)
{
do
{
xfood2=1+rand()%49;
yfood2=1+rand()%49;
}
while((((xfood2==9|| xfood2==10 ||xfood2==11 ||xfood2==12 ||xfood2==13 ||xfood2==14 ||xfood2==15 ||xfood2==16 ||xfood2==17 ||xfood2==18 ||xfood2==19 ||xfood2==20 ||xfood2==21 ||xfood2==22 ||xfood2==23 ||xfood2== 24)&&(yfood2==19||yfood2==29))||((xfood2==39|| xfood2==40 ||xfood2==41 ||xfood2==42 ||xfood2==43 ||xfood2==44 ||xfood2==45 ||xfood2==46 ||xfood2==47 ||xfood2==48 ||xfood2==49 ||xfood2==50 ||xfood2==51 ||xfood2==52 ||xfood2==53 ||xfood2== 54)&&(yfood2==19||yfood2==29))||((yfood2==4 ||yfood2==5 ||yfood2==6 ||yfood2==7 ||yfood2==8 ||yfood2==9 ||yfood2==10 ||yfood2==11 ||yfood2==12 ||yfood2==13 ||yfood2==14 ||yfood2==15 ||yfood2==16 ||yfood2==17 ||yfood2==18||yfood2== 19 )&&(xfood2==24||xfood2==39))||((yfood2==29 ||yfood2==30 ||yfood2==31 ||yfood2==32 ||yfood2==33 ||yfood2==34 ||yfood2==35 ||yfood2==36 ||yfood2==37 ||yfood2==38 ||yfood2==39 ||yfood2==40 ||yfood2==41 ||yfood2==42 ||yfood2==43||yfood2==44 )&&(xfood2==24||xfood2==39)))||((xfood2==15||xfood2==50)&&(yfood2==14||yfood2==15||yfood2==16||yfood2==17||yfood2==18||yfood2==19||yfood2==20||yfood2==21||yfood2==22||yfood2==23||yfood2==24||yfood2==25||yfood2==26||yfood2==27||yfood2==28||yfood2==29||yfood2==30||yfood2==31||yfood2==32||yfood2==33||yfood2==34)));	
timerbool2=true;	
}
}
else
a[xfood2][yfood2]=6;		




//food3


if((hori[0]==xfood3&&vert[0]==yfood3)||(timerbool3==false))
{
if(timerbool3==true)
{
	length++;
	score+=5;
	counter3=0;
}
	
timerbool3=false;
a[xfood3][yfood3]=1;
counter3++;
if(counter3%timescale==0)
{
do
{
xfood3=1+rand()%49;
yfood3=1+rand()%49;
}
while((((xfood3==9|| xfood3==10 ||xfood3==11 ||xfood3==12 ||xfood3==13 ||xfood3==14 ||xfood3==15 ||xfood3==16 ||xfood3==17 ||xfood3==18 ||xfood3==19 ||xfood3==20 ||xfood3==21 ||xfood3==22 ||xfood3==23 ||xfood3== 24)&&(yfood3==19||yfood3==29))||((xfood3==39|| xfood3==40 ||xfood3==41 ||xfood3==42 ||xfood3==43 ||xfood3==44 ||xfood3==45 ||xfood3==46 ||xfood3==47 ||xfood3==48 ||xfood3==49 ||xfood3==50 ||xfood3==51 ||xfood3==52 ||xfood3==53 ||xfood3== 54)&&(yfood3==19||yfood3==29))||((yfood3==4 ||yfood3==5 ||yfood3==6 ||yfood3==7 ||yfood3==8 ||yfood3==9 ||yfood3==10 ||yfood3==11 ||yfood3==12 ||yfood3==13 ||yfood3==14 ||yfood3==15 ||yfood3==16 ||yfood3==17 ||yfood3==18||yfood3== 19 )&&(xfood3==24||xfood3==39))||((yfood3==29 ||yfood3==30 ||yfood3==31 ||yfood3==32 ||yfood3==33 ||yfood3==34 ||yfood3==35 ||yfood3==36 ||yfood3==37 ||yfood3==38 ||yfood3==39 ||yfood3==40 ||yfood3==41 ||yfood3==42 ||yfood3==43||yfood3==44 )&&(xfood3==24||xfood3==39)))||((xfood3==15||xfood3==50)&&(yfood3==14||yfood3==15||yfood3==16||yfood3==17||yfood3==18||yfood3==19||yfood3==20||yfood3==21||yfood3==22||yfood3==23||yfood3==24||yfood3==25||yfood3==26||yfood3==27||yfood3==28||yfood3==29||yfood3==30||yfood3==31||yfood3==32||yfood3==33||yfood3==34)))	;
timerbool3=true;	
}
}
else
a[xfood3][yfood3]=6;			



//food4
	
if((hori[0]==xfood4&&vert[0]==yfood4)||(timerbool4==false))
{
if(timerbool4==true)
{
	length++;
	score+=5;
	counter4=0;
}
	
timerbool4=false;
a[xfood4][yfood4]=1;
counter4++;
if(counter4%timescale==0)
{
do
{
xfood4=1+rand()%49;
yfood4=1+rand()%49;
}
while((((xfood4==9|| xfood4==10 ||xfood4==11 ||xfood4==12 ||xfood4==13 ||xfood4==14 ||xfood4==15 ||xfood4==16 ||xfood4==17 ||xfood4==18 ||xfood4==19 ||xfood4==20 ||xfood4==21 ||xfood4==22 ||xfood4==23 ||xfood4== 24)&&(yfood4==19||yfood4==29))||((xfood4==39|| xfood4==40 ||xfood4==41 ||xfood4==42 ||xfood4==43 ||xfood4==44 ||xfood4==45 ||xfood4==46 ||xfood4==47 ||xfood4==48 ||xfood4==49 ||xfood4==50 ||xfood4==51 ||xfood4==52 ||xfood4==53 ||xfood4== 54)&&(yfood4==19||yfood4==29))||((yfood4==4 ||yfood4==5 ||yfood4==6 ||yfood4==7 ||yfood4==8 ||yfood4==9 ||yfood4==10 ||yfood4==11 ||yfood4==12 ||yfood4==13 ||yfood4==14 ||yfood4==15 ||yfood4==16 ||yfood4==17 ||yfood4==18||yfood4== 19 )&&(xfood4==24||xfood4==39))||((yfood4==29 ||yfood4==30 ||yfood4==31 ||yfood4==32 ||yfood4==33 ||yfood4==34 ||yfood4==35 ||yfood4==36 ||yfood4==37 ||yfood4==38 ||yfood4==39 ||yfood4==40 ||yfood4==41 ||yfood4==42 ||yfood4==43||yfood4==44 )&&(xfood4==24||xfood4==39)))||((xfood4==15||xfood4==50)&&(yfood4==14||yfood4==15||yfood4==16||yfood4==17||yfood4==18||yfood4==19||yfood4==20||yfood4==21||yfood4==22||yfood4==23||yfood4==24||yfood4==25||yfood4==26||yfood4==27||yfood4==28||yfood4==29||yfood4==30||yfood4==31||yfood4==32||yfood4==33||yfood4==34)));
timerbool4=true;	
}
}
else
a[xfood4][yfood4]=6;		



//food5
	
if((hori[0]==xfood5&&vert[0]==yfood5)||(timerbool5==false))
{
if(timerbool5==true)
{
	length++;
	score+=5;
	counter5=0;
}
	
timerbool5=false;
a[xfood5][yfood5]=1;
counter5++;
if(counter5%timescale==0)
{
do
{
xfood5=1+rand()%49;
yfood5=1+rand()%49;
}
while((((xfood5==9|| xfood5==10 ||xfood5==11 ||xfood5==12 ||xfood5==13 ||xfood5==14 ||xfood5==15 ||xfood5==16 ||xfood5==17 ||xfood5==18 ||xfood5==19 ||xfood5==20 ||xfood5==21 ||xfood5==22 ||xfood5==23 ||xfood5== 24)&&(yfood5==19||yfood5==29))||((xfood5==39|| xfood5==40 ||xfood5==41 ||xfood5==42 ||xfood5==43 ||xfood5==44 ||xfood5==45 ||xfood5==46 ||xfood5==47 ||xfood5==48 ||xfood5==49 ||xfood5==50 ||xfood5==51 ||xfood5==52 ||xfood5==53 ||xfood5== 54)&&(yfood5==19||yfood5==29))||((yfood5==4 ||yfood5==5 ||yfood5==6 ||yfood5==7 ||yfood5==8 ||yfood5==9 ||yfood5==10 ||yfood5==11 ||yfood5==12 ||yfood5==13 ||yfood5==14 ||yfood5==15 ||yfood5==16 ||yfood5==17 ||yfood5==18||yfood5== 19 )&&(xfood5==24||xfood5==39))||((yfood5==29 ||yfood5==30 ||yfood5==31 ||yfood5==32 ||yfood5==33 ||yfood5==34 ||yfood5==35 ||yfood5==36 ||yfood5==37 ||yfood5==38 ||yfood5==39 ||yfood5==40 ||yfood5==41 ||yfood5==42 ||yfood5==43||yfood5==44 )&&(xfood5==24||xfood5==39)))||((xfood5==15||xfood5==50)&&(yfood5==14||yfood5==15||yfood5==16||yfood5==17||yfood5==18||yfood5==19||yfood5==20||yfood5==21||yfood5==22||yfood5==23||yfood5==24||yfood5==25||yfood5==26||yfood5==27||yfood5==28||yfood5==29||yfood5==30||yfood5==31||yfood5==32||yfood5==33||yfood5==34)));
timerbool5=true;	
}
}
else
a[xfood5][yfood5]=6;	



//POWERFOOD

if((hori[0]==xfood6&&vert[0]==yfood6)||(timerbool6==false))
{
if(timerbool6==true)
{
	length++;
	score+=20;
	counter6=0;
}
	
timerbool6=false;
a[xfood6][yfood6]=1;
counter6++;
if(counter6%(timescale*4)==0)
{
do
{
xfood6=1+rand()%49;
yfood6=1+rand()%49;
}
while((((xfood6==9|| xfood6==10 ||xfood6==11 ||xfood6==12 ||xfood6==13 ||xfood6==14 ||xfood6==15 ||xfood6==16 ||xfood6==17 ||xfood6==18 ||xfood6==19 ||xfood6==20 ||xfood6==21 ||xfood6==22 ||xfood6==23 ||xfood6== 24)&&(yfood6==19||yfood6==29))||((xfood6==39|| xfood6==40 ||xfood6==41 ||xfood6==42 ||xfood6==43 ||xfood6==44 ||xfood6==45 ||xfood6==46 ||xfood6==47 ||xfood6==48 ||xfood6==49 ||xfood6==50 ||xfood6==51 ||xfood6==52 ||xfood6==53 ||xfood6== 54)&&(yfood6==19||yfood6==29))||((yfood6==4 ||yfood6==5 ||yfood6==6 ||yfood6==7 ||yfood6==8 ||yfood6==9 ||yfood6==10 ||yfood6==11 ||yfood6==12 ||yfood6==13 ||yfood6==14 ||yfood6==15 ||yfood6==16 ||yfood6==17 ||yfood6==18||yfood6== 19 )&&(xfood6==24||xfood6==39))||((yfood6==29 ||yfood6==30 ||yfood6==31 ||yfood6==32 ||yfood6==33 ||yfood6==34 ||yfood6==35 ||yfood6==36 ||yfood6==37 ||yfood6==38 ||yfood6==39 ||yfood6==40 ||yfood6==41 ||yfood6==42 ||yfood6==43||yfood6==44 )&&(xfood6==24||xfood6==39)))||((xfood6==15||xfood6==50)&&(yfood6==14||yfood6==15||yfood6==16||yfood6==17||yfood6==18||yfood6==19||yfood6==20||yfood6==21||yfood6==22||yfood6==23||yfood6==24||yfood6==25||yfood6==26||yfood6==27||yfood6==28||yfood6==29||yfood6==30||yfood6==31||yfood6==32||yfood6==33||yfood6==34)));	
timerbool6=true;	
}
}
else
a[xfood6][yfood6]=7;	






//this restricts snake's max length to 60		
if(length>60)
	length=60;
	
		

//this is the logic for snake's body to move

for(int x=length-1;x>0;x--)
{
	hori[x]=hori[x-1];
	vert[x]=vert[x-1];
}	



//this keeps head moving constantly


switch(direction)
{
		case 'a':
			{hori[0]--;
			break;}
		case 'd':
			{hori[0]++;
			break;}
		case 's':
			{vert[0]--;  
			break;}
		case 'w':
			{vert[0]++;
			break;}
		default:
			break;		
}



//this detects the collision of snake and hurdles 


switch(difficulty)
{
	
	case 0:
	{
	break;
	}
	
	case 1:
	{
		if((hori[0]==15||hori[0]==50)&&(vert[0]==14||vert[0]==15||vert[0]==16||vert[0]==17||vert[0]==18||vert[0]==19||vert[0]==20||vert[0]==21||vert[0]==22||vert[0]==23||vert[0]==24||vert[0]==25||vert[0]==26||vert[0]==27||vert[0]==28||vert[0]==29||vert[0]==30||vert[0]==31||vert[0]==32||vert[0]==33||vert[0]==34))
			{
				gameover=false;
				endmenu=true;
				direction='q';
				
			}
			break;
	}
	case 2:
	{
		if(((hori[0]==9|| hori[0]==10 ||hori[0]==11 ||hori[0]==12 ||hori[0]==13 ||hori[0]==14 ||hori[0]==15 ||hori[0]==16 ||hori[0]==17 ||hori[0]==18 ||hori[0]==19 ||hori[0]==20 ||hori[0]==21 ||hori[0]==22 ||hori[0]==23 ||hori[0]== 24)&&(vert[0]==19||vert[0]==29))||((hori[0]==39|| hori[0]==40 ||hori[0]==41 ||hori[0]==42 ||hori[0]==43 ||hori[0]==44 ||hori[0]==45 ||hori[0]==46 ||hori[0]==47 ||hori[0]==48 ||hori[0]==49 ||hori[0]==50 ||hori[0]==51 ||hori[0]==52 ||hori[0]==53 ||hori[0]== 54)&&(vert[0]==19||vert[0]==29))||((vert[0]==4 ||vert[0]==5 ||vert[0]==6 ||vert[0]==7 ||vert[0]==8 ||vert[0]==9 ||vert[0]==10 ||vert[0]==11 ||vert[0]==12 ||vert[0]==13 ||vert[0]==14 ||vert[0]==15 ||vert[0]==16 ||vert[0]==17 ||vert[0]==18||vert[0]== 19 )&&(hori[0]==24||hori[0]==39))||((vert[0]==29 ||vert[0]==30 ||vert[0]==31 ||vert[0]==32 ||vert[0]==33 ||vert[0]==34 ||vert[0]==35 ||vert[0]==36 ||vert[0]==37 ||vert[0]==38 ||vert[0]==39 ||vert[0]==40 ||vert[0]==41 ||vert[0]==42 ||vert[0]==43||vert[0]==44 )&&(hori[0]==24||hori[0]==39)))
			{
				gameover=false;
				endmenu=true;
				direction='q';
				
			}
			break;
	}		
	
	
}				




//this detects collision of snake's head with it's body

for(int x=length-1;x>0;x--)
	{
		if(hori[0]==hori[x]&&vert[0]==vert[x])
			{
				gameover=false;
				endmenu=true;
				direction='q';
				break;
			}	
	}	

//this detects snake's collision with the walls
		
if(hori[0]==0||hori[0]==64||vert[0]==0||vert[0]==49)
{
	
	direction='q';   		 
   	gameover=false;
   	endmenu=true;
}






	
	for(int x=length-1;x>0;x--)
	{
		a[hori[x]][vert[x]]=5;
	}	
	
	a[hori[0]][vert[0]]=3;
	
}	
	
	
	

	
		

	glutPostRedisplay();

    glutTimerFunc(speed / FPS, Timer, 0);
}



//this function spawns random locations for the food
void food(){



 do
{
xfood1=1+rand()%49;
yfood1=1+rand()%49;
}
while((((xfood1==9|| xfood1==10 ||xfood1==11 ||xfood1==12 ||xfood1==13 ||xfood1==14 ||xfood1==15 ||xfood1==16 ||xfood1==17 ||xfood1==18 ||xfood1==19 ||xfood1==20 ||xfood1==21 ||xfood1==22 ||xfood1==23 ||xfood1== 24)&&(yfood1==19||yfood1==29))||((xfood1==39|| xfood1==40 ||xfood1==41 ||xfood1==42 ||xfood1==43 ||xfood1==44 ||xfood1==45 ||xfood1==46 ||xfood1==47 ||xfood1==48 ||xfood1==49 ||xfood1==50 ||xfood1==51 ||xfood1==52 ||xfood1==53 ||xfood1== 54)&&(yfood1==19||yfood1==29))||((yfood1==4 ||yfood1==5 ||yfood1==6 ||yfood1==7 ||yfood1==8 ||yfood1==9 ||yfood1==10 ||yfood1==11 ||yfood1==12 ||yfood1==13 ||yfood1==14 ||yfood1==15 ||yfood1==16 ||yfood1==17 ||yfood1==18||yfood1== 19 )&&(xfood1==24||xfood1==39))||((yfood1==29 ||yfood1==30 ||yfood1==31 ||yfood1==32 ||yfood1==33 ||yfood1==34 ||yfood1==35 ||yfood1==36 ||yfood1==37 ||yfood1==38 ||yfood1==39 ||yfood1==40 ||yfood1==41 ||yfood1==42 ||yfood1==43||yfood1==44 )&&(xfood1==24||xfood1==39)))||((xfood1==15||xfood1==50)&&(yfood1==14||yfood1==15||yfood1==16||yfood1==17||yfood1==18||yfood1==19||yfood1==20||yfood1==21||yfood1==22||yfood1==23||yfood1==24||yfood1==25||yfood1==26||yfood1==27||yfood1==28||yfood1==29||yfood1==30||yfood1==31||yfood1==32||yfood1==33||yfood1==34)))	;



do
{
xfood2=1+rand()%49;
yfood2=1+rand()%49;
}
while((((xfood2==9|| xfood2==10 ||xfood2==11 ||xfood2==12 ||xfood2==13 ||xfood2==14 ||xfood2==15 ||xfood2==16 ||xfood2==17 ||xfood2==18 ||xfood2==19 ||xfood2==20 ||xfood2==21 ||xfood2==22 ||xfood2==23 ||xfood2== 24)&&(yfood2==19||yfood2==29))||((xfood2==39|| xfood2==40 ||xfood2==41 ||xfood2==42 ||xfood2==43 ||xfood2==44 ||xfood2==45 ||xfood2==46 ||xfood2==47 ||xfood2==48 ||xfood2==49 ||xfood2==50 ||xfood2==51 ||xfood2==52 ||xfood2==53 ||xfood2== 54)&&(yfood2==19||yfood2==29))||((yfood2==4 ||yfood2==5 ||yfood2==6 ||yfood2==7 ||yfood2==8 ||yfood2==9 ||yfood2==10 ||yfood2==11 ||yfood2==12 ||yfood2==13 ||yfood2==14 ||yfood2==15 ||yfood2==16 ||yfood2==17 ||yfood2==18||yfood2== 19 )&&(xfood2==24||xfood2==39))||((yfood2==29 ||yfood2==30 ||yfood2==31 ||yfood2==32 ||yfood2==33 ||yfood2==34 ||yfood2==35 ||yfood2==36 ||yfood2==37 ||yfood2==38 ||yfood2==39 ||yfood2==40 ||yfood2==41 ||yfood2==42 ||yfood2==43||yfood2==44 )&&(xfood2==24||xfood2==39)))||((xfood2==15||xfood2==50)&&(yfood2==14||yfood2==15||yfood2==16||yfood2==17||yfood2==18||yfood2==19||yfood2==20||yfood2==21||yfood2==22||yfood2==23||yfood2==24||yfood2==25||yfood2==26||yfood2==27||yfood2==28||yfood2==29||yfood2==30||yfood2==31||yfood2==32||yfood2==33||yfood2==34)));				
	



do
{
xfood3=1+rand()%49;
yfood3=1+rand()%49;
}
while((((xfood3==9|| xfood3==10 ||xfood3==11 ||xfood3==12 ||xfood3==13 ||xfood3==14 ||xfood3==15 ||xfood3==16 ||xfood3==17 ||xfood3==18 ||xfood3==19 ||xfood3==20 ||xfood3==21 ||xfood3==22 ||xfood3==23 ||xfood3== 24)&&(yfood3==19||yfood3==29))||((xfood3==39|| xfood3==40 ||xfood3==41 ||xfood3==42 ||xfood3==43 ||xfood3==44 ||xfood3==45 ||xfood3==46 ||xfood3==47 ||xfood3==48 ||xfood3==49 ||xfood3==50 ||xfood3==51 ||xfood3==52 ||xfood3==53 ||xfood3== 54)&&(yfood3==19||yfood3==29))||((yfood3==4 ||yfood3==5 ||yfood3==6 ||yfood3==7 ||yfood3==8 ||yfood3==9 ||yfood3==10 ||yfood3==11 ||yfood3==12 ||yfood3==13 ||yfood3==14 ||yfood3==15 ||yfood3==16 ||yfood3==17 ||yfood3==18||yfood3== 19 )&&(xfood3==24||xfood3==39))||((yfood3==29 ||yfood3==30 ||yfood3==31 ||yfood3==32 ||yfood3==33 ||yfood3==34 ||yfood3==35 ||yfood3==36 ||yfood3==37 ||yfood3==38 ||yfood3==39 ||yfood3==40 ||yfood3==41 ||yfood3==42 ||yfood3==43||yfood3==44 )&&(xfood3==24||xfood3==39)))||((xfood3==15||xfood3==50)&&(yfood3==14||yfood3==15||yfood3==16||yfood3==17||yfood3==18||yfood3==19||yfood3==20||yfood3==21||yfood3==22||yfood3==23||yfood3==24||yfood3==25||yfood3==26||yfood3==27||yfood3==28||yfood3==29||yfood3==30||yfood3==31||yfood3==32||yfood3==33||yfood3==34)))	;


do
{
xfood4=1+rand()%49;
yfood4=1+rand()%49;
}
while((((xfood4==9|| xfood4==10 ||xfood4==11 ||xfood4==12 ||xfood4==13 ||xfood4==14 ||xfood4==15 ||xfood4==16 ||xfood4==17 ||xfood4==18 ||xfood4==19 ||xfood4==20 ||xfood4==21 ||xfood4==22 ||xfood4==23 ||xfood4== 24)&&(yfood4==19||yfood4==29))||((xfood4==39|| xfood4==40 ||xfood4==41 ||xfood4==42 ||xfood4==43 ||xfood4==44 ||xfood4==45 ||xfood4==46 ||xfood4==47 ||xfood4==48 ||xfood4==49 ||xfood4==50 ||xfood4==51 ||xfood4==52 ||xfood4==53 ||xfood4== 54)&&(yfood4==19||yfood4==29))||((yfood4==4 ||yfood4==5 ||yfood4==6 ||yfood4==7 ||yfood4==8 ||yfood4==9 ||yfood4==10 ||yfood4==11 ||yfood4==12 ||yfood4==13 ||yfood4==14 ||yfood4==15 ||yfood4==16 ||yfood4==17 ||yfood4==18||yfood4== 19 )&&(xfood4==24||xfood4==39))||((yfood4==29 ||yfood4==30 ||yfood4==31 ||yfood4==32 ||yfood4==33 ||yfood4==34 ||yfood4==35 ||yfood4==36 ||yfood4==37 ||yfood4==38 ||yfood4==39 ||yfood4==40 ||yfood4==41 ||yfood4==42 ||yfood4==43||yfood4==44 )&&(xfood4==24||xfood4==39)))||((xfood4==15||xfood4==50)&&(yfood4==14||yfood4==15||yfood4==16||yfood4==17||yfood4==18||yfood4==19||yfood4==20||yfood4==21||yfood4==22||yfood4==23||yfood4==24||yfood4==25||yfood4==26||yfood4==27||yfood4==28||yfood4==29||yfood4==30||yfood4==31||yfood4==32||yfood4==33||yfood4==34)));


do
{
xfood5=1+rand()%49;
yfood5=1+rand()%49;
}
while((((xfood5==9|| xfood5==10 ||xfood5==11 ||xfood5==12 ||xfood5==13 ||xfood5==14 ||xfood5==15 ||xfood5==16 ||xfood5==17 ||xfood5==18 ||xfood5==19 ||xfood5==20 ||xfood5==21 ||xfood5==22 ||xfood5==23 ||xfood5== 24)&&(yfood5==19||yfood5==29))||((xfood5==39|| xfood5==40 ||xfood5==41 ||xfood5==42 ||xfood5==43 ||xfood5==44 ||xfood5==45 ||xfood5==46 ||xfood5==47 ||xfood5==48 ||xfood5==49 ||xfood5==50 ||xfood5==51 ||xfood5==52 ||xfood5==53 ||xfood5== 54)&&(yfood5==19||yfood5==29))||((yfood5==4 ||yfood5==5 ||yfood5==6 ||yfood5==7 ||yfood5==8 ||yfood5==9 ||yfood5==10 ||yfood5==11 ||yfood5==12 ||yfood5==13 ||yfood5==14 ||yfood5==15 ||yfood5==16 ||yfood5==17 ||yfood5==18||yfood5== 19 )&&(xfood5==24||xfood5==39))||((yfood5==29 ||yfood5==30 ||yfood5==31 ||yfood5==32 ||yfood5==33 ||yfood5==34 ||yfood5==35 ||yfood5==36 ||yfood5==37 ||yfood5==38 ||yfood5==39 ||yfood5==40 ||yfood5==41 ||yfood5==42 ||yfood5==43||yfood5==44 )&&(xfood5==24||xfood5==39)))||((xfood5==15||xfood5==50)&&(yfood5==14||yfood5==15||yfood5==16||yfood5==17||yfood5==18||yfood5==19||yfood5==20||yfood5==21||yfood5==22||yfood5==23||yfood5==24||yfood5==25||yfood5==26||yfood5==27||yfood5==28||yfood5==29||yfood5==30||yfood5==31||yfood5==32||yfood5==33||yfood5==34)));


do
{
xfood6=1+rand()%49;
yfood6=1+rand()%49;
}
while((((xfood6==9|| xfood6==10 ||xfood6==11 ||xfood6==12 ||xfood6==13 ||xfood6==14 ||xfood6==15 ||xfood6==16 ||xfood6==17 ||xfood6==18 ||xfood6==19 ||xfood6==20 ||xfood6==21 ||xfood6==22 ||xfood6==23 ||xfood6== 24)&&(yfood6==19||yfood6==29))||((xfood6==39|| xfood6==40 ||xfood6==41 ||xfood6==42 ||xfood6==43 ||xfood6==44 ||xfood6==45 ||xfood6==46 ||xfood6==47 ||xfood6==48 ||xfood6==49 ||xfood6==50 ||xfood6==51 ||xfood6==52 ||xfood6==53 ||xfood6== 54)&&(yfood6==19||yfood6==29))||((yfood6==4 ||yfood6==5 ||yfood6==6 ||yfood6==7 ||yfood6==8 ||yfood6==9 ||yfood6==10 ||yfood6==11 ||yfood6==12 ||yfood6==13 ||yfood6==14 ||yfood6==15 ||yfood6==16 ||yfood6==17 ||yfood6==18||yfood6== 19 )&&(xfood6==24||xfood6==39))||((yfood6==29 ||yfood6==30 ||yfood6==31 ||yfood6==32 ||yfood6==33 ||yfood6==34 ||yfood6==35 ||yfood6==36 ||yfood6==37 ||yfood6==38 ||yfood6==39 ||yfood6==40 ||yfood6==41 ||yfood6==42 ||yfood6==43||yfood6==44 )&&(xfood6==24||xfood6==39)))||((xfood6==15||xfood6==50)&&(yfood6==14||yfood6==15||yfood6==16||yfood6==17||yfood6==18||yfood6==19||yfood6==20||yfood6==21||yfood6==22||yfood6==23||yfood6==24||yfood6==25||yfood6==26||yfood6==27||yfood6==28||yfood6==29||yfood6==30||yfood6==31||yfood6==32||yfood6==33||yfood6==34)));	

	
	}



//this is our main function


int main(int argc, char*argv[]) {
    int width = 650, height =700; 
    InitRandomizer(); 
    highscore=readScore();
    food();
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(50, 50); 
    glutInitWindowSize(width, height);
    glutCreateWindow("SAFEE's Snake Game"); 
    SetCanvasSize(650, 600); 
    glutDisplayFunc(Display); 
    glutSpecialFunc(NonPrintableKeys); 
    glutKeyboardFunc(PrintableKeys); 
    glutTimerFunc(1000.0 / FPS, Timer, 0);
    glutMainLoop();
   
    return 1;
    
    
    
}
#endif 

