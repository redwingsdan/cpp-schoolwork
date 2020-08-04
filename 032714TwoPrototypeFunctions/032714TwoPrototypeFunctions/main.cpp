#include<stdio.h>

void computingArea(float a,float b)
{											
	float A;
	A=a*b;
	printf("\na=%.2f\tb=%.2f\tA=%.2f\n",a,b,A);
											
}

void input(float a, float b)
{
	printf("Enter a value of a:  ");
	scanf("%f",&a);

	printf("Enter a value of b:  ");
	scanf("%f",&b);

	computingArea(a,b);
}

int main()
{
	float a,b;

	input(a,b);

	return 0;
}

