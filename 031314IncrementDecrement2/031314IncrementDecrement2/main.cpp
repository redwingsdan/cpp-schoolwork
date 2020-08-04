#include <stdio.h>

int main()
{

int	w=15,x=25,y=30,z=35;
	printf("\nw=%d\tx=%d\ty=%d\tz=%d",w,x,y,z);

	z=++x + y++ - --w;							//add 1 to x, minus 1 from w, x+y-w. then add 1 to y
	printf("\nw=%d\tx=%d\ty=%d\tz=%d",w,x,y,z);

	y=w-- + ++y + --z;							//add 1 to y, minus 1 from z, w+y+z. minus 1 from w
	printf("\nw=%d\tx=%d\ty=%d\tz=%d",w,x,y,z);

	x=w++ - y++ + ++z;							//add 1 to w, x-y+z. add 1 to x, add 1 to z
	printf("\nw=%d\tx=%d\ty=%d\tz=%d",w,x,y,z);

	z=++x - y + z--;							//add 1 to x, x-y+z. minus 1 from z
	printf("\nw=%d\tx=%d\ty=%d\tz=%d\n",w,x,y,z);

return 0;
}