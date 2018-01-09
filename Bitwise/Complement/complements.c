/*
	Daryl Newell 11/10/17
	various opperation to show how to use bitwise opps to accomplish
	math tasks,
	how to clear the value of a variable with xor on itself.
	Take ones compliment with the xor
	Take two's compliment by adding one to the One's compliment.
*/

#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include "To_Binary.h"          //-- this is not a standard funciton and it needs to be included in the project. with "To_Binary.c"


//-- check to see if we are on a 32bit compiler or 64 bit. this is needed in the
//-- Ones() function


//-- prototype of functions

#idndef UINT
#define UINT unsigned int;           //-- define an unsigned int as UINT
#endif

UINT DoubleIt(UINT _x);              //-- DoubleIt the value passed in with shift left op
UINT OnesComplement(UINT _x);	     //-- claculate the one's complement via the xor op
UINT TwosComplement(UINT _x);	     //-- claculate the two's complement by calling "ones" and
			             //-- adding the value of 1 to that result

int main(int argc, char* argv[])
{
	 UINT x = 7;
	 UINT j = 0;
//	 UINT i = 5 ;   //

#if 0
	printf("%d in binary is ", x);
	printBinary(x);
	printf("\n");
#endif

#if 0
//	x ^= x
//-- print out the one's complement in binary using the built in op
	printf("The one's comp of %d is %d ", x, (j = ~x));
	printBinary(OnesComplement(x));
//-- print out the two's complement of x in binary using my bitwise function
	puts("\n");
	printf("The two's comp of %d is %d ", x, TwosComplement(x));

	printBinary(TwosComplement(x));
	printf("\n");
#endif

#if 1
		//-- print out the value of x then DoubleIt it. and print that value
	printf("The value of %d Doubled by shift operator is %d ", x, DoubleIt(x));

	j = DoubleIt(x);        //-- double x and assign the value to j

	printf("\n\n");
	printf("%d in binary is ", j);
	printBinary(j);        //-- print the value of j in binary
#endif

	getchar();
	return 0;
}

//-- function that takes an int.
//-- that int willbe doubled by using the left shift operator.
UINT DoubleIt(UINT x)
{
	return x << 1;
}


//-- function to invert the bits by using the xor operator
//-- xor the int variable the is sent in with all 1's. This will cause the bits
//-- in the original operand to become inveretd in the returned result
UINT OnesComplement(UINT x)
{

#if _WIN32                 //-- xor with 32 bit number
	return x ^ 0xffffffff;
#endif

#if _WIN64                 //-- xor with 64 bit number
	return x ^ 0xffffffffffffffff;
#endif
//	return 0;
}


//-- Function that takes an int
//-- it then calls the ones function to invert all the bits and adds one to that
//-- value and returns the two's complement
UINT TwosComplement(UINT x)
{
	return OnesComplement(x) + 1;
}
