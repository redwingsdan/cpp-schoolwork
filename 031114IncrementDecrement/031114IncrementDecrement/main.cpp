/*****************************/
// x++ = x+1 post increment
// ++x = x+1 pre increment
// x-- = x-1 post decrement
// --x = x-1 pre decrement
/*****************************/

#include <stdio.h>

int main()
{
	int x=10,y=53,z=12;
	printf("\nx=%d\ty=%d\tz=%d",x,y,z);

	z=x++ +y--;							//x+1 plus current y
	printf("\nx=%d\ty=%d\tz=%d",x,y,z);

	++z;
	printf("\nx=%d\ty=%d\tz=%d",x,y,z);

	y=++y +z--;							//y=y+1, then y=y+z, then dec z at the end
	printf("\nx=%d\ty=%d\tz=%d",x,y,z);

	x=y++ + ++z;						// z=z+1, then x=y+z, then post operator
	printf("\nx=%d\ty=%d\tz=%d",x,y,z);

	z=--x + y + z++;
	printf("\nx=%d\ty=%d\tz=%d\n",x,y,z);

	return 0;
}