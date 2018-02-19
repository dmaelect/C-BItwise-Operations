/*
Date         01/16/18
Name         Daryl Newell
Description  Write a program that will convert a decimal number in to its HEX
			 equivalent
Source		 Me
*/
//---------------------------- Includes --------------------------------------
#include <stdio.h>
#include <conio.h>
#include <string.h>				//-- for strlen function
//#include <stdlib.h>


//---------------------------- #define Macros --------------------------------
#define UINT unsigned int
#define MAX_HEX_ARRAY_LENGTH 128


//---------------------------- Function declarations -------------------------
//---------------------------- Begin ReverseString() -------------------------
//-- Reverse the content of the buffer array
void ReverseString(char *buffer)
{
	int nLastIndex = strlen(buffer) - 1;
	int nFirstIndex = 0;
	char ch = 0;

	while(nFirstIndex < nLastIndex)
	{
		ch = buffer[nFirstIndex];
		buffer[nFirstIndex] = buffer[nLastIndex];
		buffer[nLastIndex] = ch;
		nFirstIndex++;
		nLastIndex--;
	}
}
//--------------------------- End ReverseString() -----------------------------


//-------------------------- Begin DecToHex() --------------------------------
//--
//--
//--
//-- I used snprintf() so I would have the formated chars held in the array
//-- that way there is no need to convert it when you want to print it out.
char* DecToHex(char *hexString, UINT nDecNum)
{
	char *pTemp;                    //-- gets returned to the caller
	const int MAX_LEN = 9;			//-- 8 bytes plus the NULL to hold the hexString[]

	pTemp = hexString;              //-- copy the 1st address of hexString
									//-- pTemp will be returned to the caller
	do{
		snprintf(hexString++, MAX_LEN, "%X", (nDecNum % 16));
	}while(nDecNum >>= 4);          //-- shift the bits to the right 4 places
									//-- this is equivalent to dividing by 16

	ReverseString(pTemp);           //-- the hex value is in reverse order. It needs to be flipped
	hexString = pTemp;				//-- restore the pointer of hexString back to first ellememt

	return hexString;       		//-- return the address so it can be used in a printf() call
}
//---------------------------- End DecToHex() --------------------------------




//---------------------------- Begin Main ------------------------------------
int main(int argc, char* argv[])
{
	char ch = 0;
	char hexString[MAX_HEX_ARRAY_LENGTH] = {0};
	unsigned int x = 0;                //-- 4294967295 this is 2^32 - 1. it is the max value of an UINT


	do
	{
		printf("Enter a positive Decimal number to convert into Hex\n");
		scanf("%u", &x);
		fseek(stdin, 0, 0);     //-- Set the stdin file pointer back to 0
								//-- this effectivley clears the input buffer
		//-- load each hex char value for HEX into the hexString Array. and print it out
		printf("\n%u is 0x%s in HEX \n", x, DecToHex(hexString, x));

		printf("\n\nPress 'q' to quit... OR \nPress ANY key to continue...\n");

		ch = getch();                          //-- wait for keypress
		fseek(stdin, 0, 0);
		clrscr();

	}while( ch != 'q');



	return 0;
}
//-------------------------- End Main() --------------------------------------
