#include <stdio.h>
#include <conio.h>

int main() {
	// Define this so I can grab the choice they make
	int choice;
	printf("What would you like to do?\n");
	printf("1: Add\n");
	printf("2: Subtract\n");
	printf("3: Multiply\n");
	printf("4: Divide\n");
	printf("");
	scanf("%d", &choice);
	// This goes through and decides where to send the user
	switch(choice){
		case 1 :
			add();
			break;
		case 2 :
			subtract();
			break;
		case 3 :
			multiply();
			break;
		case 4 :
			divide();
			break;
		// This is in case they input a number not between 1 and 4
		default :
			printf("ERROR: Invalid Number\n");
			printf("Please run the program again with a new value.\n");
	}
	getch();
	
	
	return 0;
}
int add(){
	int first;
	int second;
	printf("First number to add: ");
	scanf("%d", &first);
	printf("\nSecond number to add: ");
	scanf("%d", &second);
	int end_value = first+second;
	printf("\nYour answer is: %d", end_value);
	return 0;
}
int subtract(){
	int first;
	int second;
	printf("First number to subtract: ");
	scanf("%d", &first);
	printf("\nSecond number to subtract: ");
	scanf("%d", &second);
	int end_value = first-second;
	printf("\nYour answer is: %d", end_value);
	return 0;
}
int multiply(){
	int first;
	int second;
	printf("First number to multiply: ");
	scanf("%d", &first);
	printf("\nSecond number to multiply: ");
	scanf("%d", &second);
	int end_value = first*second;
	printf("\nYour answer is: %d", end_value);
	return 0;
}
int divide(){
	double first;
	double second;
	printf("First number to divide: ");
	scanf("%lf", &first);
	printf("\nSecond number to divide: ");
	scanf("%lf", &second);
	double end_value = first/second;
	printf("\nYour answer is: %lf", end_value);
	return 0;
}