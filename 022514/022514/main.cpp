/*
#include <stdio.h>
#include <math.h>		//needed to use "pow"

int main()
{
	float x=10,y=2,z;	//float for decimals

	z=pow(x,y);			//exponents of x to the y
	
	printf("x^y=%.2f\n",z);	//prints with 2 places after decimal

	return 0;
}

*/
/*
#include <stdio.h>
#define pi 3.14

int main()
{
	float radius, area;
	int i=1;

	while(i<=10)
	{
		printf("Enter radius of circle:   \n");
		scanf("%f",&radius);

		area=pi*radius*radius;
		printf("\nRadius=%10.2f\t\tArea=%10.2f\n",radius,area);
		i++;
	}
	return 0;
}
*/
/*********************************************************/
/* Design a program in C which will produce a computation*/
/* pf the tangent of a user specified angle in degrees   */
/*********************************************************/

#include <stdio.h>
#include <math.h>
#define pi 3.14

int main()
{
	float degrees,radians,tanValue;		//declares variables
//insert while(1) here to make it infinite
	printf("Enter a value for angle in degrees:  ");	
	scanf("%f",&degrees);				//reads value for degrees in float

	radians=(degrees*pi)/180;			//converts the degrees to radians
	tanValue=tan(radians);				//takes the tangent value of radians

	printf("Angle in deg = %.2f\ttan of %.2f deg = %.2f\n\n",degrees,degrees,tanValue);		//prints the degrees, and its tangent

	return 0;
}