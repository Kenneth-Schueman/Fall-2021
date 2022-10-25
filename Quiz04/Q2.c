#include<stdio.h>
#include <string.h>

int main() {
	char userPasswrd[50];
	char updatedPasswrd[50];
	int i;
	int n; 
	
	printf("Please enter a password: ");
	scanf("%s", userPasswrd);
	
	 for (i = 0; userPasswrd[i] != '\0'; ++i);
		
	 for (n = 0; n <= i; ++n){
		 if (userPasswrd[n] == 'i'){
			 userPasswrd[n] = '1';
		 }
		 else if (userPasswrd[n] == 'a'){
			 userPasswrd[n] = '@';
		 }
		 else if (userPasswrd[n] == 'm'){
			 userPasswrd[n] = 'M';
		 }
		 else if (userPasswrd[n] == 'B'){
			 userPasswrd[n] = '8';
		 }
		 else if (userPasswrd[n] == 's'){
			 userPasswrd[n] = '$';
		 }
	 }
	
	userPasswrd[i] = '!';
	userPasswrd[++i] = '\0';
	
	printf("\nYour updated password: %s", userPasswrd);
	
return 0;
}
	