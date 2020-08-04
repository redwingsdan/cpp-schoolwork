/*

factorial(n)=n*factorial(n-1);		//1*2*3*...(n-1)*n;

x[5] = {x[0],x[1],x[2],x[3],x[4]} ;	//array. 5 elements within the array. 1 Dimensional

*/

#include <stdio.h>

int factorialNo(int num);

int main()
{
	int fNumber,num;		//sometimes need to initialize num to enter loop

	for(num=0;num<10;num++)
	{
		fNumber=factorialNo(num);
		printf("Factorial of %d is %d\n",num,fNumber);
	}
	return 0;
}
int factorialNo(int num)
{
	int result;

	if(num==0)
	{
		result=1;
	}
	else
	{
		result=num*factorialNo(num-1);
	}
	return result;
}