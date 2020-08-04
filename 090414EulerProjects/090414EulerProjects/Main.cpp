#include <iostream>

using namespace std;

int main()
{
	int divisor, num, total, good = 1; 
	num = 20;
	while(good == 1){
	for (divisor=2; divisor<=20; divisor++){
		total = num%divisor;
		if (num%divisor != 0){
			num++;
			break;
		}
		if(divisor == 21){
			cout << num << endl;
			good = 0;
		}
	}
	}
	
	return 0;
}