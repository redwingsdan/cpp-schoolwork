#include <iostream>

using namespace std;

int main()
{
	float acres(2500.0);
	int i, year(1);

	cout << "\t\t\t" << "YEAR" << "\t\t" << "ACRES FORESTED"
		<< "\n" << "\t\t\t" << "---------------------------" << endl;

	for(i = 0; i < 20; i++){
		cout << "\t\t\t" << "Year " << year << "\t\t" << acres << " acres";
		year++;
		acres = (acres + (0.02 * acres));
		cout << "\n";
	}


	return 0;
}