#include <stdio.h>
#include <math.h>
#define pi 3.14

float sinFunction(float x);
float tanFunction(float y);


int main()
{
	float rad, deg, sinValue, cosValue, tanValue;
	int runmode;

	while(1)
	{
		printf("Please enter a value for angle in degrees:  ");
		scanf("%f",&deg);
		printf("Please enter a value for runmode:  ");
		scanf("%d",&runmode);

		rad=deg*pi/180;

		switch(runmode)
		{
		case(1):
			sinValue=sinFunction(rad);
			printf("Sin(%.2f) degrees = %.2f\n",deg,sinValue);
			break;
		case(2):
			cosValue=cos(rad);
			printf("Cos(%.2f) degrees = %.2f\n",deg,cosValue);
			break;
		case(3):
			tanValue=tanFunction(rad);
			printf("Tan(%.2f) degrees = %.2f\n",deg,tanValue);
			break;
		default:
			printf("Unallowed value, please enter a valid runmode\n");
			break;
		}
	}
	return 0;
}


float sinFunction(float x)
{
	float sinValue;
	sinValue=sin(x);
	return sinValue;
}

float tanFunction(float y)
{
	float tanValue;
	tanValue=tan(y);
	return tanValue;
}
