/*********************************************************/
/*				Illustrating the module operator         */
/* The expression "x modulus y" (written as x%y in code) */
/* is equal to the remainder which is obtained when x is */
/* divided by y. Note: x and y are both positve integers */
/* Example: 6%2=0 13%2=1 34%3=1                          */
/*********************************************************/


#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Please enter a value for a:  ");
	scanf("%d",&a);
	printf("\nPlease enter a value for b:  ");
	scanf("%d",&b);

	c=a%b;
	printf("\n%d Modulus %d = %d\n\n",a,b,c);

	return 0;
}