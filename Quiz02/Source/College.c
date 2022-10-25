#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void){
	char firstName[25];
	char lastName[25];
	char major[25];
	char collegeYear[25];
	char graduationYear[25];
	
	printf("Enter your first name: ");
	scanf("%s", &firstName);
	printf("Enter your last name: ");
	scanf("%s", &lastName);
	printf("Major: ");
	scanf("%s", &major);
	printf("Enter year in college (ex. Freshman, sohpomore, etc.): ");
	scanf("%s", &collegeYear);
	printf("Enter your graduation year: ");
	scanf("%s", graduationYear);
	
	printf("\n");
	
	printf("\nName (last, first): Name (%s, %s)", lastName, firstName);
	printf("\nMajor: %s", major);
	printf("\nYear: %s", collegeYear);
	printf("\nGraduation year: %s", graduationYear);
	
return 0;
}