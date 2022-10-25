/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Kenneth Schueman																	 -
- 	Section: 6 																 -
-	NetID: Kenschue															     -
-	Date: 9/9/2021																		 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int a;
	int b;
	double c;
	double d;
	int e;
	int f;
	double g;
	double h;
	double i;
	int j;
	double k;
	
	a = 6427 + 1725;
	b = (6971 * 3925) -95;
	c = 79 + 12 / 5;
	d = 3640.0 / 107.9;
	e = (22 / 3) * 3;
	f = 22 / (3 * 3);
	g = 22 / (3 * 3);
	h = 22 / 3 * 3;
	i = (22.0 / 3) *3.0;
	j = 22.0 / (3 * 3.0);
	k = 22.0 / 3.0 * 3.0;

	printf(" a=%d\n b=%d\n c=%.2f\n d=%.2f\n e=%d\n f=%d\n g=%.2f\n h=%.2f\n i=%.2f\n j=%d\n k=%.2f\n", a, b, c, d, e, f, g, h, i, j, k);
	
	printf("\n\n");
	//circle
	double circ = 23.567;
	double totArea;
	double pi = 22.0/7.0;
	
	//area of a circle is pi * circumference squared
	totArea = pow(circ, 2) * pi;
	printf("The area of a cirlce with the circumference 23.567 is: %lf",totArea);
	
	printf("\n\n");
	//Feet to meeters is roughly feet divided by 3.281
	double feet = 14.0;
	double meters;
	double conv = 3.281;
	
	meters = feet / conv;
	
	printf("14 feet is equal to %lf meters", meters);
	
	printf("\n\n");
	//Farhrenheit to Celsius is (°F − 32) × 5/9
	double tempF = 76.0;
	double tempC;
	
	tempC = (tempF - 32.0) * 5/9;
	
	printf("76 degrees Farhrenheit is equal to %lf Celsius", tempC);
	
    return 0;
}
