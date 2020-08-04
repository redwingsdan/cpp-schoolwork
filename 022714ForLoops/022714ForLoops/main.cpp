#include <stdio.h>

int main()
{
	int i,j;

	for(i=0;i<2;i=i+1)
	{
		for(j=4;j>=i;j=j+1)
		{
			if(j==4)
			{
			continue;
			//break
		    }
		if(i==i && j==3)
		{
			break;
		}
		printf("\n\t%d\t\t5d\n",i,j);
	     }
    }
return 0;
}