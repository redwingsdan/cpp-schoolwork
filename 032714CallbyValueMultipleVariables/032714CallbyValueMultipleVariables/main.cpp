#include<stdio.h>

void computingArea(float a,float b)			//void means that output takes place within the prototype function
{											//if add float instead of void
	float A;
	A=a*b;
	printf("\na=%.2f\tb=%.2f\tA=%.2f\n",a,b,A);
											//add a return A; line and comment the printf out
}

int main()
{
	float a,b;				//initialize float A here
	printf("Enter a value of a:  ");
	scanf("%f",&a);

	printf("Enter a value of b:  ");
	scanf("%f",&b);

	computingArea(a,b);
							//add A=computingArea(a,b)
							//move the print statement to here

	return 0;
}

