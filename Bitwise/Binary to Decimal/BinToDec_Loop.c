
/*
Date  		 11/13/17
Name         Daryl Newell
Description  A program to convert a binary string into Decimal with a repeat loop
Source       Me
*/

#include <stdio.h>
#include <math.h>         //-- for pow()
#include <string.h>       //-- for strlen()
#include <conio.h>        //-- for clrscr()

//-- define the max length of my binary string arrays as:
#define STR32 33
#define STR64 65
#define STR16 17
#define STR8 9

//-- 2^0 = 1, 2^1 = 2, 2^2 = 4, 2^3 = 8, 2^4 = 16, 2^5 = 32, 2^6 = 64, 2^7 = 128
int BinToDec(char *);

int main(int argc, char* argv[])
{
//	int decVal = 0;
	char ch = 0;
	char cBinArry[STR32] = {0};      //-- hold 32 bit binary values in a string
//-----------------------------End Vars----------------------------------------

	clrscr();

	do
	{
		printf("Enter the binary number to be converted to Decimal: ");
		fgets(cBinArry, STR32, stdin);          //-- limit the length of the input to STR32

		cBinArry[strlen(cBinArry) - 1] = '\0';  //-- clear the '\n' from the array


	//	decVal = BinToDec(cBinArry);          //-- Send the contents of array for conversion

		printf("The Decimal value of %s is: %d ", cBinArry, BinToDec(cBinArry));
		printf("\n\nPress 'q' to quit... OR \nPress ANY key to continue...\n");


		ch = getch();                        //-- wait for keypress
		fflush(stdin);                       //-- clear the input buffer

		clrscr();                            //-- clear the screen
	}while(ch != 'q');                     //-- quit on 'q'


//	getchar();
	return 0;
}


int BinToDec(char *buffer)
{
	int i = 0;                             //-- iterator counter
	int strLen = 0;                        //-- length of the string buffer
	int decVal = 0;                        //-- decimal value

	strLen = strlen(buffer) - 1;           //-- get the length to the buffer minus the NUL

	while(buffer[i] != '\0')
	{
		if(buffer[i++] == '1')
		{
			decVal += pow(2, strLen);        //-- raise 2 to the power of the value
		}                                  //-- held by strLen, this is the position
		strLen--;                          //-- of the "1" in the buffer string array
	}

	return decVal;                       //-- return the decimal value to caller
}
