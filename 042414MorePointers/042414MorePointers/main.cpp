#include <stdio.h>

void swap(int *aPtr, int *bPtr)
{
	int temp;

	printf("Starting values before swap: x=%d\ty=%d\n",*aPtr,*bPtr);
	temp=*aPtr;
	*aPtr=*bPtr;
	*bPtr=temp;
	printf("Ending values after swap:  x=%d\t\ty=%d\n",*aPtr,*bPtr);
}

int main()
{
	int x=20,y=67;
	int *xPtr=&x;
	int *yPtr=&y;

	swap(&x,&y);
	return 0;
}
