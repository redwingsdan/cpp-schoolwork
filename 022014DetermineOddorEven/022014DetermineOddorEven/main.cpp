//Determine over an infinite loop if a user-specified
//Arbitrary positive integer is odd or even

#include <stdio.h>

int main()
{
	int num=0

		while(1)
		{
			printf("Enter an arbitrary positive integer number:  ");
			scanf("%d",&num);

			if(num==0)
			{
				break