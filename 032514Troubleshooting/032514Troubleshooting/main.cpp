/*
#include <stdio.h>

	int xNumber(int num)		//add ;  , also change xNumber to xFunction

	void main()					//change void to int
	{
		int num,xNumber;		//cannot use variable name that is already used for prototype function (fixed so is ok)

		while(1)
		{
			printf("Enter a value of a positive integer variable");
			scanf("%.2f",&num);	//cannot have %f for int variables and cannot use .2 in scanf
			xFunction(int num); //no need for int because variable type has already been described and set xFunction=xNumber;
			printf("\nThe xNumber of %d is %d\n",num,xNumber);
		}
		return 0;
	}

	int xFunction(x)			//must have int in the declaration statement (int x)
	{
		int xNumber=1,i;
		for(i=1;i<=x;i++)
		{
			xNumber=xNumber*i*i;
		}
								//must include "return xNumber;"
	}
	*/

#include <stdio.h>

	int xNumber(int num);		//add ;  , also change xNumber to xFunction

	int main()					//change void to int
	{
		int num,xNo;		//cannot use variable name that is already used for prototype function (fixed so is ok)

		while(1)
		{
			printf("Enter a value of a positive integer variable:  ");
			scanf("%d",&num);	//cannot have %f for int variables and cannot use .2 in scanf
			xNo = xNumber(num); //no need for int because variable type has already been described and set xFunction=xNumber;
			printf("\nThe xNumber of %d is %d\n",num,xNumber);
		}
		return 0;
	}

	int xNumber(int x)			//must have int in the declaration statement (int x) and the functions must be xFunction-->xNumber
	{
		int xNo=1,i;
		for(i=1;i<=x;i++)
		{
			xNo=xNo*i*i;
		}
			return xNo;				//must include "return xNumber;"
	}