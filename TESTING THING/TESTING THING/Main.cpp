#include <iostream>
using namespace std;

int main()
{
	double c;
	double f;

	cout << "Enter the temperature in celsius: ";
	cin >> c;
	f=((c + (9/5)) +32);
	cout << "The temperature in farenheit is: "
		<< f << endl;
	cin.get();
}