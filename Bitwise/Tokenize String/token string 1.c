 /*
 Date:         07/06/17
 Description:  Use Bitwise to shift bits left to tokenize a string array entered
			   by the user. Store each token from the string to a 2D array.
			   Print out each token in the 2D array to the display
 Source:       Daryl Newell
 */

#include <stdio.h>
#include <conio.h>	// for clrscr() function

void strToken(char *strArry);

 int main(int argc, char* argv[])
{
	char strArry[81] = {};         //-- declare and initialize string array
	char strTokens[81][15] = {};   //-- store up to 80 tokens up to 14 chars long
	char *p = strArry;
	int i = 0;

	printf("Enter a string < 80 chars or less > of both upper and lower case letters\n");
	scanf("%80[ a-zA-Z^\n]s", strArry);   //-- get a string from user up to 80 chars and stop on '\n'
                                              //-- I modified this to only allow: spaces, up and lower Alphabet only

	strToken(strArry);             //-- tokenize the string array

	//-----------------------------Load tokens into the 2D array of tokens
	i = 0;
	while(*p != '\0')
	{
		strcpy(&strTokens[i++][0], p); //-- copy each token into an array of tokens
		while(*p++ != '\0'){}          //-- increment the pointer until '\0' is reached
	}
	//------------------------------End Load Tokens

	//------------------------------Print tokens from 2D array of tokens
	i = 0;
	while(strTokens[i][0] != '\0')
	{
		printf("token %d is %s\n", i, &strTokens[i++][0]);
	}
	//------------------------------End Print tokens

    i = 0;

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
		}                             //-- This value gets stored in place of the
	}                                 //-- "space" (' ') that typed in the string
}
