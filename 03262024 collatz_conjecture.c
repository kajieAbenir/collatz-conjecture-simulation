#include <stdio.h>
#include <stdlib.h>

// collatz conjecture demo
// by: brent kyrjeh abenir

// reason for creation: Veritasium's video.

// function prototypes. for program to be read later.

void welcomeScreen();
void operation (int number);
void afterLoopPrint(int lastNum, int looNum);

int main() {
	// clears cmd screen in case of previous entries.
	system("cls");
	
	// calls the main program.
	welcomeScreen();
	
	// program finishes if user inputs 0 in welcomeScreen.
	return 0;
}

void welcomeScreen(){
	printf("COLLATZ CONJECTURE SIMULATION PROGRAM\n");
	printf("made by: BRENT KYRJEH ABENIR\n");
	
	printf("\n---------------\n\n");
	
	// declare starting number.
	int number = 0;
	
	printf("Enter a starting number. 0 to exit. \n>>> ");
	scanf("%d",&number);
	
	if(number == 0){
		return;
	} else if(number < 0){
		system("cls");
		printf("ERROR! Value must not be negative.\nThe program will go wild XD\n");
		printf("\n---------------\n\n");
		welcomeScreen();
	}
	
	printf("\n---------------\n\n");
	
	operation(number);
}

void operation (int number){
	// declare loop repititions.
	int i = 0;
	
	// declare 4-2-1 loop detection storage.
	int problemStart = 0;
	
	int collatzLoop = 0;
	
	for(i = 0;i < i+1;i++){
		
		// if the number is even...
		if(number % 2 == 0){
			
			// the number is divided by 2.
			number = number / 2;
		} 
		
		// else, assuming the number is odd...
		else {
			
			// the number is mult. by 3 then added by 1.
			number = (3 * number) + 1;
		}
		
		// outputs result from the conditions.
		printf("Result #%d >> %d\n", i+1, number);
		
		// algorithm to stop program from overflowing the 4-2-1 loop more than 3 times.
		
		// checks if current result == 1
		if(number == 1){
			problemStart = i;
			// if yes, also checks how many 4-2-1 (Collatz Sequence) loops had passed.
			// if 4-2-1 loops == 3, stops the repetitive calculation.
			if(collatzLoop == 3){
				printf("\nExecution stopped.\nCollatz sequence found!\n");
				break;
			} else {
				collatzLoop++;
			}
		}
	}
	
	// passes to result-printing function.
	afterLoopPrint(number, problemStart);
}

void afterLoopPrint(int lastNum, int loopNum){
	
	printf("\n---------------\n\n");
	
	printf("The 4-2-1 Collatz Sequence started at result #%d\n", loopNum-10);
	
	// waits for user's ENTER key.
	printf("Press [Enter] to continue... ");
	getch();
	
	// clears screen to make way of new entry.
	system("cls");
	
	// loops the program back to start.
	welcomeScreen();
}