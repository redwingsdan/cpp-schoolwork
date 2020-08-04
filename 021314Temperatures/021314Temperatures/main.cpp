#include <stdio.h>

int main()
{
	int a=0;
	while (a<=100)
	{
		printf("%4d degrees F = %4d degrees C\n",a, (a-32)*5/9);
		a=a+5;
	}
 return 0;
}
