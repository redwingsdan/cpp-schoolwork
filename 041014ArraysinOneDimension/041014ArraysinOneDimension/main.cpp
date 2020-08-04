//Arrays allow for one variable to hold memory for multiple values. One value for grade can hold up to 100 values

#include <stdio.h>

#define max 100			//the amount of elements in program

int main()
{
	int number,i;
	float grade[max],sum=0,average;

	//asks the user to enter the amount of students
	printf("Enter the # of students:  ");
	scanf("%d",&number);
	printf("\n");

	//asks the user to enter the grades for every student up to the amount that they entered

	for(i=0;i<number;i++)
	{
		printf("Enter the grade of student %d:  ",i);
		scanf("%f",&grade[i]);
	}
	printf("\n");

//the below calculates the class average
	for(i=0;i<number;i++)
	{
		sum=sum+grade[i];
		
	}
	average=sum/number;
	printf("The class average is %.2f\n",average);
//the above calculates the class average

	//prints the grade for each student entered in order from 0-99
	for(i=0;i<number;i++)
	{
		printf("The grade of student %d is %.2f\n",i,grade[i]);
	}
	printf("\n");

return 0;
}
