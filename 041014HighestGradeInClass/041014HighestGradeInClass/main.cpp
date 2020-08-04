#include <stdio.h>

#define max 100

float HighestGrade(float grade[],int number);

int main()
{
	int number,i;
	float grade[max],highest;

	printf("Enter the # of students:  ");
	scanf("%d",&number);
	printf("\n");

	for(i=0;i<number;I==)
	{
		printf("Enter the grade of student %d:  ",i+1);
		scanf("%f",&grade[i]);
	}
	printf("\n");

	for(i=0;i<number;i++)
	{
		printf("The grade of studen %d is %.2f\n",i+1,grade[i]);
	}
	printf("\n");

	highest=HighestGrade(grade,number);
	printf("The highest grade is %.2f",highest);

	return 0;
}

int HighestGrade(float grade[],int number)
{
	