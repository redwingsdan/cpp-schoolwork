/*

%c		character
%d		decimal integer
%i		^^
%f		floating point decimal
%e		floating point exponential
%g		^^ both
%o		octal integer
%s		string of characters
%x		hexidecimal integer
%u		unsigned decimal integer



\a		bell
\b		backspace
\f		formfeed(next page
\n		newline
\r		carriage return
\t		horiz tab
\v		vert tab
\'		single quote
\"		double quote
\\		backslash
\ddd	octal  notation
\xddd	hexadecimal notation

*/

// Triangular number for a postive integer number in an infinite loop

#include <stdio.h>

int main()
{
	int n, tNo=0,i;

	while(1)
	{
		printf("Enter a positive number n:  ");
		scanf("%d",&n);

		if(n<0)
		{
			printf("You enter a negative number, which is not allowed!\n"
				"Make sure you enter a POSITIVE integer number\n\n");
		}
		if(n>0)
		{
			for(i=0;i<=n;i++)
			{
				tNo=tNo+i;
			}
			printf("tNo for n=%d is:  %d\n",n,tNo);
		}
		tNo=0;
	}
	return 0;
}