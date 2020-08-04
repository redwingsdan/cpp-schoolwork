#include <stdio.h>

#define IMAX 2
#define JMAX 3

void tNumber (int *xPtr);
void fNumber (int *xPtr);

int main()
{
	int i,j;
	char oper;
	int x[IMAX][JMAX]={{1,2,3},{4,5,6}};
	int *xPtr;
	xPtr=&x[0][0];
	
	for(i=0;i<IMAX;i++)
	{
		for(j=0;j<JMAX;j++)
		{
			printf("x[%d][%d]=%d\t\t",i,j,x[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Enter 'f' for fNumber and 't' for tNumber:  ");
	scanf("%c",&oper);

	switch(oper)
	{
	case('t'):
		tNumber(&x[0][0]);
		break;
	case('f'):
		fNumber(&x[0][0]);
		break;
	default:
		printf("\nUnknown operator\n");
		break;
	}
	
	return 0;
	}




	void tNumber(int *xPtr)
	{
		int i,k, sum;
		int x[IMAX][JMAX],tNumber[IMAX][JMAX];
		int *tNumPtr = &tNumber[0][0];

		for(i=0;i<IMAX*JMAX;i++)
		{
			sum=0;
			for(k=1;k <=*(xPtr+i);k++)
			{
				sum +=k;
			}
			*(tNumPtr+i) = sum;
			printf("i=%d\nsum=%d\n",i,sum);
		}

		for(i=0;i<IMAX*JMAX;i++)
		{
		printf("x[%d][%d]=%d\t\ttNumber[%d][%d]=%d\n",i/JMAX,i%JMAX,*(xPtr+i),i/JMAX,i%JMAX,*(tNumPtr+i));
		}
		printf("\n");
	}





		void fNumber(int *xPtr)
	{
		int i,k, product;
		int x[IMAX][JMAX],fNumber[IMAX][JMAX];
		int *fNumPtr = &fNumber[0][0];

		for(i=0;i<IMAX*JMAX;i++)
		{
			product=1;
			for(k=1;k <=*(xPtr+i);k++)
			{
				product *=k;
			}
			*(fNumPtr+i) = product;
			printf("i=%d\nproduct=%d\n",i,product);
		}
		for(i=0;i<IMAX*JMAX;i++){
		printf("x[%d][%d]=%d\t\tfNumber[%d][%d]=%d\n",i/JMAX,i%JMAX,*(xPtr+i),i/JMAX,i%JMAX,*(fNumPtr+i));

	}
	printf("\n");
}
