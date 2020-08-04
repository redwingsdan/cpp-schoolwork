#include <iostream>
#include <cmath>
using namespace std;

double polynomial(double x, double a, double b, double c, double d);
double derivative (double a, double b, double c, double d, double x);

int main(){

	int times = 1;
	double x, poly, tolerance, dp, a0, a1, a2, a3;


	cout << "Enter coefficients a0, a1, a2, a3: \n";
	cin >> a0 >> a1 >> a2 >> a3;
	cout << "Enter guess for root: \n";
	cin >> x;

	poly = polynomial(a0,a1,a2,a3,x);

	tolerance = abs(poly);
	while(tolerance > .001 && times < 100){
		dp = derivative(a0,a1,a2,a0,x);

		x = x - (poly/dp);

		poly = polynomial(a0,a1,a2,a3,x);
		tolerance = abs(poly);
		times++;
	}

	if(tolerance < .001){
		cout << "The root is " << x <<endl
		<<times << " times\n";
	}
	else
		cout << "The function didn't have a root after 100 times\n";

	return 0;
}

double polynomial(double x, double a, double b, double c, double d){
	
	return a*x*x*x + b*x*x + c*x + d;
}

double derivative (double a, double b, double c, double d, double x){

	return 3*a*x*x + 2*b*x + c;

}