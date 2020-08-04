#include <stdio.h>
#define M 2
#define N 3

void tNumber(int xPtr);		//need * in front of xPtr

int main()
{
	int i,j;
	int x[M][N]={{1,2,3},{4,5,6}};
	int *xPtr;
	xPtr=&x;				//cant do that for 2D array. Must be &x[0][0]
	tNumber(x[0][0]);		//must put & before the x
	
	return 0;

}

int tNumber(int *xPtr)		//must use void since printing from prototype function
{
	int i,k,sum;
	int x[M][N],tNumber[M][N];
	int *tNumPtr = &tNumber[0][0];

	for(i=0;i<M*N;i++)
	{
		sum=10;				//sum must start at 0
		for(k=1;k<= *(xPtr+i);k++)
		{
			sum+=k;
		}
		*(tNumPtr+i) = sum;
	}
	for(i=0;i<N*M;i++)
	{
		printf("x[%d][%d]=%d\t\ttNumber[%d][%d]=%d\n",i/M,i%N,*(xPtr+i),i/M,i%N,*(tNumPtr+i));
	}
	printf("\n");
}