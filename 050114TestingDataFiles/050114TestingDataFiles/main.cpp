#include <stdio.h>
#include<math.h>
#include<stdlib.h>

#define size 270
#define pi 3.14

int main()
{
	FILE *ptr;
	int i;
	char Hockey[size];
	

	ptr=fopen("sineValue.txt", "w");

	for(i=0;i<10;i++)
	{
		printf("Enter Hockey Players: \n");
		scanf("%s",&Hockey[i]);
	}

	for(i=0;i<10;i++)
	{
		fprintf(ptr,"%s\n",Hockey[i]);
	}
	fclose(ptr);

	system("sineValue.txt");

	return 0;
}
