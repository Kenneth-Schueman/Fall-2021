/*--------//--------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name: Kenneth Schueman																	 -
- 	Section: 6																 -
-	NetID: kenschue																     -
-	Date: 9/30/2021  																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/

double mag(double a, double b, double c);
int close_to (double tolerance, double point, double value);
int checkMovement (double a, double b, double c, double tolerance, double value);


/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	int flag = 0;

    while (b1 == 0)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",&ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4);
		
	if (close_to(0.1, 0, mag(ax, ay, az))) {	

		if (close_to (.1, 1, gy) && flag != 1){
			flag=1;
			printf("Top\n");
		}
		else if (close_to (.1, -1, gy) && flag != 2){
			flag = 2;
			printf("Bottom\n");
		}
		else if (close_to (.1, 1, gx) && flag != 3){
			flag = 3;
			printf("Left\n"); //left
		}
		else if (close_to (.1, -1, gx) && flag != 4){
			flag = 4;
			printf("Right\n"); //right
		}
		else if (close_to (.1, 1, gz) && flag != 5){
			flag = 5;
			printf("Back\n"); //top
		}
		else if (close_to (.1, -1, gz) && flag != 6){
			flag = 6;
			printf("Front\n"); //bottom
			}
		}
	}
	return 0;
}

double mag(double a, double b, double c){
	double m = sqrt((a * a) + (b * b) +(c * c));
			printf("%lf", m);

	return m;
	}
	
int close_to (double tolerance, double point, double value){
	if ((value > point - tolerance && value < point + tolerance)) {
		return 1;
	} else { 
		return 0;
}
}

int checkMovement (double a, double b, double c, double tolerance, double value) {
	if (value > mag(a, b, c) - tolerance && value < mag(a, b, c) + tolerance) {
		return 0;
	} else {
		return 1;
	}
}