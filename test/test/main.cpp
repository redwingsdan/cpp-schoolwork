#include <stdio.h>

int main()
{
	float r,req=0;
	int n,i;

	printf("Please enter the total number of resistors:  ");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("Please enter a value for r: ");
		scanf("%f",&r);
		printf("r(%d)= %.2f\n",i,r);
		req=req+(1/r);
	}
	req=(1/req);
	printf("The equivalent resistance for %d resistors is %16.2f\n\n",n,req);

	return 0;
}