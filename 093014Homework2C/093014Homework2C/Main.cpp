#include <iostream>

using namespace std;

int main()
{
	float inches(0.0), centimeters(0.0);
	int i;

	cout << "\t\t\t" << "INCHES" << "\t\t" << "CENTIMETERS"
		<< "\n" << "\t\t\t" << "---------------------------" << endl;

	for(i = 0; i < 41; i++){
		cout << "\t\t\t" << inches << " in" << "\t\t" << centimeters << " cm";
		inches = inches + 0.5;
		centimeters = inches * 2.54;
		cout << "\n";
	}


	return 0;
}