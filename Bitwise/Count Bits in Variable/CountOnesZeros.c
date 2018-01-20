/*
Date
Name         Daryl Newell
Description  Count the number of 1's in a binary integer.
Source       Me
*/

/*
	Set up an integer, get integer value from user
	write a function that will look at each bit in that value.
	count the ones and zeros store the count of each in a variable, int ones, zeros
	Use the DecToBin function to print out the binary
*/

//---------------------------------Includes------------------------------------
#include <stdio.h>

#include "To_Binary.h"               //-- this is needed to run the tests and print out the binary pattern.
                                     //-- it is not required to do it but I prefer it.
//---------------------------------Macros-------------------------------
#ifndef UINT
#define UINT unsigned int           //-- define an unsigned int
#define BYTE 8                      //-- define a byte size
#define BIT_SIZE32 (sizeof(UINT) * BYTE)   //-- easier to type BIT_SIZE32
#endif
//--------------------------------Functions------------------------------------
int CountBits(UINT _n, UINT *_nOnes, UINT *_nZeros);

int main(int argc, char* argv[])
{
	int test = 0;
	UINT zeros = 0, ones = 0;                 //-- the sum of ones and zeros, does not need to be UINT
	UINT i = 0, x = 0xFFFAFFFF;               //-- test input vars
        UINT bitMask = (1 << (BIT_SIZE32 - 1));   //-- move the 1 mask to the MSB of a 32 bit #
	int y = 0xFFFAFFFF;                       //-- Test input vars

//	printBinary(y);

	CountBits(y, &ones, &zeros);

	printf("\nThere are %u ones and %u zeros in the above bit pattern ", ones, zeros);

	getchar();
	return 0;
}

//-- Use the shift op to check each bit of the "number" being passed in for ones
//-- and zeros using an if() statement
int CountBits(UINT number, UINT *_ones, UINT *_zeros)
{
	UINT i = 0;
	UINT bitMask = 1 << (BIT_SIZE32 - 1);       //-- move the 1 mask to the MSB of a 32 bit #

	printBinary(number);                        //-- Display the binary bit pattern

	for(i = 0; i < BIT_SIZE32; ++i)
	{
/*-------------------------    For testing only  -----------------------------------
//		printf("%u", (number & bitMask));
//		printBinary(bitMask);
---------------------------    End Testing only  ------------------------------------*/
    if(number & bitMask) {
			*_ones += 1;                 //-- Add up the "ones"
		}

		if((number & bitMask) == 0){
			*_zeros += 1;                //-- Add up the "zeros"
		}
		bitMask >>= 1;                       //-- move the mask bit to the right on 
		                                     //-- each loop iteration to test the next bit
	}


	return number;
}
