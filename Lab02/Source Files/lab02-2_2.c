/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Kenneth Schueman																	 -
- 	Section: 6 																 -
-	NetID: Kenschue															     -
-	Date: 9/9/2021																		 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
int x,y,z;
	printf("Enter a width: ");
	scanf("%d", &x);
	printf("Enter a height: ");
	scanf("%d", &y);
	printf("Enter a length: ");
	scanf("%d", &z);
	printf("A %d by %d and %d rectangle's volume is: %d",x, y, z, x*y*z);

return 0;
}