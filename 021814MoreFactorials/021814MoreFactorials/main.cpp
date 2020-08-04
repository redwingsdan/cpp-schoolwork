#include <stdio.h>

int main()
{
	int n,nstart,nstop,nstep,i,j,fNum;
	printf("Pleae enter a positive integer nstart:  ");
	scanf("%d",&nstart);
	printf("Please enter a postive integer nstop:  ");
	scanf("%d",&nstop);
	printf("Please enter a positive integer nstep:  ");
	scanf("%d",&nstep);

	printf("Number\t\tfNum\n");
	printf("------\t\t----\n");

	n=nstart;
	
	
	{
		while(n<=nstop)
		{
	if(n%2==0)
	{
		fNum = 1;
		i=1;
		while(i<=n)
			{
			fNum*=i;
			i++;
			}
		printf("%d\t\t%d\n\n",n,fNum);
		
		}
		n+=nstep;
		}
	
	}
	return 0;
}