/*
#include <stdio.h>

int main()

{
	float r, req=0;
	int i,n;

	printf("Please enter the total number of resistors:  ");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("Please enter a value for r:  ");
		scanf("%f",&r);
		printf("r(%d)= %.2f\n",i,r);
		req=req+r;
	}

	printf("The equivalent resistance for %d resistors is %16.2f\n\n",n,req);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

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
*/

#include <stdio.h>

int main()
{
	int n,i,runmode,series,parallel;
	float r,req=0, seq=0;

	while(1)
	{
		printf("Enter the total number of resistors:  ");
		scanf("%d",&n);

		printf("Enter a value for runmode\n0 to compute Req in series, 1 to compute Req in parallel:  ");
		scanf("%d",&runmode);

		series=0;
		parallel=1;

		if(runmode==0)
		{
			req=0;
			for(i=1;i<=n;i++)
			{
				printf("Please enter a value for r:  ");
				scanf("%f",&r);
				printf("r(%d)= %.2f\n",i,r);
				req=req+r;
			}		

		}
		else if(runmode==1)
		{
			seq=0;
			for(i=1;i<=n;i++)
			{
				printf("Please enter a value for r: ");
				scanf("%f",&r);
				printf("r(%d)= %.2f\n",i,r);
				seq+=(1/r);
			}
		seq=(1/seq);
		}
		
		printf("The equivalent resistance for %d resistors is %16.2f\n\n",n,seq);
		
		else
		{
			printf("Please enter a valid runmode.\n");
		}
	}

	return 0;
}