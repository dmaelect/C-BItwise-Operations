
/*
Date         01/16/18
Name         Daryl Newell
Description  Write a program that will convert a decimal number in to its HEX
			 equivalent
Source		 Me
*/
//---------------------------- Includes --------------------------------------
#include <stdio.h>
#include <conio.h>                              //-- for clrscr() function
#include <string.h>				//-- for strlen function
#include <stdlib.h>                             //-- for itoa() funciton


//---------------------------- #define Macros --------------------------------
#define UINT unsigned int
#define MAX_HEX_ARRAY_LENGTH 128


//---------------------------- Function declarations -------------------------
char* DecToHex(char *, UINT);                //-- uses snprintf() and the modulas to do the conversion
char* DecToHex1( char *, UINT );             //-- uses switch() case: and modulas to do the conversion
void ReverseString(char *);                  //-- reverse a char string array


//---------------------------- Begin Main ------------------------------------
int main(int argc, char* argv[])
{
	char ch = 0;
	char hexString[MAX_HEX_ARRAY_LENGTH] = {0};
	unsigned int x = 4294967295;   // this is 2^32 - 1. it is the max value of an UINT
//	char buffer[100];


	do
	{
		printf("Enter a positive Decimal number to convert into Hex\n");
		scanf("%u", &x);
		fseek(stdin, 0, 0);     //-- Set the stdin file pointer back to 0
								//-- this effectivley clears the input buffer
		//-- load each hex char value for HEX into the hexString Array. and print it out
		printf("\n%u is 0x%s in HEX \n", x, DecToHex(hexString, x));

		printf("\n\nPress 'q' to quit... OR \n ANY other key to continue...\n");

		ch = getch();                          //-- wait for keypress
		fseek(stdin, 0, 0);                    //-- clear input buffer
		clrscr();                              //-- requires conio.h

	}while( ch != 'q');


//	getchar();
	return 0;
}
//-------------------------- End Main() --------------------------------------

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

	do{                             //-- convert the nDecNum and store it into hexString
		snprintf(hexString++, MAX_LEN, "%X", (nDecNum % 16));
	}while(nDecNum >>= 4);          //-- shift the bits to the right 4 places
									//-- this is equivalent to dividing by 16


	ReverseString(pTemp);           //-- the hex value is in reverse order. It needs to be flipped
	hexString = pTemp;				//-- restore the pointer of hexString back to first ellememt
	pTemp = NULL;

	return hexString;       		//-- return the address so it can be used in a printf() call
}
//---------------------------- End DecToHex() --------------------------------

//-------------------------- Begin DecToHex1() -------------------------------
//-- This version uses switch() Case: to do the conversion
//-- it does require the stdlib.h header file for the itoa() function
//-- the results of this function is the exact same as that using the snprintf()
//--
char* DecToHex1( char *hexString, UINT nDecNum)
{
	int decVal = 0;			//-- temp to hold the converted decimal value
	char *pTemp;			//-- temp pointer to hold a copy of the initial
							//-- hexString address


	pTemp = hexString;      //-- copy the original address to pTemp;
	do
	{
		decVal = (nDecNum % 16);
		switch (decVal) {
			case 10: *hexString++ = 'A';    //-- convert 10 to A
				break;
			case 11: *hexString++ = 'B';	//-- convert 11 to B
				break;
			case 12: *hexString++ = 'C'; 	//-- convert 12 to C
				break;
			case 13: *hexString++ = 'D';	//-- convert 13 to D
				break;
			case 14: *hexString++ = 'E';	//-- convert 14 to E
				break;
			case 15: *hexString++ = 'F';	//-- convert 15 to F
				break;
			default : itoa(decVal, hexString++, 10);
				break;
		} //-- End Switch

	}while(nDecNum >>= 4);    //-- divide by 16 with shift right op
	//-- End while loop

	ReverseString(pTemp);
	hexString = pTemp;        //-- restore the original address back to hexStsring
	pTemp = NULL;

	return hexString;
}
//-------------------------------- End DecToHex1() ----------------------------
