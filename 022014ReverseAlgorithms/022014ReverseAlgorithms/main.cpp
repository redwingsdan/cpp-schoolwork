/**********************************************************************/
// Design a program in C whihc, when executed, will ask the user to   //
// enter a positive integer number comprised of two or more digits,   //
// and then output on the console a new integer numer whose digits    //
// are the reverse of the original number. This, for example, if the  //
// user inputs the number 1234, the console output should be 4321.    //
/**********************************************************************/

// Modulus the number to get the last digit, then divide the number by 10
// Do this in a loop until all of the digits are accounted for in opposite
// Order. Then print out all of the values recieved.

#include <stdio.h>

int main()
{
	int num, rightDigit, numNew, i=0;

	printf("Enter a positive integer number of 2 or more digits:  ");
	scanf("%d",&num);

	printf("\nThe reversed number to %d is:     ",num);

	while(num!=0)
	{
		i=i+1;
		rightDigit=num%10;
		printf("%d",rightDigit);
		num=num/10;
	}
	printf("\n\n");
	return 0;
}