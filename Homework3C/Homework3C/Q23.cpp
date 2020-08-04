#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	double time, distance, velocity, acceleration;

	ifstream inputfile;

	inputfile.open("rocket3.txt");

	if(inputfile.fail()){
		cerr << "Unable to open the file." << endl;
		getchar();
		getchar();
		return 0;
	}

	inputfile >> time >> distance >> velocity >> acceleration;
	while(!inputfile.eof()){
		if(acceleration < (-9.8 * .65) && acceleration >= -9.8){
			cout << time << endl;
		}
		inputfile >> time >> distance >> velocity >> acceleration;
	}
	inputfile.close();

	getchar();
	getchar();
	return 0;
}
	