#include <stdio.h>
#define pi 3.14				//did not include <math.h>  "Missing Statement"

int main()
{
float i,deg,rad,sinValue,tanValue		//need statement int i; for i

for (i=0;;i=i+1)			//No final value means that there is an infinite loop NOT AN ERROR
{
	printf("Please enter a value for angle in degrees:  ");
	scanf("%.2f",deg);		//there is no & for the degrees and can't have the .2 in front of the f value in scanf
	rad=deg*pi/180;
	sinValue=sin(rad);
	tanValue=tan(rad);

	printf("sin %.2fdeg = %.2f\ttan%.2fdeg = %.2f\n\n",deg,sinValue,deg,tanValue); 
}

return 0;
							//Missing the closing parenthesis for main function