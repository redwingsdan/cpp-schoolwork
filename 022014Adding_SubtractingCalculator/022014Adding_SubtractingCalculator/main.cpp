/*****************************************************************/
/* Adding or subtracting an abitrary number of integers of       */
/* arbitrary values.											 */
/* This program simulates the addition & subtraction features of */
/* a calculator													 */
/*****************************************************************/

#include <stdio.h>

int main()
{
	int num=1,sum=0;

	//num=1 is a dummy value in order to initiate the loop. It will
	//Continue infinitely until a value of 0 in entered. At this
	//point, the loop will end and the sum will be computed.
	
	while(num!=0)
	{
		//The argument of while stands for "num not equal to 0"
		//Thus, looping takes place if num is not equal to 0, i.e.,
		//argument of while is TRUE, and looping in terminated if
		//num is equak to 0, i.e.,vthe argument of while is FALSE.

		printf("\nEnter an integer number:  ");
		scanf("%d",&num);

		printf("Number=%d\n",num);

		sum=sum+num;	//sum+=num;

		printf("\nThe sum so far is: %d",sum);  //optional to show the sum at all points along the way
	}
	printf("\nTotal of all typed numbers is %d\n\n",sum);
	return 0;
}