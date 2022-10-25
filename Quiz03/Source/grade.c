#include<stdio.h>


int main (void){
	int gradePerc;
	
	printf("Please enter your grading percentage:\n");
	scanf("%d", &gradePerc);
	
	if (gradePerc >= 0 && gradePerc < 100) {
		if (gradePerc >= 93) {
			printf("Your grade letter is A");
		}
		else if (gradePerc >= 90 && gradePerc < 93) {
			printf("Your grade letter is A-");
		}
		else if (gradePerc >= 87 && gradePerc < 90) {
			printf("Your grade letter is B+");
		}
		else if (gradePerc >= 83 && gradePerc < 87) {
			printf("Your grade letter is B");
		}
		else if (gradePerc >= 80 && gradePerc < 83) {
			printf("Your grade letter is B-");
		}
		else if (gradePerc >= 77 && gradePerc < 80) {
			printf("Your grade letter is C+");
		}
		else if (gradePerc >= 73 && gradePerc < 77) {
			printf("Your grade letter is C");
		}
		else if (gradePerc >= 70 && gradePerc < 73) {
			printf("Your grade letter is C-");
		}
		else if (gradePerc >= 67 && gradePerc < 70) {
			printf("Your grade letter is D+");
		}
		else if (gradePerc >= 63 && gradePerc < 67) {
			printf("Your grade letter is D");
		}
		else if (gradePerc >= 60 && gradePerc < 63) {
			printf("Your grade letter is D-");
		}
		else if (gradePerc >= 0 && gradePerc < 60) {
			printf("Your grade letter is F");
		}
		
	}
	
	else {
		printf("Your grade must be between 0 percent and 100 percent inclusively.");
	}
	
	return 0;
}