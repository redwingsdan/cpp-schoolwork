#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x1(1), y1(5), x2(4), y2(7), side1,  side2, distance;

	side1 = x2 - x1;
	side2 = y2 - y1;
	distance = sqrt(side1*side1 + side2*side2);

	cout << "The distance between the two points is " <<
		distance << endl;

	return 0;

}