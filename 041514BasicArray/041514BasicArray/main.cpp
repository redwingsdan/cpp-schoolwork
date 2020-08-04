/*

#include <stdio.h>

int main()
{
	int i, x[5]={6,8,2,4};

	for(i=0;i<5;i++)
	{
		printf("x[%d]=%d\n",i,x[i]);
	}
	return 0;
}
*/

/*#include <stdio.h>

int main()
{
	int i,j,x[3][4]={{1,2,3,4},{2,3,4},{3,4,5}};

	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("x[%d][%d]=%d\n",i,j,x[i][j]);
		}
	}
		return 0;
	
}*/

#include <stdio.h>
#define size 100

void maxValue(int a[],int num);
void minValue(int a[],int num);
void meanValue(int a[],int num);

int main()
{
	int x[size],i,num;

	printf("Enter the number of elements in the array:  ");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		printf("Enter the value of the array element x[%d]:  ");
		scanf("%d",&x[i]);
	}
	printf("\nOutputting element values in the array:  \n");
		for(i=0;i<num;i++)
		{
			printf("x[%d]=%d  ",i,x[i]);
		}

		printf("\n");

		maxValue(x,num);
		minValue(x,num);
		meanValue(x,num);

		return 0;
}


void maxValue(int a[],int num)
{
	int i,aMax=a[0];

	for(i=1;i<num;i++)
	{
		if(aMax<a[i])
		{
			aMax=a[i];
		}
	}
	printf("aMax=%d\n",aMax);
}

void minValue(int a[],int num)
{
	int i,aMin=a[0];

	for(i=i;i<num;i++)
	{
		if(aMin>a[i])
		{
			aMin=a[i];
		}
	}
	printf("aMin=%d\n",aMin);
}

void meanValue(int a[],int num)
{
	int i,sum=0;
	float aMean;

	for(i=0;i<num;i++)
	{
		sum+=a[i];
	}
	aMean=sum/num;

	printf("aMean=%.2f\n",aMean);
}