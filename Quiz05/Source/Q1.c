#include<stdio.h> 

int main(void) {
const int AMNT_HW = 5;
const int AMNT_EX = 3;	
double hw[AMNT_HW];
double exam[AMNT_EX];
double hwB = 0;
double exB = 0;
double hwAvg, examAvg, weightedAvg;

	for (int i = 0; i < AMNT_HW; ++i) {
		printf("Enter your grade (%%) for HW #0%d:", i + 1);
			scanf("%lf", &(hw[i]));
	}
	for (int i = 0; i < AMNT_EX; ++i) {
		printf("Enter your grade (%%) for Exam #0%d:", i + 1);
			scanf("%lf", &(exam[i]));
	}
	printf("\n");
	
	for (int i = 0; i < AMNT_HW; ++i) {
		hwB = hwB + hw[i];
	}
	
	for (int i = 0; i < AMNT_EX; ++i) {
		exB = exB + exam[i];
	}
		
	hwAvg = hwB / 5.0; //Adverage
	examAvg = exB / 3.0; //Adverage	
	
	weightedAvg = (0.40 * hwAvg) + (0.60 * examAvg); //Total adverage
	
	printf("\nFinal grade = %.2lf%%\n" , weightedAvg);     

return 0;
}