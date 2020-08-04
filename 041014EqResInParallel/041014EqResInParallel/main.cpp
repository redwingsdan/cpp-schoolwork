#include <stdio.h>
#define size 100

void equivR(float R[],int num);

int main(void)
{
	int i,num;
	float R[size];

	printf("Enter the number of resistors connected in parallel:  ");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		printf("Enter the value of resistor R[%d]:  ",i);
		scanf("%f",&R[i]);

	}

	equivR(R,num);

	return 0;
}


void equivR(float R[],int num)
{
	int i;
	float Gequiv=0,Requiv;

	printf("\nResistor values in the array:   \n");
	for(i=0;i<num;i++)
	{
		printf("R[%d]=%d  ",i,R[i]);
		Gequiv+=1/R[i];
	}
	Requiv = 1/Gequiv;
	printf("\nEquivalent resistance is Requiv = %.2f\n",Requiv);
	printf("\n");
}