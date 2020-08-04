#include <iostream>

using namespace std;

bool condition_test(bool a, bool b, bool c);

int main()
{
	bool a(false), b(false), c(false), tautology(true);
	
	if(tautology == true){
	tautology = condition_test(a,b,c);
	a = !a;
	}
	if(tautology == true){
	tautology = condition_test(a,b,c);
	a = !a;
	b = !b;
	}
	if(tautology == true){
	tautology = condition_test(a,b,c);
	a = !a;
	}
	if(tautology == true){
	tautology = condition_test(a,b,c);
	c = !c;
	b = !b;
	a = !a;
	}
	if(tautology == true){
	tautology = condition_test(a,b,c);
	a = !a;
	}
	if(tautology == true){
	tautology = condition_test(a,b,c);
	a = !a;
	b = !b;
	}
	if(tautology == true){
	tautology = condition_test(a,b,c);
	a = !a;
	}
	if(tautology == true){
	tautology = condition_test(a,b,c);
	}

	if(tautology == false){
		cout << "\n\n" << "This condition is NOT a tautology" << endl << endl;
	}
	else{
		cout << "\n\n" << "This condition is a tautology" << endl << endl;
	}


		return 0;
}

bool condition_test(bool a, bool b, bool c){
	bool condition;
	condition = ((a && b) || (b && c));
	cout << "\n" << "The condition: \n\n!(" << a << " && " << b << ") || " << b << " && " << c << " is = " <<
			condition << endl << endl;
		//cin.get();
	return condition;
}
