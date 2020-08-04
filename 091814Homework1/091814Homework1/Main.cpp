#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	string e[5] = {"Carbon","Hydrogen","Oxygen","Nitrogen","Sulfur"};	//array of the elements used in the amino acid
	int n(5), a[5], i, atoms;		//array for the values of each of the elements
	int * p;
	string * q;
	q = &e[0];				   	//pointer to the element array
	p = &a[0];					//pointer to the value of atoms array
	float weight(0), average(0);

	for(i=0; i<n; i++){			//inputting the values for the number of atoms
		cout << "Please enter the number of atoms for the element " <<
			*(e+i) << ":  ";
		cin >> a[i];
	}

	for(i=0; i<n; i++){			//adds the total atoms up
		atoms = atoms + (*(p+i));
	}

	for(i=0; i<n; i++){			//calculates the weight of each set of atoms. Each loop is for a different element
		if(i == 0){				//all of the weights are then added together
		weight = weight + (*(p+i) * 12.011);		//calculates the weight of the carbon atoms
		}
		if(i == 1){
		weight = weight + (*(p+i) * 1.00794);		//calculates the weight of the hydrogen atoms
		}
		if(i == 2){
		weight = weight + (*(p+i) * 15.9994);		//calculates the weight of the oxygen atoms
		}
		if(i == 3){
		weight = weight + (*(p+i) * 14.00674);		//calculates the weight of the nitrogen atoms
		}
		if(i == 4){
		weight = weight + (*(p+i) * 32.066);		//calculates the weight of the sulfur atoms
		}
	}

	average = weight / atoms;						//the average weight of each atom is calculated by taking the total weight 
													//and dividing by the total number of atoms
	cout << "\n\n" << "The average weight of the atoms in the amino acid is " << 
		average << " grams per mole." << endl << endl;

	return 0;
}
	