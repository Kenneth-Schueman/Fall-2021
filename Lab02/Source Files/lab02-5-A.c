/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Kenneth Schueman													 -
- 	Section: 6 																 -
-	NetID: Kenschue															 -
-	Date: 9/9/2021															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double filler;

    printf("Please enter the first integer: ");
	scanf("%d", &a);
	printf("\nPlease enter the second integer: ");
	scanf("%d", &b);
	
	a = a*a;
	
	c = sqrt((pow(b, 2)) + (pow(a, 2)));
	
	printf("%d", c);


    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt();

    return 0;
}
