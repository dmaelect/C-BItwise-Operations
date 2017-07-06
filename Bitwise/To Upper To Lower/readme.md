Usese Bitwise to convert charactors to upper and lower case.
One function uses array notation to iterate the string array 
and the other function uses pointer notation.
This works because the hex value for lower case letters and upper case letters are the same except for bit 5
If bit 5 is 1 then the letter is lower case. We then mask the 8 bit letter with 0010 0000 by OR-ing it. This turns on bit 5
If bit 5 is 0 then the letter is upper case. We then unmask the 8 bit letter with 1101 1111 by AND-ing it. This turns off bit 5
