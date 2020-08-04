#include <stdio.h>

int main()
{
	int i,nstart,nstep,nstop,zNumber,n;
	printf("Value of nstart: \n");
	scanf("%d",&nstart);
	printf("Value of nstop: \n");
	scanf("%d",&nstop);
	printf("Value of nstep: \n");
	scanf("%d",&nstep);
	printf("i-Number\t\tzNumber\n");
	printf("--------\t\t-------\n");
	i=0;
	n=nstep;

	while(i<=nstop)
	{
		zNumber=0;
		zNumber=(i*i*i);
		if(i%2==0)
		{
			printf("%d\t\t\t%d\n",i,zNumber);
		}
		i=i+n;
	}
	return 0;
}