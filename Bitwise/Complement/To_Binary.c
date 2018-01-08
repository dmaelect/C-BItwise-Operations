//---------------------------------------------------------------------------

#pragma hdrstop

#include "To_Binary.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//-- print out the value of n in binary form
//-- uses the bitwise shift op

void printBinary(unsigned int n)
{
	unsigned int i;
	unsigned mask = 1 << 15;             //-- move the 1 mask to the MSB of a 32 bit #
	for(i = 0; i < sizeof(unsigned int) * 4 ; ++i){
		putchar(n & mask ? '1' : '0');   //-- if ((n & (mask >> i)) == (mask >> i))

		if ( (i + 1) % 8 == 0)
			printf(" ");
		n <<= 1;						 //-- shift the mask to the left 1 time
	} //-- end for loop
	printf("\n");
} //-- end printBinar
