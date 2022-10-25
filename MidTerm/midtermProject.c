/*----------------------------------------------------------------------------
-		         SE 185: Midterm Project   	                                     -
- 
1- Sam Russett - Role: Quiz Creator	and debugger - Participation: 50%
(Created some quiz questions, totalAverage() function, random seed generation, and various components of the quizzes.)
2- Kenneth Schueman - Role: Quiz Creator and debugger - Participation: 50%
(Created some quiz questions and functions along with some GUI.)												                                     -
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void quiz1();
void quiz2();
void quiz3();
void totalAdverage();
int totalAttempts[30];
int attemptNumber = 0; //initialize attempt number outside of loop

int main() //Random Selection and main menu
{
	int userNum;
	int userChoice;

	printf("\nWelcome! You have three quizzes to choose from!\n");
	
	while (7 != 5){
		
	printf("Enter your lucky number 1-9 (inclusive) to get a random seeded quiz.\n");
	printf("Type anything else to exit: ");
	
	scanf("%d", &userNum);
	
	if ((userNum>=1)&&(userNum<=9)){
		srand(userNum);
		int randomNum = (rand()%100);
    
		if (randomNum%3 == 1){
			printf("\nYou got Quiz 1!");
			quiz1();
		}
		
		else if (randomNum%3 == 2){
			printf("\nYou got Quiz 2!");
			quiz2();
		}
		else if (randomNum%3 == 3){
			printf("\nYou got Quiz 3!");
			quiz3();
			}
		}
	else {
		totalAdverage();
		printf("\nThank you for playing!");
				break;
	}
}
	
    printf("\n\nYou have completed your first quiz, now you get to choose the next one.");

  /* while (7 != 5){

    printf("\nPleases select the number corrisponding to a quiz you haven't already taken");//Main Menu
    printf("\nIf you have completed all quizzes enter option 4");
    printf("\n1) Quiz01\n2) Quiz02\n3) Quiz03\n4) Calculate my results and exit\n\nChoice: ");
    scanf("%d", &userChoice);

    if (userChoice == 1){
		quiz1();
			
		}
		else if (userChoice == 2){
			quiz2();
		}
		else if (userChoice == 3){
			quiz3();
		}
		else if (userChoice == 4){
			totalAdverage();
			printf("\nThank you for playing!");
				break;
		}
    
	}
*/
    return 0;
}

void quiz1(){
	int quizScore = 0;
	int cont; //exit input
	double quizPercent;
	int quiz1answer1;
	int quiz1answer2; 
	char quiz01question3[50];
	
	printf("\n\n\nQuiz 1\nThere are 3 questions, each worth 5 points.");
	printf("\nYou can take this quiz until you get a perfect score.");
	
	while (quizScore != 15){

		attemptNumber += 1; //+1 attempt at the top of each loop
		//printf("\n\nThis is attempt #%d", attemptNumber);
		quizScore = 0;
		
		//Question 1
		printf("\n\n\nQuestion 1: True or False\n\n");
		printf("Is a valid scanf function for an integer: scanf?\n(\"lf\", &myInt);");
		printf("\n\nAnswer (1 for true and 2 for false): ");
		scanf("%d", &quiz1answer1);
		if (quiz1answer1 == 2){ //Question 1 check
			quizScore += 5;
			printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
		}
		else{
			printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
		}

   //Question 2
    printf("\n\n\nQuestion 2: Multiple Choice (answer with corresponding number)\n\n");
    printf("How many total values can be held in this array?");
    printf("\n\nint NUM_ARRAY[5][7];");
    printf("\n1) 5\n2) 7\n3) 35\n4) 12");
    printf("\n\nAnswer: ");
    scanf("%d", &quiz1answer2);

    if (quiz1answer2 == 3){ //Question 2 Check
      quizScore += 5;
       printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
    }
    else{
      printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
    }
    
    
    printf("\n\nQuestion03 fill in the blank"); //Third question
    printf("What library must you include to use the abs() function?");
    printf("\nWrite your answer in this fill in the blank format, #include <______>");
    printf("Your answer here: ");
    scanf("%s", quiz01question3);

    if(strcmp(quiz01question3, "math.h") == 0){
      quizScore += 5;
       printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
    }
    else{
      printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
    }

		totalAttempts[attemptNumber] = quizScore; //End of quiz score
		if (quizScore == 15){
			for (int i = 0; i < attemptNumber + 1; ++i) {
			quizPercent += (totalAttempts[i] / (15.0 * attemptNumber));
			}
			quizPercent *= 100;
			printf("\n\nYou got a perfect score! In total you got a %.2f%% in %d attempts\n\n", quizPercent, attemptNumber);
			break;
		}

		else{
			printf("\n\nYou did not get a perfect score yet, would you will take the quiz again!");
			}
		}
	}

void quiz2(){
  int quizScore = 0;
  int quiz2answer1, quiz2answer2;
  char quiz2answer3[50];
  int cont; //exit input
  double quizPercent;
	
	printf("\n\n\nQuiz 2:\nThere are 3 questions, each worth 5 points.");
	printf("\nYou can take this quiz until you get a perfect score.");

  while (quizScore != 15){
		attemptNumber += 1; //+1 attempt at the top of each loop
		//printf("\n\nThis is attempt #%d", attemptNumber);
		quizScore = 0;
	
    int quiz2answer1; //Quiz02 Question 1
		printf("\n\nQuestion 1: True or False\n");
		printf("Is a valid variable declaration: float myNum = 10.5?;");
		printf("\n\nAnswer (1 for true and 2 for false): ");
		scanf("%d", &quiz2answer1);
		if (quiz2answer1 == 1){ //Question 1 check
			quizScore += 5;
			 printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
		}
		else{
			printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
		}

		printf("\n\nQuestion02: Multiple choice"); //Second question
		printf("\nAnswer with corresponding number:\n What is the binary equivalent to 164? \n1) 10111001\n2) 11011001\n3) 01001100\n4) 10100100");
		printf("\nNumber _ is correct: ");
		scanf("%d", &quiz2answer2);
		
		if (quiz2answer2 == 4) { //Second question check
			quizScore += 5;
			printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
		}
		else{
			printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
		}
		
		printf("\n\nQuestion03 fill in the blank");
		printf("\n(omit whitespaces!)"); //Third question
		printf("\nComplete the program to print “Hello World!”\nx = 3\ny = 5");
		printf("\n\nIf ( x __ y) {\n    printf(“Hello World!”);\n}\nelse{}\nOperator: ");
		scanf("%s", quiz2answer3);
		
		if ((strcmp(quiz2answer3, "!=") == 0)){ //Third question check
				quizScore += 5;
			 printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
		}
		else{
			printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
		}

    totalAttempts[attemptNumber] = quizScore; //End of quiz score
		if (quizScore == 15){
			for (int i = 0; i < attemptNumber + 1; ++i) {
				//printf("%d", totalAttempts[i]);
			quizPercent += (totalAttempts[i] / (15.0 * attemptNumber));
			}
			quizPercent *= 100;
			printf("\n\nYou got a perfect score! In total you got a %.2f%% in %d attempts\n\n", quizPercent, attemptNumber);
			break;
		}

    
		else{
			printf("\n\nYou did not get a perfect score yet, would you will take the quiz again!");
        }
			quizScore = 0;
		}
  }


void quiz3(){
  int quizScore = 0;
  char quiz03question3[50];
  int quiz03question2;
  int cont; //exit input
  double quizPercent;

	while (quizScore != 15){
		attemptNumber += 1; //+1 attempt at the top of each loop
		//printf("\n\nThis is attempt #%d", attemptNumber);
		quizScore = 0;

	  int quiz3answer1; //Question 1
		printf("\n\nQuestion 1: True or False\nPrinting string3 will result in the output \"Hello World!\"?");
		printf("\n\nchar string1[10] = 'Hello';");
		printf("\nchar string2[10] = 'World'");
		printf("\nchar string3[20] = string1 + string2 + '!';");
		printf("\n\nAnswer (1 for true or 2 for false): ");
		scanf("%d", &quiz3answer1);
		if (quiz3answer1 == 2){
			quizScore += 5;
		   printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
		}
		else{
			printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
		}

		printf("\n\nQuestion02: Multiple Choice"); //Second question
		printf("\nPlease select the correct number:\n What is the correct way to calculate magnatude? \n1) magnitude = (x * y) + (y * z) + (z * x)\n2) magnitude = (x * x) + (y * y) + (z * z)\n3) magnitude = (pow(x,2) * pow(y,2) * pow(z,2))\n4) magnitude = (x * x) * (y * y) * (z * z)");
		printf("\nNumber __ is correct: ");
		scanf("%d", &quiz03question2);
		
		if (quiz03question2 == 2) { //Question check
			quizScore += 5;
		    printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
		}
		else{
			printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
		}
		
		printf("\n\nQuestion03 fill in the blank");
		printf("\n\nPlease fill in the blank \n(omit whitespaces!)"); //Third question
		printf("\nWrite a malloc function call to allocate an array for 15 double variables.");
		printf("\nchar* string = NULL;\nstring = (char*)malloc(_______);: ");
		scanf("%s", quiz03question3);
		
		
		if ((strcmp(quiz03question3, "10*sizeof(char)") == 0) || (strcmp(quiz03question3,"sizeof(char)*10") == 0)){ //Question check
				quizScore += 5;
		  printf("\nCorrect!\n\nScore for this attempt: %d / 15", quizScore);
		}
		else{
			printf("\nIncorrect\n\nScore for this attempt so far: %d / 15", quizScore);
		}
    
    totalAttempts[attemptNumber] = quizScore; //End of quiz score
		if (quizScore == 15){
			for (int i = 0; i < attemptNumber; ++i) {
			quizPercent += (totalAttempts[i + 1] / (15.0 * attemptNumber));
			}
			quizPercent *= 100;
			printf("\n\nYou got a perfect score! In total you got a %.2f%% in %d attempts\n\n", quizPercent, attemptNumber);
			break;
		}

		else{
			printf("\n\nYou did not get a perfect score yet, would you will take the quiz again!");
        }
			quizScore = 0;
		}
  }

void totalAdverage(){
  double avgPercent = 0;
	for (int i = 0; i <= attemptNumber; ++i){
	avgPercent = totalAttempts[i] + avgPercent;
		//printf("\n%lf\n", avgPercent);
	}
	for (int i = 0; i <= attemptNumber; ++i){
		if (totalAttempts[i] == 0) {
			attemptNumber += 1;
		}
	}
	attemptNumber /= 10;
	printf("\n\nTotal points scored = %.2f / %d", avgPercent, attemptNumber * 15);
	printf("\nTotal number of attempts = %d", attemptNumber);
	avgPercent = (avgPercent / (attemptNumber * 15.0)* 100);
	printf("\nYour average score across all quiz attempts is: %.2f%%", avgPercent);

}

double quizAdverage(double score){
  score /= 15;
  score *= 100;
  return (score);
}