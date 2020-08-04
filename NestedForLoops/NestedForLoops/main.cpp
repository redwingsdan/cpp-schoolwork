#include <stdio.h>

int main()
{
	int i,j,k,product;
	int count=0;

	printf("All possible computer combinations of 3 integer numbers whose product is 10\n");
	printf("Count#\t   1stNumber\t   2ndNumber\t   3rdNumber\t   product");
	printf("------\t   ---------\t   ---------\t   ---------\t   -------");
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			for(k=1;k<=10;k++)
			{
				product = i*j*k;
				if(product==10)
				{
					count=count+1;
					printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",count,i,j,k,product);
				}
			}
		}
	}
	return 0;
}
