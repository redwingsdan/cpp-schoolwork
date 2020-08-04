#include <stdio.h.>
#define size 100

void equivRseries(float R[],int num);

int main()
{
	int i,num;
	float R[size];

	printf("Enter the number of resistors connected in series:  ");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		printf("Enter the value of resistor R[%d]:  ",i);
		scanf("%f",&R[i]);
	}

	printf("The typed values of resistors are:  \n");
	for(i=0;i<num;i++)
	{
		printf("R[%d]:%.2f  \n",i,R[i]);
	}

	equivRseries(R,num);


return 0;
}


void equivRseries(float R[],int num)
{
	int i;
	float Req=0;

	printf("\nResistor values in the array:  \n");
	for(i=0;i<num;i++)
	{
		printf("R[%d]=%.2f\n",i,R[i]);
	}
	for(i=0;i<num;i++)
	{
		Req+=R[i];
	}
	printf("The equivalent resistance of %d resistors is %.2f\n",num,Req);
}


