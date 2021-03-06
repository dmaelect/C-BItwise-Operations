//---------------------------------------------------------------------------

#pragma hdrstop

#include "PrintBinary.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//-- print out the value of n in binary form
//-- uses the bitwise shift op

#define BYTE 8   //--define the number of bits in a byte.
//-- this could also be obtained from your limits.h file by using the macro
//-- CHAR_BIT, in my implamantation that value is 8


void printBinary(unsigned int n)
{
	unsigned int i;
	unsigned mask = 1 << (sizeof(unsigned int) * BYTE) - 1;             //-- move the 1 mask to the MSB of a 32 bit #

	for(i = 0; i < sizeof(unsigned int) * BYTE ; ++i){
		putchar(n & mask ? '1' : '0');   

		if ( (i + 1) % 8 == 0)
			printf(" ");
		n <<= 1;						 //-- shift the mask to the left 1 time per loop pass
	} //-- end for loop
	printf("\n");
} //-- end printBinary
