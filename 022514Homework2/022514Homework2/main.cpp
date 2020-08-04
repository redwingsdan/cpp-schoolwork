/*
#include <stdio.h>

int main()
{
	int n,i,zNumber=0;

	printf("Please enter a value for n:  ");
	scanf("%d",&n);

	i=1;
	while(i<=n)
	{
		zNumber+=(i*i*i);
		++i;
	}

		printf("\nThe zNumber of %d is zNumber(%d)=  %d\n",n,n,zNumber);
		return 0;
}

*/
#include <stdio.h>

int main()
{
	int nstart,nstep,nstop,n,i,zNumber=0;

	printf("Please enter a value for nstart:  ");
	scanf("%d",&nstart);
	printf("\nPlease enter a value for nstep:  ");
	scanf("%d",&nstep);
	printf("\nPlease enter a value for nstop:  ");
	scanf("%d",&nstop);

	i=1;				
	printf("N-Value\t\tzNumber\n");
	printf("-------\t\t-------\n");
	n=nstop;
	while(i<=nstop)
	{
		zNumber=0;
		zNumber+=(i*i*i);
		if(i%2==0)
		{
		printf("%d\t\t%d\n",i,zNumber);
		}
		i=i+1;
	}

		return 0;
}
