/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name: Kenneth Schueman																	 -
- 	Section: 6																 -
-	NetID: kenschue																     -
-	Date: 10/21/2021																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
-	                            Notes  -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/

int triangle, circle, buttonx, square;
int timer;
int run_game(void);

int main(int argc, char *argv[])
{
	
	printf("Welcome to Bop-It! Press Triangle to play, or Circle to exit\n");
	
	while (1){
		scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
		
		if (triangle == 1){
			run_game();
			break;
		}
		else if (circle == 1){
			break;
		}
	}
	
    return 0;
}

int run_game(void){
	
	int randomButton;
	int userAnswer;
	int rounds = 0;
	
	 //user starts with 2500 milliseconds to answer on the first round
	int timeAllotted = 2500;
	
	//scan in time at which the user started the round
	int timeStart;			
	
	while (1){
		
		 //skip if all input not zero
		scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
		
		//gets rid of extraneous button presses
		if ((triangle == 1) || (circle == 1) || (buttonx == 1) || (square == 1)){ 
			continue;
		}
		
		srand(time(NULL)); /* This will ensure a random game each time. */
		randomButton = (rand()%4); //random number will be 0, 1, 2, or 3
		
		//assign 0 with triangle
		if (randomButton == 0){ 								
			printf("\n\nYou have %d milliseconds to respond!", timeAllotted);
			printf("\nPress the Triangle button!\n");
			scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
			timeStart = timer;
			while(timer < timeStart + timeAllotted){
				scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
				if (triangle == 1){
					printf("\nCorrect!\n");
					timeAllotted = timeAllotted - 100;
					rounds += 1;
					break;
				}
				else if(circle == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(buttonx == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(square == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
					
				if (timer >= timeStart + timeAllotted){
					printf("\nYou ran out of time! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
			}
		}
		
		//assign 1 with circle	
		else if (randomButton == 1){ 							
			printf("\n\nYou have %d milliseconds to respond!", timeAllotted);
			printf("\nPress the Circle button!\n");
			scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
			timeStart = timer;
			while(timer < timeStart + timeAllotted){
				scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
				if (triangle == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(circle == 1){
					printf("\nCorrect!\n");
					timeAllotted = timeAllotted - 100;
					rounds += 1;
					break;
				}
				else if(buttonx == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(square == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
					
				if (timer >= timeStart + timeAllotted){
					printf("\nYou ran out of time! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
			}
		}
		
		//assign 2 with X
		else if (randomButton == 2){							
			printf("\n\nYou have %d milliseconds to respond!", timeAllotted);
			printf("\nPress the X button!\n");
			scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
			timeStart = timer;
			while(timer < timeStart + timeAllotted){
				scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
				if (triangle == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(circle == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(buttonx == 1){
					printf("\nCorrect!\n");
					timeAllotted = timeAllotted - 100;
					rounds += 1;
					break;
				}
				else if(square == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
					
				if (timer >= timeStart + timeAllotted){
					printf("\nYou ran out of time! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
			}
		}
		
		// assign 3 with square
		else if (randomButton == 3){							
			printf("\n\nYou have %d milliseconds to respond!", timeAllotted);
			printf("\nPress the Square button!\n");
			scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
			timeStart = timer;
			while(timer < timeStart + timeAllotted){
				scanf("%d, %d, %d, %d, %d", &timer, &triangle, &circle, &buttonx, &square);
				if (triangle == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(circle == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(buttonx == 1){
					printf("\nWrong Button! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
				else if(square == 1){
					printf("\nCorrect!\n");
					timeAllotted = timeAllotted - 100;
					rounds += 1;
					break;
				}
					
				if (timer >= timeStart + timeAllotted){
					printf("\nYou ran out of time! You lose!\n");
					printf("You made it through %d rounds", rounds);
					printf("\n\nThanks for playing!");
					exit(0);
				}
			}
		}
	}
}
