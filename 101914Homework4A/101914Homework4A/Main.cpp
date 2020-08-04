#include <iostream>
#include <ctime>

using namespace std;

unsigned int roll_dice() {
	unsigned int output;
	output = rand() % 6;
	output += 1;
	return output;
}

int main(){

	srand(time(0));
	unsigned int output = rand() % 6, sum = 0;
	int i, n;
	float x = 0.00, y = 0.00, percentage;

	cout << "Please enter the number of dice rolls you would like to take: ";
	cin >> n;
	cin.get();
	for(i=0; i<n; i++){

	output = roll_dice();
	cout << "You rolled a " << output;
	sum += output;
	output = roll_dice();
	cout << " and " << output << endl;
	sum += output;
	if (sum == 8){
		x++;
	}
	y++;
	sum = 0;
	
	cin.get();
	}

	percentage = x / y;
	percentage = percentage * 100;

	cout << "The percentage of times the total number on of the dice was eight was: "
		<< percentage << "%\n";

	return 0;
}