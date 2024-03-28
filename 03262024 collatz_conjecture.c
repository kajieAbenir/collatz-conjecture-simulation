#include <stdio.h>
#include <stdlib.h>

// collatz conjecture demo
// by: brent kyrjeh abenir

// reason for creation: Veritasium's video.

// function prototypes. for program to be read later.

void welcomeScreen();
void operation (int loopAmt, int number);
void afterLoopPrint(int lastNum, int loopNum);

int main() {
	// calls the main program.
	welcomeScreen();
	
	// program finishes if user inputs 0 in welcomeScreen.
	return 0;
}

void welcomeScreen(){
	// clears cmd screen in case of previous entries.
	system("cls");
	
	printf("COLLATZ CONJECTURE SIMULATION PROGRAM\n");
	printf("made by: BRENT KYRJEH ABENIR\n\n");
	
	printf("\n---------------\n\n");
	
	// declare int for user-define result loop amt.
	int loopAmt = 0;
	
	// declare starting number.
	int number = 0;
	
	printf("Enter a starting number. 0 to exit. \n>>> ");
	scanf("%d",&number);
	
	if(number == 0){
		return;
	}
	
	printf("\nEnter max amount of results \n>>> ");
	scanf("%d",&loopAmt);
	
	printf("\n---------------\n\n");
	
	operation(loopAmt, number);
}

void operation (int loopAmt, int number){
	// declare loop repititions.
	int i = 0;
	
	// declare 4-2-1 loop detection storage.
	int problemStart = 0;
	
	int collatzLoop = 0;
	
	for(i = 0;i < loopAmt;i++){
		
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
	
	// failsafe check if the calculation was lacking.
	
	if(lastNum > 4){
		// if program did not found the desired sequence, error message will appear.
		printf("Error! Collatz Sequence not found!\n");
	} else {
		// else, prints out the starting number of Collatz Sequence.
		// validation for loop number integrity (avoid 'glitch').
		if(lastNum < 10){
			printf("The 4-2-1 Collatz Sequence started at result #%d\n", loopNum-1);
		} else{
			printf("The 4-2-1 Collatz Sequence started at result #%d\n", loopNum-10);
		}
	}
	
	// waits for user's ENTER key.
	printf("Press [Enter] to continue... ");
	getch();
	
	// loops the program back to start.
	welcomeScreen();
}