/************************************************************/
/* Illustrating a call or prototype function. One prototype */
/* function will be used whose job will be to compute the   */
/* square of an integer number. Here the call function will */
/* be placed before the main function. It can also be placed*/
/* after the main function, but then one has to use one     */
/* additional step.                                         */
/************************************************************/
/*
#include <stdio.h>

void squaring(int x)
{
	int xsq;
	xsq=x*x;
	printf("The square of x=%d is xsq=%d\n\n",x,xsq);
}

int main()
{
	int x,xsq;
	printf("Enter a value for x:  ");
	scanf("%d",&x);
	printf("\nx=%d\n",x);
	squaring(x);

	return 0;
}

*/

#include <stdio.h>

void squaring(int x); //change void to int to return to the main function


int main()
{
	int x,xsq;
	printf("Enter a value for x:  ");
	scanf("%d",&x);
	printf("\nx=%d\n",x);
	squaring(x); //xsq=squaring(x);

	return 0;
}

void squaring(int x)				//change void to int in order to return to the main function
{
	int xsq;
	xsq=x*x;
	printf("The square of x=%d is xsq=%d\n\n",x,xsq);  //move to below squaring in main
	//return xsq;
}