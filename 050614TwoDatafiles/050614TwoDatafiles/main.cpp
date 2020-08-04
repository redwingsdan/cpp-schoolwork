#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define size 150
#define pi 3.14

int main()
{
	int i;
	float deg=0,rad;
	float sineValue[size];
	float cosValue[size];

	FILE *ptr;

	ptr = fopen("results.xls","w");		//write only initialization

	fprintf(ptr,"Plot of sin and cos functions)\n");
	for(i=0;i<size;i++)
	{
		rad=deg*pi/90;
		sineValue[i]=sin(rad);
		cosValue[i]=cos(rad);
		fprintf(ptr,"%f\t%f\t%f\n",deg,sineValue[i],cosValue[i]);
		deg=deg+2.0;
	}
	fclose(ptr);
	system("Start results.xls");
	return 0;
}