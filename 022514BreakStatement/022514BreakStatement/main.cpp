/**********************************************************/
/* When Break in encountered, the loop is terminated      */
/* When continue is encountered then all after is skipped */
/**********************************************************/


#include <stdio.h>

int main()
{
	int num,num1,i;

	num1=2;
	num=num1;
	for(i=1;i<=5;i++)		//i++ is the same as i = i+1
	{
		if(i%3==0)
		{
			continue;
			//break;
		}
		num+=i;					//num += i is num+1
								//same for -=, *=, /=

		printf("i=%d\t\tnum= %d\n",i,num);
	}
	printf("The output is: %d\n",num);
	return 0;
}