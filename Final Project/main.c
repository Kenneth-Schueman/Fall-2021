
/*
Team xx (please insert your team number instead of xx)
Team member 1 "Name" | "Percentage of Contribution to The Project"
Team member 2 "Name" | "Percentage of Contribution to The Project"
*/

////////////////////
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "shapes.h"

#define MAX 100

//////////////////////
// Struct Definition//
////////////////////

typedef struct processStruct {
	int userScore;
	char name[3]; //SR//
} struc;

struct processStruct structs[MAX];

// Shapes
void triangle(int winX, int winY);
void square(int winX, int winY);
void circle(int winX, int winY);
void cross(int winX, int winY);

// Indicual Prints
void standardPrint(int winX, int winY);
void trianglePrint(int winX, int winY);
void squarePrint(int winX, int winY);
void circlePrint(int winX, int winY);
void crossPrint(int winX, int winY);

// Game Mechanics
int countdownTimer();

int main(int argc, char **argv) {
	FILE *highscores = NULL; //SR//
	char startChar;
	int score = 0, i, level, levelCounter, levelScore;
	int winY, winX;
	int flagA = 1, flagB = 1, flag0 = 1, flagEnd = 0;
	int j;

	char *sequenceMachine;
	char *sequenceUser;
	char *userInput;

  struc scores[9]; //SR//
  struc attempt; //SR//
  int placeval = 10;

  highscores = fopen("highscores.txt", "r"); //SR//
  
  for (j = 0; j < 9; j++){ //SR//
		fscanf(highscores, "%d %s", &scores[j].userScore, scores[j].name);
	}
	fclose(highscores);

	// malloc
	sequenceMachine = (char *)malloc(sizeof(char));
	sequenceUser = (char *)malloc(sizeof(char));
	userInput = (char *)malloc(100 * sizeof(char));

	// Screen Start
	initscr();
	refresh();
	cbreak();
	echo();

	// Grabing Window Size
	getmaxyx(stdscr, winY, winX);

	// Welcome Message
	mvaddstr(0, 0, "Welcome to the Memory game.");
	mvaddstr(1, 0, "To start the game press \"g\"");
	mvaddstr(2, 0, "In the game various shapes will appear with a cirlce around it");
	mvaddstr(3,0,"You must remember the shapes that are circled and repeat the order");
	mvaddstr(4,0,"Use \"w\" for up. \"s\" for down. \"d\" for right. \"a\" for left");

	// Highscore Table
	mvaddstr(6, 0, "Highscore Table:");
	mvaddstr(7, 0, "Rank Score Name");

	// Highscore Table read and print FIXME
	for (i = 0; i < 9; i++) {//SR//
		mvprintw((8 + i), 0, " %d    %d    %s", i+1, scores[i].userScore, scores[i].name);
	}

	// Game Countdown and User Input
	mvaddstr(18, 0, "What would you like to do?");
	mvaddstr(19, 0, "Press \"g\" for a game: ");

	refresh();
	startChar = getch();

	if (startChar != 'g') {
		mvaddstr(19, 0, "Thanks for playing!");
		refresh();
		sleep(2);
		endwin();
		return 0;
	}
	// Screen Reset
	sleep(1);
	clear();

	//////////////////////////////////////////////////////////////////////////////////////////////

	// Game
	while (flag0 == 1) {
		while (flagA == 1) {
			// END GAME
			if (score == 101) {
				clear();
				mvaddstr((winY / 2), (winX / 2) - 4, "YOU WIN!");
				mvaddstr(((winY / 2) - 1), (winX / 2) - 4, "Press Any Key To Quit");
				getch();
				endwin();
				return 0;
			}
			// Radom Selection and level generator
			else {
				srand(time(NULL));

				clear();
				mvprintw(0, 0, "You are on Level %d!", (levelCounter + 1));

				for (i = 3; i > 0; i--) {
					mvprintw((4 - i), 0, "%d...\n", i);
					fflush(stdout);
					refresh();
					sleep(1);
				}

				clear();
				mvprintw(0, 0, "You are on Level %d!", (levelCounter + 1));

				sequenceMachine[0] = '\0';

				// Sequence Generator
				for (i = 0; i < (levelCounter + 1); i++) {
					level = rand() % 4;
					standardPrint(winX, winY);
					sleep(1);

					switch (level) {
					case 0:
						clear();
						trianglePrint(winX, winY);
						mvprintw(0, 0, "You are on Level %d!", (levelCounter + 1));
						strcat(sequenceMachine, "w");
						break;
					case 1:
						clear();
						squarePrint(winX, winY);
						mvprintw(0, 0, "You are on Level %d!", (levelCounter + 1));
						strcat(sequenceMachine, "a");
						break;
					case 2:
						clear();
						circlePrint(winX, winY);
						mvprintw(0, 0, "You are on Level %d!", (levelCounter + 1));
						strcat(sequenceMachine, "d");
						break;
					case 3:
						clear();
						crossPrint(winX, winY);
						mvprintw(0, 0, "You are on Level %d!", (levelCounter + 1));
						strcat(sequenceMachine, "s");
						break;
					}
					sleep(1);
					clear();
					mvprintw(0, 0, "You are on Level %d!", (levelCounter + 1));
					standardPrint(winX, winY);
					sleep(1);
				}
				flagA = 0;
			}
		}

		// Inbetween Machine and user sequence
		sleep(1);
		clear();
		mvaddstr(0, 0, "Ready?");

		for (i = 3; i > 0; i--) {
			mvprintw((4 - i), 0, "%d...\n", i);
			fflush(stdout);
			refresh();
			sleep(1);
		}

		// housekeeping
		clear();
		++levelCounter;
		sequenceUser[0] = '\0';
		flagB = 1;

		while (flagB == 1) {
			// Start Message
			mvaddstr(0,	0,"You have 5 secconds to choose every symbol in the sequence,");
			mvaddstr(1,0,"use the \"w\",\"a\",\"s\",\"d\" keys to enter the sequence.");
			mvprintw(2, 0, "Turn: %d", levelCounter);
			mvprintw(3, 0, "Score: %d", score);
			levelScore = 0;

			// User history
			

			// mvprintw(1, (winX - 30), "%s / %s", sequenceUser,sequenceMachine);// Cheat Sheet

			// User selection
			for (i = 0; i < strlen(sequenceMachine); i++) {
				mvprintw((5 + i), 0, "Selection %d: ", (levelScore + 1));

				*userInput = getch();

				if (*userInput == 'w' || *userInput == 'a' ||*userInput == 's' || *userInput == 'd') {
					// string comapre
					strcat(sequenceUser, userInput);
					sequenceUser[i + 1] = '\0';
					refresh();

					if (sequenceMachine[i] == sequenceUser[i]) {
						// score adding -> to next sequence
						++score;
						mvprintw((6 + i), 0, "Score: %d", score);
						++levelScore;
						refresh();
					}

					// Wrong Answer
					else{
						mvaddstr((8 + i), 0, "Sorry, that is incorrect");
						refresh();
						sleep(1);
						flagEnd = 1;
						break;
					}
				}

				// Invalid input
				else {
					mvaddstr((8 + i), 0, "Invalid Key");
						refresh();
						--i;
				}
			}

				//flag reset for next round
				if (flagEnd == 0){
				flagA = 1;
				flagB = 0;
				mvaddstr((7 + i), 0, "Nice Work! Moving on to the next round...");
				refresh();
				sleep(3);
				}
				
				//End Game prompt
				else{
				flagA = 0;
				flagB = 0;

					clear();
					mvprintw(0, 0, "Sorry, you lose, at least you got to level %d", levelCounter);
					mvprintw(1, 0, "Your final score was %d. Try again and get even higher!", score);
					refresh();
					
					attempt.userScore = score; 
					
					//Check Score to see if > then 9th place FIXME
					
					for (j=0; j<9; j++){ 
						if (attempt.userScore > scores[j]. userScore){
							mvprintw(3, 0, "Your score placed you at rank %d", j+1);
							placeval = j;
							break;
						}
					}
					
					if (placeval == 10){
						mvaddstr(4, 0, "You did not place on the scoreboard :(");
						refresh();
					}
					else {
						
						//update scoreboard
						mvaddstr(5, 0, "Congratulations, you made it on the highscore table!");
						mvaddstr(6, 0, "Please enter three initials (no spaces): ");
						refresh();
						scanf("%s", attempt.name);
					
						for (i=8; i>placeval; i--){
							scores[i].userScore = scores[i-1].userScore;
							strcpy(scores[i].name, scores[i-1].name);
						}
						
						scores[placeval].userScore = attempt.userScore;
						strcpy(scores[placeval].name, attempt.name);
					}
						
						//print scoreboard
						mvaddstr(7, 0, "Updated scoreboard:");
						mvaddstr(8, 0, "Rank Score Name");
						
						for (i=0; i<9; i++){
							mvprintw((10+i), 0, "%d. %d %s",i + 1, scores[i].userScore, scores[i].name);
						}
						
						highscores = fopen("highscores.txt", "w");
						for (i=0; i<9; i++){
							fprintf(highscores, "%d %s\n", scores[i].userScore, scores[i].name);
						}
	
						fclose(highscores);
					
					mvaddstr(21, 0, "Press Any Key To Quit");
					refresh();
					getch();
					flag0 = 0;
				}

		// Sleep until next round
		sleep(3);
		refresh();
	  }
  }

	// clear memory
	free(sequenceMachine);
	free(sequenceUser);
	free(userInput);

	endwin();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
// Game Mechanics

int countdownTimer() {
	int result, i;

	for (i = 5; i > 0; i--) {
		sleep(1);
		while (i == 0) {
			result = 1;
		}
		result = 0;
	}

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////
