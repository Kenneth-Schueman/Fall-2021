//./ds4rd.exe -d 054c:09cc -D DS4_USB -t -bt | ./lab8_2 10
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159

#define NUMCOLS 100
#define NUMROWS 80

#define AVATAR 'O'
#define WALL '*'
#define EMPTY_SPACE ' '

#define NUM_SAMPLES 10  

char MAZE[NUMROWS][NUMCOLS];

void generate_maze(int difficulty);

void draw_maze(void);

void draw_character(int x, int y, char use);

float calc_roll(float x_mag);

void delay(unsigned int ms);

void main(int argc, char* argv[])
{
	int time, difficulty, avX, avY;
	double x, y, z;
	
	sscanf(argv[1], "%d", &difficulty);
	
	// setup screen    
	initscr();
	refresh();

	// Generate and draw the maze, with initial avatar
	generate_maze(difficulty);
	draw_maze();
	avX = NUMCOLS/2;
	avY = 0;
	draw_character(avX, avY, AVATAR);

	// Read gyroscope data to get ready for using moving averages.    
	scanf("%d, %lf, %lf, %lf", &time, &x, &y, &z);
	
	double direction = -10;
	int directVal = 0;
	int waiting = 0;
	int movingSideways = 0;
	int prevX = 0;
	int	prevY = 0;

	// Event loop
	do
	{
		// Read data, update average
        scanf("%d, %lf, %lf, %lf", &time, &x, &y, &z);
		
		//if(!waiting){
			//draw_character(avX,avY, EMPTY_SPACE);
		//}			
		//if(movingSideways){
			//draw_character(avX,avY, EMPTY_SPACE);
		//}
		
		//get direction				
		if(calc_roll(x) > .1){
			//move left
			if(avX > 0){ // keeps avatar in maze on left side
				directVal = -1;
			}else if(x < -0.1){
				//move right
				if(avX < NUMCOLS){ // keeps avatar in maze on right side
					directVal = 1;
				}else{
					directVal = 0;
				}
			}
		}
		
		if(directVal != 0){
			//check in directVal direction and below
			if(MAZE[avX + directVal][avY] != EMPTY_SPACE && MAZE[avX][avY + 1] != EMPTY_SPACE){	
				//stuck
				draw_character(avX, avY, AVATAR);
						
				int count = 0;
				int i = avX;
				while(i > 0 && i < NUMCOLS){	
					i = i - directVal;
					if(MAZE[i][avY] != EMPTY_SPACE){
						i = -5;
						break;
					}
					if(MAZE[i][avY+1] == EMPTY_SPACE){
						break;
					}
					count++;
				}
						
				if(i==-5){
					endwin();
					printf("YOU LOSE!");
					break;
				}		
				continue;
			}
		}else if(MAZE[avX][avY + 1] == EMPTY_SPACE){
			//moves avatar down
			avY++;
			draw_character(avX, avY - 1, EMPTY_SPACE);
			draw_character(avX, avY, AVATAR);
		}
		
		//checks if there's a star below character
		if(MAZE[avX][avY + 1] == WALL){
			while(MAZE[avX][avY + 1] == WALL){
				scanf("%d, %lf, %lf, %lf", &time, &x, &y, &z);
				if(x < -.5){
					//move right
					avX++;
					draw_character(avX, avY, EMPTY_SPACE);
					draw_character(avX, avY, AVATAR);
					break;
				}
			}
		}
		else{
			//moves avatar down
			avY++;
			delay(1000);
			draw_character(avX, avY - 1, EMPTY_SPACE);
			draw_character(avX, avY, AVATAR);
		}
	} while(avY != NUMROWS);

	// Print the win message
	endwin();
	
	printf("YOU WIN!\n");
}

void generate_maze(int difficulty){
	srand(time(NULL));
	for(int i = 0; i < NUMROWS; ++i){
		for(int j = 0; j < NUMCOLS; ++j){
            rand() % 100;
            if(rand() % 100 < difficulty){
                MAZE[i][j] = WALL;
            }else{
                MAZE[i][j] = EMPTY_SPACE;
            }
		}
	}
}

void draw_maze(void){
	for(int i = 0; i < NUMROWS; ++i){
		for(int j = 0; j < NUMCOLS; ++j){
            draw_character(i,j,MAZE[i][j]);
		}
	}
	refresh();
}

float calc_roll(float x_mag){
	if(x_mag <= -1){
		x_mag = -1;
	}else if(x_mag >= 1){
		x_mag = 1;
	}
	return asin(x_mag);
}

void delay(unsigned int ms)
{
    clock_t sec = ms + clock();
    while (sec > clock());
}

//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}