/*

#include <stdio.h>

int main()
{
	int x,xCube;
	int *xPtr;
	xPtr=&x;

	printf("Please type a value for x: ");
	scanf("%d",&x);

	printf("\nUser-supplied value of variable x = %d\n\n",x);
	printf("Address of x=%d\n\n",&x);
	printf("Value of pointer xPtr=%d\n\n",xPtr);
	printf("Address of pointer xPtr=%d\n\n",&xPtr);
	printf("Address of pointer is not important but it does exist\n\n");
	printf("Value of x in terms of pointer is: %d\n\n",*xPtr);

	printf("Finding x^3 using pointers means computing the *xPtr x *xPtr x *xPtr\n\n");

		xCube=*xPtr * *xPtr * *xPtr;
	printf("i.e., x^3 = %d\n\n",xCube);
	
	return 0;
}

*/
/*

#include <stdio.h>

int main()
{
	int x,xCube;
	int *xPtr = &x;

	printf("PLease type a value for x:  ");
	scanf("%d",&x);

	printf("\nUser-supplied value of variable x = %d\n\n",x);
	printf("Address of x=%d\n\n",&x);
	printf("Value of pointer xPtr=%d\n\n",xPtr);
	printf("Address of pointer xPtr=%d\n\n",&xPtr);
	printf("Address of pointer is not important but it does exist\n\n");
	printf("Value of x in terms of pointer is: %d\n\n",*xPtr);

	printf("Finding x^3 using pointers means computing the *xPtr x *xPtr x *xPtr\n\n");

		xCube=*xPtr * *xPtr * *xPtr;
	printf("i.e., x^3 = %d\n\n",xCube);
	
	return 0;
}

*/

#include <stdio.h>

int cubing(int *xPtr);

int main()
{
	int x,xCube;
	int *xPtr=&x;

	printf("Please enter a value for x:  ");
	scanf("%d",&x);

	xCube=cubing(&x);

	printf("i.e., x^3 = %d\n\n",xCube);

	return 0;
}

int cubing(int *xPtr)
{
	int xCube;

	xCube=*xPtr * *xPtr * *xPtr;

	return xCube;
}

//Basically, the "&" means the address of the varialbe
//The *x means the value within the address