#include<stdio.h>

void summing(int *ptr,int n);

int main(){
	int x[10],n,i;
	int *ptr;				//Allows for *xptr to be equal to the value of x
	ptr=x;

	printf("Enter the # of elements n in the array:  ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Enter element x[%d] of the array:  ",i);
		scanf("%d",&x[i]);
	}

	for(i=0;i<n;i++){
		printf("x[%d]=%d\n",i,x[i]);
	}

	summing(x,n);

	return 0;
}

void summing(int *ptr,int n){
	int i,sum=0;

	for(i=0;i<n;i++){
		printf("\nx[%d]=%d",i,*(ptr+i));
		sum += *(ptr+i);
	}
	printf("\nsum=%d\n",sum);
}
