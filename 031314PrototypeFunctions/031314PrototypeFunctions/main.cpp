#include <stdio.h>
int cubing (int num);

int main()
{
	int num,numCubed;

	while(1)
	{
		printf("Enter an integer # on the keyboard:  ");
		scanf("%d",&num);
		
		numCubed=cubing(num);
		printf("The cube of %d is %d\n",num,numCubed);
	}
	return 0;
}
int cubing(int num)
{
	int numCubed;
	 numCubed=num*num*num;
		 return(numCubed);
}