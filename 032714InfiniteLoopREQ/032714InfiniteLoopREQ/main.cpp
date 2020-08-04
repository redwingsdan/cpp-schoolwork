#include<stdio.h>

float reqSeries(int nR)
{
	int i;
	float req=0,r;
	
	for(i=1;i<=nR;i++)
	{
		printf("Enter the value of a resistor:  ");
		scanf("%f",&r);
		req += r;
	}
	return req;
}
	
int main()
{
	float r,req;
	int nR;

	while(1)
	{
		req=0;
		printf("Enter the number of resistors:  ");
		scanf("%d",&nR);
		req=reqSeries(nR);
		printf("The desired equivalent resistance is %.2f\n", req);

	}
	return 0;
}
