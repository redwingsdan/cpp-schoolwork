//Design a protgram using a prototype function placed before
//the main function which will compute the factorial of a 
//user-specified positive integer number. The computed value
//of factorial is to be printed from within the main function

#include <stdio.h>

int factorial(int num)		//declaring function
{
	int fNumber=1;			//declaring variable that will be used in the function
	int i;					//dummy variable for looping
	for(i=1;i<=num;i++)
	{
		fNumber = fNumber*i;
	}
	return fNumber;
}

int main()
{
	int num,fNumber;

	while(1)
	{
		printf("Enter a positive integer number:  ");
		scanf("%d",&num);
		fNumber=factorial(num);
		printf("The factorial of %d is %d\n",num,fNumber);
	}
	return 0;
	
}
