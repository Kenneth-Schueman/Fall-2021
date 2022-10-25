#include<stdio.h> 
#include<stdlib.h>
#include<math.h>

double adverageGrade(double number);
char gradeLttr(double number);

int main(void) {
const int STU_AMNT = 2;
const int STU_ASNT = 4;
int stu[STU_AMNT][STU_ASNT];
double counter1 = 0;
double counter2 = 0;

	for (int i = 0; i < STU_AMNT; ++i) {
		for (int j = 0; j < STU_ASNT; ++j) {
			printf("Student-%d Assignment-%d grade: ", i + 1, j + 1);
				scanf("%d", &(stu[i][j]));
		}
	}

	printf("\n");
	
	for (int j = 0; j <= STU_ASNT - 1; ++j) {
		counter1 = counter1 + (stu[0][j]);
	}
	
	for (int j = 0; j <= STU_ASNT -1; j++) {
		counter2 = counter2 + (stu[1][j]);
	}
	
		printf("Student 1 Avg = %.2f\n", adverageGrade(counter1)); //add variables
		
		printf("Student 1 Grade = %c\n", gradeLttr(adverageGrade(counter1))); //add variables
		
		printf("Student 2 Avg = %.2f\n", adverageGrade(counter2)); //add variables
		
		printf("Student 2 Grade = %c\n", gradeLttr(adverageGrade(counter2))); //add variables
		
return 0;
}

double adverageGrade(double number){
	number = number / 4.0;
	return number;
}
	
char gradeLttr(double number){
	if (number >= 0 && number < 100) {
		if (number >= 85) {
			number = 'A';
		}
		else if (number >= 75 && number < 85) {
			number = 'B';
		}
		else if (number >= 60 && number < 75) {
			number = 'C';
		}
		else if (number >= 74 && number < 60) {
			number = 'D';
		}
		else if (number >= 0 && number < 60) {
			number = 'F';
		}
	}
	return number;
}