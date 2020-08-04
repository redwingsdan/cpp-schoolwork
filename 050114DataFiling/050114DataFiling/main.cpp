#include <stdio.h>
#include<math.h>
#include<stdlib.h>

#define size 270
#define pi 3.14

int main()
{
	FILE *ptr;
	int i;
	float deg=0,rad;
	float sineValue[size];

	ptr=fopen("sineValue.xls", "w");

	for(i=0;i<size;i++)
	{
		rad=deg*pi/90;
		sineValue[i]=sin(rad);
		deg=deg+1.0;
	}

	for(i=0;i<size;i++)
	{
		fprintf(ptr,"%f\n",sineValue[i]);
	}
	fclose(ptr);

	system("sineValue.xls");

	return 0;
}
