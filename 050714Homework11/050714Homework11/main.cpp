#include <stdio.h>
#define size 100

void StudentAverage(float *aPtr, int m, int n);

void QuizAverage(float *aPtr, int m, int n);

void ClassAverage(float *aPtr, int m, int n);


int main()
{
	int i,j,m,n;
	float a[size][size],*aPtr;
	aPtr=&a[0][0];

	printf("Enter the total number of students:  ");
	scanf("%d",&m);
	printf("Enter the toal number of quizzes taken:  ");
	scanf("%d",&n);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Please enter grade #%d for student #%d:  ",j,i);
			scanf("%f",&a[i][j]);
		}
	}

	for(j=0;j<n;j++)
	{
		printf("\t\tQuiz # %d",j);
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		printf("Student # %d",i);
		for(j=0;j<n;j++)
		{
			printf("\t%.2f\t\t",a[i][j]);
		}
		printf("\n");
	}
	
	StudentAverage(&a[0][0],m,n);

	printf("\n");

	QuizAverage(&a[0][0],m,n);

	printf("\n");

	ClassAverage(&a[0][0],m,n);

	printf("\n");

	return 0;
}



void QuizAverage(float *aPtr, int m, int n)
{
	int i,j;
	float M[size];

	for(i=0;i<m;i++)
	{
		M[i]=0;
		for(j=0;i<n;j++)
		{
			M[i]= M[i] + *(aPtr+i);
		}
		M[i] /= n;
	}

	for(i=0;i<m;i++)
	{
		printf("The average grade of student #%d is:  %.2f\n",i,M[i]);
	}
}