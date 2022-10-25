#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void){
	double x1 = 15.55;
	double y1 = 55.15;
	double x2;
	double y2;
	double distance;
	
	//Mike
	x2 = 22.05;
	y2 = 85.10;
	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	printf("The E distance for Mike is: %lf \n", distance);
	
	//Mary
	x2 = 43.25;
	y2 = 9.80;
	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	printf("The E distance for Mary is: %lf \n", distance);
	
	//Gary
	x2 = 2.55;
	y2 = 72.86;
	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	printf("The E distance for Gary is: %lf \n", distance);
	
	//Logan
	x2 = 15.15;
	y2 = 40.40;
	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	printf("The E distance for Logan is: %lf \n", distance);
	
return 0;
}