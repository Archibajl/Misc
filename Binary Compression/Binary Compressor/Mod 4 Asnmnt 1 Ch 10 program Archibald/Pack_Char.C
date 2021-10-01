//Justin Archibald
//CSC 230 CSC230C00
//Module 4 Assignment 1 Ch 10 Program

#include <stdio.h>

//Functions that print and pack and print the bits of each input letter.
void printBits(char pacCh[]);
void packCharacters(char pacCh[]);

int main(void) {
	char inCh[4];
	
			//Input for the bit combonation.
		puts("Enter 4 characters to compress the bits.");
		scanf("%c %c %c %c", &inCh[0], &inCh[1], &inCh[2], &inCh[3]);
		
		//Prints the bits of each input character.
		printBits(inCh);

		//Packs and outputs the packed bits of the input characters. 
		packCharacters(inCh);

		system("pause");
}


void printBits(char pacCh[]) {
	char tempCh[4];
	unsigned int cpyMask = 1 << 31;

	//Transfers the input characters to a temporary character array
	//this saves the integrity of the bits from the initial input.
	for (int count = 0; count <= 3; count++) {		
		tempCh[count] = pacCh[count];		
	}

	//Prints the binary of the input letters through a loop.
	printf("Your variable is: %c \n", pacCh[0]);
	for (unsigned int count = 1; count <= 32; count++) {
		//Tests for 1 values and outputs the appropriate response.
		putchar(tempCh[0] & cpyMask ? '1' : '0');
		//Increments the bit, to test the next one.
		tempCh[0]<<=1;
		//Outputs space to show each byte.
		if (count % 8 == 0) {
			putchar(' ');
		}
	}
	puts("");

	//Prints out bits of the second input character.	
	printf("Your variable is: %c \n", pacCh[1]);
	for (unsigned int count = 1; count <= 32; count++) {
		putchar(tempCh[1] & cpyMask ? '1' : '0');
		tempCh[1]<<=1;
		if (count % 8 == 0) {
			putchar(' ');
		}
	}
	puts("");

	//Prints out bits of the third input character.
	printf("Your variable is: %c \n", pacCh[2]);
	for (unsigned int count = 1; count <= 32; count++) {
		putchar(tempCh[2] & cpyMask ? '1' : '0');
		tempCh[2]<<=1;
		if (count % 8 == 0) {
			putchar(' ');
		}
	}
	puts("");

	//Prints out bits of the forth input character.
	printf("Your variable is: %c \n", pacCh[3]);
	for (unsigned int count = 1; count <= 32; count++) {
		putchar(tempCh[3] & cpyMask ? '1' : '0');
		tempCh[3]<<1;
		if (count % 8 == 0) {
			putchar(' ');
		}
	}
	puts("");	
}


void packCharacters(char pacCh[]) {
	unsigned int bitStore ;
	unsigned int cpyMask = 1 << 31;

	//Assigns the value of the first character to an int.
	bitStore = pacCh[0];	
	//Packs the bytes from the last 3 characters into a 4 byte int.
	for (unsigned int count = 1; count <= 3; count++) {
		//Int is left shifted 8 bits, to make space for the next 8 bits to be input.
		bitStore = bitStore<<8 | pacCh[count];
	}

	
	//Outputs the packed int's binary bits.
	printf("Your packed variables number is: %d \n", bitStore);
	for (unsigned int count = 1; count <= 32; count++) {
		putchar(bitStore & cpyMask ? '1' : '0');
		bitStore <<=1;
		if (count % 8 == 0) {
			putchar(' ');
		}
	}
	puts("");
}