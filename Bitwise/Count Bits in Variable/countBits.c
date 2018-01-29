/*
Date
Name         Daryl Newell
Description  Count the number of 1's in a binary integer.
Source       Me
*/

/*
	Set up an integer, 
	write a function that will look at each bit in that value.
	count the ones and zeros, store the count of each in a variable, int ones, zeros
	Use the printBinary() function to print out the binary
*/

//---------------------------------Includes------------------------------------
#include <stdio.h>
#include "PrintBinary.h"    //--this needs to be added to the project
//---------------------------------Macros-------------------------------

#ifndef UINT
#define UINT unsigned int
#endif

#ifndef BYTE
#define BYTE 8
#endif

#define BIT_SIZE32 (sizeof(UINT) * BYTE)
//--------------------------------Functions------------------------------------
void CountBits(UINT _n);

int main(int argc, char* argv[])
{
//	int test = 0;
//	UINT zeros = 0, ones = 0;                 //-- Unsigned ints to hold the ones and zero counts
	UINT x = 0xFFFAFFFF;		    //-- test input
	int  y = 0xFFFAFFFF;        //-- test input



	CountBits(y);               //-- count the bits in the variable "y"



	getchar();
	return 0;
}

//-- Use the shift op to check each bit of the "number" being passed in for ones
//-- and zeros using an if() statement
void CountBits(UINT number)
{
	int i = 0;
	UINT ones = 0, zeros = 0;
	UINT bitMask = 1 << (BIT_SIZE32 - 1);   //-- move the 1 mask to the MSB of a 32 bit #

	printBinary(number);                    //-- display the binary pattern

	for(i = 0; i < BIT_SIZE32; ++i)
	{
		if(number & bitMask) {
			ones += 1;                    //-- Add up the "ones"
		}

		if((number & bitMask) == 0){
			zeros += 1;                   //-- Add up the "zeros"
		}
		bitMask >>= 1;                  //-- move the mask bit to the right on
										                //-- each loop iteration to test the next bit.
	}

	printf("\nThere are %u ones and %u zeros in the above bit pattern ", ones, zeros);


}
