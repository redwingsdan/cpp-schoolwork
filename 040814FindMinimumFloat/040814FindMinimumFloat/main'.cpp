#include <stdio.h>

float min(float x1,float x2, float x3, float x4);

int main()
{
	float x1,x2,x3,x4;
		
	printf("Enter four floating point numbers:  ");
	scanf("%f  %f  %f  %f",&x1,&x2,&x3,&x4);

	printf("\nMinimum of numbers %.2f, %.2f, %.2f and %.2f is %.2f\n",x1,x2,x3,x4,min(x1,x2,x3,x4));

	return 0;
}

float min(float x1,float x2, float x3, float x4)
{
	float min;

	min=x1;

	if(x2<min)
	{
		min=x2;
	}
	if(x3<min)
	{
		min=x3;
	}
	if(x4<min)
	{
		min=x4;
	}

	return min;
}