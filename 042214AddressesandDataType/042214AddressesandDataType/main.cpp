#include <stdio.h>

int main()
{
	int i=5,j=25,a[5];
	float x=6.23,y=27.6;
	a[0]=24;


	printf("i=%d\tj=%d\tx=%.2f\ty=%.2f\ta[0]=%d\n",i,j,x,y,a[0]);
	printf("&i=%d\t&j=%d\t&x=%d\t&y=%d\t&a[0]=%d\n",&i,&j,&x,&y,&a[0]);
	printf("Memory size of int is %d bytes\n",sizeof(int));
	printf("Memory size of float is %d bytes\n",sizeof(float));
	printf("Memory size of double is %d bytes\n",sizeof(double));
	printf("Memory size of short is %d bytes\n",sizeof(short));
	printf("Memory size of char is %d bytes\n",sizeof(char));
	return 0;
}