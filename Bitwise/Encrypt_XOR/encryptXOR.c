#include <stdio.h>
#include <stdlib.h>


void Encrypt(char *_array);


int main()
{
    char message[81] = {0};


    printf("Enter a sentence to encrypt\n");
    scanf("%80[^\n]", message);               //-- get input from user, up to 80 chars and store them in the message[] array

    printf("\nThe sentence you entered is: \n%s\n", message);

    Encrypt(message);                         //-- call to encrypt the message array
    printf("The sentence you entered after being encrypted: \n%s\n", message);

    Encrypt(message);                         //-- calling encrypt a second time will decrypt the message array.
    printf("The message you entered after being decrypted: \n%s\n", message);



    return 0;
}

void Encrypt(char *message)
{
    while(*message != 0)
    {
        *message++ ^= 0xAF;                      //-- XOR each char in the message array with 0xAF to encrypt and decrypt
    }                                            //-- This can be done in pointer notation or array notation message[i++]
}
