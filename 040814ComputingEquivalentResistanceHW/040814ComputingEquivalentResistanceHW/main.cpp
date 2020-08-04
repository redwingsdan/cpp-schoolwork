#include <stdio.h>

float equivRseries(float r, float reqS);

float equivRparallel(float r, float reqP);

float equivCseries(float r, float ceqS);

float equivCparallel(float r, float ceqP);

float equivLseries(float r, float leqS);

float equivLparallel(float r, float leqP);

int main()
{
	float r, reqS, reqP, ceqS, ceqP, leqS,leqP;
	int runmode;
	

	printf("Please enter a value for runmode: \n1.) Calculate resistance in series.\n2.) Calculate resistance in parallel.\n3.) Calculate capacitance in series.\n4.) Calculate capacitance in parallel.\n5.) Calculate inductance in series.\n6.) Calculate inductance in parallel.\n");
	scanf("%d",&runmode);
	switch(runmode)
	{
	case(1):
		reqS=0;
		reqS=equivRseries(r,reqS);
		printf("The equivalent resistance is %.2f\n",reqS);
		break;
	case(2):
		reqP=0;
		reqP=equivRparallel(r,reqP);
		printf("The equivalent resistance is %.2f\n",reqP);
		break;
	case(3):
		ceqS=0;
		ceqS=equivCseries(r,ceqS);
		printf("The equivalent capacitance is %.2f\n",ceqS);
		break;
	case(4):
		ceqP=0;
		ceqP=equivCparallel(r,ceqP);
		printf("The equivalent capacitance is %.2f\n",ceqP);
		break;
	case(5):
		leqS=0;
		leqS=equivLseries(r,leqS);
		printf("The equivalent inductance is %.2f\n",leqS);
		break;
	case(6):
		leqP=0;
		leqP=equivLparallel(r,leqP);
		printf("The equivalent inductance is %.2f\n",leqP);
		break;
	default:
		printf("Please enter a valid runmode.\n");
		
	}
	
	return 0;
}

float equivRseries(float r, float reqS)
{
	int i=0;
	r=1;
	reqS=0;
	while(r!=0)
	{
		printf("Please enter a value for the resistor:  ");
		scanf("%f",&r);
		reqS+=r;
		if(r!=0)
		{
		i++;
		}
	}
	printf("There are %d resistors.\n",i);
	return reqS;
}


float equivRparallel(float r, float reqP)
{
	int i=0;
	float g, geq=0;
	r=1;
	reqP=0;
	while(r!=0)
	{
		printf("Please enter a value for the resistor:  ");
		scanf("%f",&r);
		if(r!=0)
		{
		g=(1/r);
		i++;
		geq=geq+g;
		}
	}
	reqP=(1/geq);
	printf("There are %d resistors.\n",i);
	return reqP;
}

float equivCseries(float r, float ceqS)
{
	int i=0;
	float g, geq=0;
	r=1;
	ceqS=0;
	while(r!=0)
	{
		printf("Please enter a value for the capacitor:  ");
		scanf("%f",&r);
		if(r!=0)
		{
		g=(1/r);
		i++;
		geq=geq+g;
		}
	}
	ceqS=(1/geq);
	printf("There are %d capacitors.\n",i);
	return ceqS;
}


float equivCparallel(float r, float ceqP)
{
	int i=0;
	r=1;
	ceqP=0;
	while(r!=0)
	{
		printf("Please enter a value for the capacitor:  ");
		scanf("%f",&r);
		ceqP+=r;
		if(r!=0)
		{
		i++;
		}
	}
	printf("There are %d capacitors.\n",i);
	return ceqP;
}


float equivLseries(float r, float leqS)
{
	int i=0;
	r=1;
	leqS=0;
	while(r!=0)
	{
		printf("Please enter a value for the inductor:  ");
		scanf("%f",&r);
		leqS+=r;
		if(r!=0)
		{
		i++;
		}
	}
	printf("There are %d inductors.\n",i);
	return leqS;
}


float equivLparallel(float r, float leqP)
{
	int i=0;
	float g, geq=0;
	r=1;
	leqP=0;
	while(r!=0)
	{
		printf("Please enter a value for the inductor:  ");
		scanf("%f",&r);
		if(r!=0)
		{
		g=(1/r);
		i++;
		geq=geq+g;
		}
	}
	leqP=(1/geq);
	printf("There are %d inductors.\n",i);
	return leqP;
}
