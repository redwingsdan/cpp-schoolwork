#include <iostream>
#include <cmath>
using namespace std;

double sinc(double x);
void check_roots (double left, double right);

int main(){

	int n, k;
	double a, b, step, left, right;

	cout << "Enter interval limits a, b (a<b): \n";
	cin >> a >> b;
	cout << "Enter step size: \n";
	cin >> step;

	n = ceil((b-a)/step);
	
	for(k=0; k<= n-1; k++){
		left = a + k*step;
		if(k == n-1){
			right = b;
		}
		else
			right = left + step;
		check_roots (left, right);
	}
	check_roots (b,b);
	return 0;
}

void check_roots(double left, double right){
	double f_left, f_right;
	f_left = sinc(left);
	f_right = sinc(right);
	if(fabs(f_left) < 0.1e-04)
		cout << "Root detected at " << left << endl;
	else
		if(!(fabs(f_right) < 0.1e-04))
			if(f_left*f_right < 0)
				cout << "Root detected at " << (left+right)/2 << endl;
	return;
}

double sinc(double x)
{
	if(x==0)
		return 1;
	else
		return sin(x)/x;



	return 0;
}