#include <stdio.h>
#define size 100

void MaxMin(int x[],int n,int *largest, int *smallest);

int main()
{
	int num,a[size],i,largest,smallest;

	printf("Enter a value for num:  ");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		printf("Enter the element a[%d] of array:  ",i);
		scanf("%d",&a[i]);
	}


	MaxMin(a,num,&largest,&smallest);

	

	return 0;
}


void MaxMin(int x[],int n, int *largest, int *smallest)
{
	int i;

	*largest=*smallest=x[0];
	for(i=1;i<n;i++)
	{
		if(x[i]>*largest)
		{
			*largest = x[i];
		}
		if(x[i]<*smallest)
		{
			*smallest = x[i];
		}
	}
	printf("Largest = %d\t\tSmallest=%d\n",*largest,*smallest);
}