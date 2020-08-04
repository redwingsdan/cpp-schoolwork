#include <stdio.h>

int main()
{
	float r,req=0;
	int i,n;

	printf("Please enter the total number of resistors:  ");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
	printf("Please enter a value for r:  ");
	scanf("%f",&r);
	printf("r(%d)=%.2f\n",i,r);			//optional, specifies the resistance number as well as its value
	req=req+r;
	}
	printf("The equivalent resistance for %d resistors is:  %16.2f\n\n",n,req);		//16.2 is left justification of 16 characters and 2 decimal places shown

	return 0;
}