#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void){
	long phoneNum;
	int areaCode;
	int exCode;
	int usrNum;
	
	printf("Please enter the 10 digits phone number:");
	scanf("%ld", &phoneNum);
	printf("\n");
	
	areaCode = phoneNum * pow(10,-7);
	phoneNum -= areaCode * pow(10,7);
	exCode = phoneNum * pow(10,-4);
	phoneNum -= exCode * pow(10, 4);
	usrNum = phoneNum;
	
	printf("The area code is: %d \n", areaCode);
	printf("The exchange code is: %d \n", exCode);
	printf("The user number is: %d \n", usrNum);
	
return 0;
}