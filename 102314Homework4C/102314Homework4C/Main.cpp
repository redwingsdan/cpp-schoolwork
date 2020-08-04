#include <iostream>
#include <cmath>
using namespace std;

double poly(double x, double a0, double a1, double a2, double a3);
void check_roots (double left, double right, double a0, double a1, double a2, double a3);

int main(){

	int n, k;
	double a, b, step, left, right, a0, a1, a2, a3;


	cout << "Enter coefficients a0, a1, a2, a3: \n";
	cin >> a0 >> a1 >> a2 >> a3;
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
		check_roots (left, right, a0, a1, a2, a3);
	}
	check_roots (b, b, a0, a1, a2, a3);
	return 0;
}

void check_roots (double left, double right, double a0, double a1, double a2, double a3){
	double f_left, f_right, c;
	f_left = poly(left, a0, a1, a2, a3);
	f_right = poly(right, a0, a1, a2, a3);
	if(fabs(f_left) < 0.1e-04)
		cout << "Root detected at " << left << endl;
	else
		if(!(fabs(f_right) < 0.1e-04))
			if(f_left*f_right < 0)
				c = (left*f_right - right*f_left)/(f_right - f_left);
				//cout << "Root detected at " << c << endl;
					cout << "There was no root found at " << left <<endl;
	return;
}

double poly(double x, double a0, double a1, double a2, double a3)
{

		return a0*x*x*x + a1*x*x + a2*x + a3;

}