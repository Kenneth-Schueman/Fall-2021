#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main (){
	char userName[50];
	char passWord[50];
	
	printf("Enter your username: ");
	scanf("%s", userName);
	printf("\nEnter your password: ");
	scanf("%s", passWord);
	
	
	if (strcmp(userName, "se185@iastate.edu") == 0) {
		if (strcmp(passWord, "ds4rd") == 0) {
			printf("Success!");
		}
		else {
			printf("Username or password is incorrect.");
		}
	}
	else {
		printf("\nUsername or password is incorrect.");
	}
return 0;
}