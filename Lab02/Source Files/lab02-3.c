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

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double integer_result; //int can not be used because the operation produces a decimal_result
    double decimal_result;
	int result2; //no call for printf statement 2

    integer_result = 77 / 5;
    printf("The value of 77/5 is %lf, using integer math.\n", integer_result);

    result2= 2 + 3;
    printf("The value of 2+3 is %d.\n",result2);

    decimal_result = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf.\n", decimal_result);// calling for decimal_result not long float

    return 0;
}
