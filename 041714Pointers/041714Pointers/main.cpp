/*

#include <stdio.h>
#define rows 10
#define columns 10

void passingAndRowSumming(int a[rows][columns],int m, int n);

int main()
{
	int a[rows][columns],i,j,m,n;

	printf("Enter the order mxn of array a:  \n");
	scanf("%d %d",&m,&n);

	printf("Enter the elements of array a:  \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nElement values in the user-inputted array:  \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=%d \n",i,j,a[i]);
		}
	}

	passingAndRowSumming(a,m,n);

	return 0;
}

void passingAndRowSumming(float a[rows][columns],int m,int n)
{
	int i,j,sum=0;
	
	printf("\nElement values passed to the prototype function:  \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=%d \n",i,j,a[i]);
		}
	}
	printf("\n");

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=sum+a[i][j];
		}
		printf("\nb[%d]=%d\n\n",i,sum);
		sum=0;
	}
}

*/

int xPtr=%x;		//points to the address of x, which is an int

//compiler allocates a certain byte amount to a particular variable
//then the pointer points to that byte amount associated with the variable

int x=25;			//creates block at a certain address stored in memory (arbitrary)
int *xPtr;			//creates a pointer with an unknown value, does not point to a declared address
xPtr=&x;			//decares the value in the pointer to be = the address of the x, then it points to that address
