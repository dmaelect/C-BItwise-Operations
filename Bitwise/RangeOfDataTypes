/*
    A program to print range of various integer like data types in C on a machine
    Author : Bhalchandra Gholkar
    Date : 23/01/2018
    Level: Beginner 
 */
#include <stdio.h>
#define SIZE(x) sizeof(x)*8

void signed_data(int);
void unsigned_data(int);

void main()
{
    printf("\nRange of int data type is ");
    signed_data(SIZE(int));
    printf("\nRange of unsigned int data type is ");
    unsigned_data(SIZE(unsigned int));
    printf("\nRange of char data type is ");
    signed_data(SIZE(char));
    printf("\nRange of unsigned char data type is ");
    unsigned_data(SIZE(unsigned char));
    printf("\nRange of short data type is ");
    signed_data(SIZE(short));
    printf("\nRange of unsigned short data type is");
    unsigned_data(SIZE(unsigned short));

    printf("%d\n",sizeof(int));

}

void signed_data(int count)
{
    int min, max, num;
    num = 1;
    while (count != 1)
    {
        num = num << 1;
        count--;
    }
    min = ~num;
    min = min + 1;
    max = num - 1;
    printf("\t\t%d to %d\n", min, max);         // prints the range of unsigned
}

void unsigned_data(int count)
{
    unsigned int min, max, num = 1;

    while (count != 0)
    {
        num = num << 1;
        count--;
    }
    min = 0;
    max = num - 1;
    printf("\t%u to %u\n", min, max);           // prints the range of unsigned
}
