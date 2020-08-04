#include <iostream>
#include <cmath>

#define LOG2E 1.442696504088896340736	//Defines log2(e)
using namespace std;

inline long double log2(const long double x){	//Declares the function log2(x)
	return log(x) * LOG2E;				//Returns the log of the user inputted value multiplied by log2(e)
}

int main()
{
	int n = 0, i;
	double y;

	while(n <= 0){
		cout << "Enter a positive number: ";
		cin >> n;
		if(n <= 0){
			cout << "ERROR! Please enter a POSITIVE number." << "\n\n";
		}
		if(n > 0){
			y = log2(n);		//sets y equal to the value of log2(n). n is sent to the function above
			cout << "The logarithm of " << n << " to base 2 is: " <<
				y << "\n\n\n" << endl;
		}
	}
	return 0;
}