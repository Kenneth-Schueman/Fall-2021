#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double drivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon){
	double func;
	func = (drivenMiles / milesPerGallon) * dollarsPerGallon;
	return func;
}

int main (void){
	double drivenMiles;
	double milesPerGallon;
	double dollarsPerGallon;
		
	printf("Enter driven Miles:");
	scanf("%lf", &drivenMiles);
	printf("\nEnter Miles per Gallon:");
	scanf("%lf", &milesPerGallon);
	printf("\nEnter dollars per Gallon:");
	scanf("%lf", &dollarsPerGallon);
	
	printf("\nDriving Cost= %.2f", drivingCost(drivenMiles, milesPerGallon, dollarsPerGallon));
return 0;
}