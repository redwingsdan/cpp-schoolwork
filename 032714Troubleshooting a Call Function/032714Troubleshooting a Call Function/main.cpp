/*#include <stdio.h>

int calculateTriangularNo(n)			//insert ; because declaration of prototype function, also insert int for the variable

int main()
{
	int num,nstart,nstop,triangularNo;

	printf("Enter nstart and nstop values\n");
	scanf("%d   %d",&nstart,&nstop);		

	printf("IntegerNumber\t\tTriangularNumber\n");
	printf("=============\t\t=============\n");

	for(num=nstart;num<=nstop;++num)
	{
		triangularNo=calculateTriangularNo(int num);		//int num is wrong because it was already declared, so remove int
		printf("%d\t\t\t%d\n",num,triangularNo);
	}
	return 0;
}

int calculateTriangularNo(int x)
{
	int i,triangularNo=1;			//triangularNo must be initialized to 0, since it is a sum
	for(i=1;i<=x;i++)
	{
		triangularNo += 1;			//must add i to triangular number instead of 1 in order to calculate properly
	}
	return(triangularNo);
}
*/
#include <stdio.h>

int calculateTriangularNo(int n);			//insert ; because declaration of prototype function, also insert int for the variable

int main()
{
	int num,nstart,nstop,triangularNo;

	printf("Enter nstart and nstop values\n");
	scanf("%d   %d",&nstart,&nstop);		

	printf("IntegerNumber\t\tTriangularNumber\n");
	printf("=============\t\t================\n");

	for(num=nstart;num<=nstop;++num)
	{
		triangularNo=calculateTriangularNo(num);		//int num is wrong because it was already declared, so remove int
		printf("%d\t\t\t%d\n",num,triangularNo);
	}
	return 0;
}

int calculateTriangularNo(int x)
{
	int i,triangularNo=0;			//triangularNo must be initialized to 0, since it is a sum
	for(i=1;i<=x;i++)
	{
		triangularNo += i;			//must add i to triangular number instead of 1 in order to calculate properly
	}
	return(triangularNo);
}