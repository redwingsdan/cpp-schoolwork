#include <stdio.h>
#include <math.h>
#define pi 3.14

int main()
{
	float theta1,theta2,theta3,thetastep,n,f1,f2,radians;
	
	//User inputted variables:
	printf("Enter theta1:  ");
	scanf("%f",&theta1);
	printf("Enter theta2:  ");
	scanf("%f",&theta2);
	printf("Enter theta3:  ");
	scanf("%f",&theta3);
	printf("Enter thetastep:  ");
	scanf("%f",&thetastep);
	
	//Headers 
	printf("Theta\t       Radians\t        F1\t        F2\n");
	printf("-----\t       -------\t        --\t        --\n");

	//Loop for computing the F1 function values. Stops at and including theta2. Incremented by thetastep
	for(n=theta1;n<=theta2;n+=thetastep)
	{
		radians=(pi*n)/180;								//converts the degrees in theta to radians
			printf("%-16.2f",n);						//prints the degrees
			printf("%-16.2f",radians);					//prints the converted radians
			f1=sin(radians)+2*cos(2*radians);			//computes the value of F1 using radians
		
		printf("%-16.2f",f1);							//prints the computed value F1
		printf("N/A\n");								//placeholder for F2 values
		
	}
	n+=thetastep;										//increments n so that the second loop begins one thetastep after theta2
	
	//Loop for F2, stops at and including theta3 and starts after theta2
	for(n<theta2;n<=theta3;n+=thetastep)
	{
		radians=(pi*n)/180;
			printf("%-16.2f",n);
			printf("%-16.2f",radians);
			f2=sin(2*radians)-cos(radians);
			printf("N/A");								//placeholder for the F1 value
			printf("%16.2f\n",f2);						//prints the computed F2 value
	}
	
	return 0;
}
