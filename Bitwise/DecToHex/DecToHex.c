
/*
Date         01/16/18
Name         Daryl Newell
Description  Write a program that will convert a decimal number in to its HEX
			 equivalent
Source		 Me
*/
//---------------------------- Includes --------------------------------------
#include <stdio.h>
//#include <cstdio.h>
#include <string.h>

//---------------------------- #define Macros --------------------------------
#define UINT unsigned int
#define MAX_HEX_ARRAY_LENGTH 128

//---------------------------- Function declarations -------------------------
void printBinary(unsigned int);
char* DecToHex(char *, UINT);
void ReverseString(char *);

//---------------------------- Begin Main ------------------------------------
int main(int argc, char* argv[])
{
	char hexString[MAX_HEX_ARRAY_LENGTH] = {0};
	unsigned int x = 4294967295;   // this is 2^32 - 1. it is the max value of an UINT
	char buffer[100];
	int pos = 0, level = 0;
//	int cx;

	printf("Enter a positive Decimal number to convert to Hex\n");
	if(scanf("%u", &x)){               //-- upon entering data, reset the stdin *FP back to "zero"
		pos = fseek(stdin, 0, 0);      //-- this will clear the input buffer, ready for new input
		}
//	pos = ftell(stdin);
//	level = stdin->level;

	//-- load each hex char value for HEX into the hexString Array.
	printf(" %u is 0x%s in HEX \n", x, DecToHex(hexString, x));



	getchar();
	return 0;
}
//-------------------------- End Main() --------------------------------------


//-------------------------- Begin DecToHex() --------------------------------
//--
//--
//--
//-- I used snprintf() so I would have the formated chars held in the array
//-- that way there is no need to convert it when you want to print it out.
char* DecToHex(char *hexString, UINT nDecNum)
{
	char *pTemp;                    //-- gets returned to the caller
	int nStrLength = 0;             //-- to hold the number of bytes written
	const int MAX_LEN = 9;			//-- 8 bytes plus the NULL to hold the hexString[]

	if(nDecNum < 1)                 //-- test for invalid inpout
		return "  --- ERROR - invalid input   ---   ";

	pTemp = hexString;              //-- assign the address of hexString to pTemp

	do
	{
	nStrLength += snprintf(hexString++, MAX_LEN, "%X", (nDecNum % 16));
//		pHexString++;
	}while(nDecNum >>= 4);         //-- shift the bits to the right 4 places
								   //-- this is equivalent to dividing by 16
	ReverseString(pTemp);          //-- the hex value is in reverse order. It needs to be flipped

	return pTemp;        //-- return the address so it can be used in a printf() call
}
//---------------------------- End DecToHex() --------------------------------


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


//-- This function is not needed here. it can be removed if desired.
void printBinary(unsigned int n)
{
	unsigned int i;
	unsigned mask = 1 << 15;             //-- move the 1 mask to the MSB of a 32 bit #
	for(i = 0; i < sizeof(unsigned int) * 4 ; ++i){
		putchar(n & mask ? '1' : '0');             //if ((n & (mask >> i)) == (mask >> i))

		if ( (i + 1) % 8 == 0)
			printf(" ");
		n <<= 1;						 //-- shift the mask to the left 1 time
	} //-- end for loop
	printf("\n");
} //-- end printBinary
