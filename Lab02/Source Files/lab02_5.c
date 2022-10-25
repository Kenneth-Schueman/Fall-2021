#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void){ 
	double c;
	double b;
	double a;
	double pyThe;
	//Pythagorean Theorem c^2 = b^2 + a^2
	printf("Please enter an A value: \n ");
	scanf("%lf", & a);
	printf("Please enter an B value: \n ");
	scanf("%lf", & b);
	
	c = (a*a) + (b*b);
	pyThe = c*c;

	printf("The missing side is %lf long.", pyThe);
	
	return 0;
}