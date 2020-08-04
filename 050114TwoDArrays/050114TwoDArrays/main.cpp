#include <stdio.h>
#define M 2
#define N 3

void tNumber(int xPtr);

int main()
{
	int i,j;
	int x[M][N]={{1,2,3},{4,5,6}};
	int *xPtr;
	xPtr=&x[0][0];

	for(i=0;i<M*N;i++)
	{
		printf("\nx[%d][%d]=%d\n\n",i/M,i%N,*(xPtr+i));
	}
	return 0;
}