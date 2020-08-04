#include <iostream>

using namespace std;

int main()
{
	bool a(false), b(false), c(false), condition;


	cout << "Enter the value for a: ";
	cin >> a;
	cout << "\n" << "Enter the value for b: ";
	cin >> b;
	cout << "\n" << "Enter the value for c: ";
	cin >> c;
	
		if(a<=1 && b<=1 && c<=1){
			condition = !(a || b) && c;
		
	
//			cout << "\n" << "The condition: \n\n!(" << a << " || " << b << ") && " << c << " is = " <<
//					condition << endl << endl;

			if(condition == 1){
				cout << "\n" << "The condition: \n\n!(" << a << " || " << b << ") && " << c << " is = " <<
					"true" << endl << endl;
			}

			if(condition == 0){
				cout << "\n" << "The condition: \n\n!(" << a << " || " << b << ") && " << c << " is = " <<
					"false" << endl << endl;
			}
		}

		return 0;
}

