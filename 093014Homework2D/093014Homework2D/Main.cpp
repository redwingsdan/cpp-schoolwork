#include <iostream>

using namespace std;

int main()
{
	float yen(1), pesos(0.0902);
	int i;

	cout << "\t\t\t" << "YEN" << "\t\t" << "PESO"
		<< "\n" << "\t\t\t" << "---------------------------" << endl;

	for(i = 0; i < 30; i++){
		cout << "\t\t\t" << yen << " yen" << "\t\t" << pesos << " pesos";
		yen = yen + 2;
		pesos = yen * 0.0902;
		cout << "\n";
	}

	return 0;
}