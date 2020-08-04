/*
#include<stdio.h>

int main()
{
	int i=1,n,f=1;	//initializing and declaring variables
	printf("Please type on the keyboard a value for n:  ");	//asks the user to input a value for n
	scanf("%d",&n);		//reads and assigns the entered value for n
	
	printf("The value for n is %d\n",n);	//prints the value for n back to the 

	while(i<=n)
	{
		f=f*i;
		i=i+1;
		printf("\n%d\n",f);
	}
	printf("\nThe factorial of %d is %d\n",n,f);
	return 0;
}
*/


/********************************************************************************************/
/*					 Computing the area of a rectange with user-specified			    	*/
/*					 length and height values for the rectange								*/
/********************************************************************************************/

#include<stdio.h>

int main()
{
	float a,b,c;	//a is length, b is height, c is area
	
	while(1)		//says that as long as the values are true, the looping will continue infinitely
	{
	printf("Please enter the length and width of the rectangle:   ");
	scanf("%f %f",&a,&b);

	c=a*b;
	if(c==25)
	{
		printf("");
	}
	else
	{
	printf("\nThe area of length %.2f and width %.2f is %.3f\n",a,b,c);		//.2 changes the amount of decimal spaces shown to two
	}
	}
	return 0;
}
