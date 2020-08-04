/*

#include <stdio.h>

int main()
{
	int num,tNum,fNum,i,runMode;

	while(1)
	{
		printf("Enter a number for num whose tNum or fNum is to be found:  ");
		scanf("%d",&num);

		printf("Enter a value for runMode, 0 to compute tNum, 1 to compute fNum:  ");
		scanf("%d",&runMode);

		tNum=0;
		fNum=1;

		if(runMode==0)
		{
			for(i=1;i<=num;i=i+1)
			{
				tNum=tNum+1;
			}
			printf("tNum for num=%d is %d\n\n",num,tNum);
		}
		else if(runMode==1)
		{
			for(i=1;i<=num;i=i+1)
			{
				fNum=fNum*i;
			}
			printf("fNum for num=%d is %d\n\n",num,fNum);
		}
	}
	return 0;
}

*/

//Using the switch statement to compute sine, cosine and tangent

#include <stdio.h>
#include <math.h>
#define pi 3.14

int main()
{
	int runmode;
	float deg,rad,sinValue,cosValue,tanValue;

	while(1)
	{
		printf("\nPlease enter a value for angle in degrees:  ");
		scanf("%f",&deg);
		printf("Please enter a value of runmode:  ");
		scanf("%d",&runmode);

		//runmode 1 =sin
		//runmode 2 =cos
		//runmode 3 =tan

		rad=deg*pi/180;

		switch(runmode)
		{
		case(1):
			sinValue=sin(rad);
			printf("Sin %.2f deg = %.2f\n",deg,sinValue);
			break;
		case(2):
			cosValue=cos(rad);
			printf("Cos %.2f deg = %.2f\n",deg,cosValue);
			break;
		case(3):
			tanValue=tan(rad);
			printf("Tan %.2f deg = %.2f\n",deg,tanValue);
			break;
		default:
			printf("Unallowed value of runmode\n");
		}
		
	}
	return 0;
}



