 /*
 Date:         07/06/17
 Description:  Use Bitwise & and | to convert charactors to upper and lower case
 Source:       Daryl Newell
 */

#include <stdio.h>
#include <conio.h>	// for clrscr() function
//#include <iostream>


//const int TO_LOW = 0x20;
//const int TO_UP = 0xDF;

#define TO_LOWER 0x20
#define TO_UPPER 0xDF

void aLower(char *_array);         //-- use array notation to iterate the array
void pLower(char *_array);         //-- use pointer notation to iterate the array
void aUpper(char *_array);
void pUpper(char *_array);

 int main(int argc, char* argv[])
{
	char strArry[81] = {};         //-- declare and initialize string array

	printf("Enter a string < 80 chars or less > of both upper and lower case letters\n");
	scanf("%80[^\n]s", strArry);   //-- get a string from user up to 80 chars and stop on '\n'

	printf("The string of chars you entered are: \n%s\n", strArry);
	aLower(strArry);
	printf("The string of chars after they are converted to lower case: \n%s\n", strArry);
	aUpper(strArry);
	printf("The string of chars after they are converted to upper case: \n%s\n", strArry);

	getch();
	return 0;
}

//-- this function uses array notation to iterate the array.
void aLower(char *strArry)
{
	int i = 0;

	while(strArry[i] != '\0')
	{
		strArry[i++] |= TO_LOWER;
	}
}

//-- this function uses pointer notation to iterate the array
void pLower(char *strArry)
{
	while(*strArry != '\0')           //-- test for NULL in string
	{
		*strArry++ |= TO_LOWER;       //-- bitwise "OR" *strArry with 0x20 - Hex
	}
}

//-- this function uses array notation to iterate the array
void aUpper(char *strArry)
{
	int i = 0;

	while(strArry[i] != '\0')
	{
		if(strArry[i] == ' ')
		{
			i++;
			continue;
		}
        strArry[i++] &= TO_UPPER;
	}
}

//-- this function uses pointer notation to iterate the array
void pUpper(char *strArry)
{
	while(*strArry != '\0')           //-- test for NULL in string
	{
		if(*strArry == ' ')           //-- if the pointer is pointing to a "space"
		{
			strArry++;                //-- incriment the pointer
			continue;                 //-- continue looping
		}
		*strArry++ &= TO_UPPER;       //-- bitwise "and" *strArry with 0xDF - Hex
									  //-- incriment the pointer
	}
}
