#include<stdio.h>
#define size 100

void factorial(int *xPtr,int n);

int main(){
	int x[size],i,n,product;
	int *xPtr;
	xPtr=x;

	printf("Enter the size of the array:  ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Please enter element x[%d]:   ",i);
		scanf("%d",&x[i]);
	}

	for(i=0;i<n;i++){
		printf("x[%d]=%d\n",i,x[i]);
	}

	factorial(x,n);

	return 0;
}

void factorial(int *yPtr,int m){
	int i,j,product;
	int fNumber[size];

	for(i=0;i<m;i++){
		printf("y[%d]=%d\n",i,*(yPtr+i));
	}
	for(i=0;i<m;i++){	
		product=1;
		for(j=1;j<=*(yPtr+i);j++){
			product *= j;
		}
		fNumber[i]=product;
	}

	printf("\n");
	for(i=0;i<m;i++){
	printf("fNumber[%d] = %d\n",i,fNumber[i]);
	}
	printf("\n");
}
