/*
#include <stdio.h>

int xFunction(num)			//int num within parenthesis
{
	int num, xNumber=1;		//want xNumber to be equal to 0 because its addition series, no need to initialize num again
	int i;

	for(i=1;i<=num;i++)
	{
		xNumber=xNumber+1*i;
		printf("The xNumber of %d is %d\n",num,xNumber);		//move to main because can't print within call function unless void is present
	}
	return 0;				//return xNumber;
}

int main()
{
	int num,xNumber;
	while(1)
	{
		printf("Enter a positive integer number:  ");
		scanf("%d",&num);
		xNumber=xFunction(num);
	}
	return 0;
}

*/

#include <stdio.h>

int xFunction(int num)			//int num within parenthesis
{
	int xNumber=0;		//want xNumber to be equal to 0 because its addition series, no need to initialize num again
	int i;

	for(i=1;i<=num;i++)
	{
		xNumber=xNumber+i*i;
	}
	return xNumber;          
}

int main()
{
	int num,xNumber;
	while(1)
	{
		printf("Enter a positive integer number:  ");
		scanf("%d",&num);
		xNumber=xFunction(num);
		printf("The xNumber of %d is %d\n",num,xNumber);
	}
	return 0;
}