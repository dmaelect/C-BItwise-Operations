/*
 Date:         07/06/17
 Description:  Use Bitwise to shift bits left to tokenize a string array entered
			   by the user. Print out each token of the array to the display
 Source:       Daryl Newell
 */

#include <stdio.h>
#include <conio.h>	// for clrscr() function


 int main(int argc, char* argv[])
{
	char strArry[81] = {};         //-- declare and initialize string array
	char *p = strArry;

	printf("Enter a string < 80 chars or less > of both upper and lower case letters\n");
	scanf("%80[^\n]s", strArry);   //-- get a string from user up to 80 chars and stop on '\n'


	strToken(strArry);             //-- tokenize the string array

	while(*p != '\0')
	{
		puts(p);
		while(*p++ != '\0'){}      //-- increment the pointer until '\0' is reached
	}


	getch();
	return 0;
}


void strToken(char *strArry)
{
	while(*strArry++ != '\0')         //-- Loop until the NULL or end of string
	{
		if(*strArry == ' ')           //-- if space is detected 0010 0000
		{
			*strArry++ <<= 3;         //-- replace the space with NULL by shifting left the bits
									  //-- space = 0010 0000
									  //-- shift the bits left three places
									  //--       = 0000 0000
		}//-- end if()
  }//-- end while()
}//-- end strToken()
