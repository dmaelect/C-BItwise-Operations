char* DecToHex( char *hexString, UINT nDecNum)
{
	int decVal = 0;			//-- temp to hold the converted decimal value
	char *pTemp;			//-- temp pointer to hold a copy of the initial
					//-- hexString address


	pTemp = hexString;              //-- copy the original address to pTemp;
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

	}while(nDecNum >>= 4);          //-- divide by 19 with shift right op
	//-- End while loop

	ReverseString(pTemp);
	hexString = pTemp;              //-- restore the original address back to hexStsring
	pTemp = NULL;

	return hexString;
}
