#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	ofstream constr("construction.txt");

	int lines;

	if(constr.is_open())
	{
		constr << "EVENT\t\tTASK\t\tNUMBER OF DAYS\n\n";
		constr << "  1  \t\t 15 \t\t        3\n";
		lines++;
		constr << "  1  \t\t 27 \t\t        6\n";
		lines++;
		constr << "  1  \t\t 36 \t\t        4\n";
		lines++;
		constr << "  2  \t\t 15 \t\t        5\n";
		lines++;
		constr << "  3  \t\t 18 \t\t        4\n";
		lines++;
		constr << "  3  \t\t 26 \t\t        1\n";
		lines++;
		constr << "  4  \t\t 15 \t\t        2\n";
		lines++;
		constr << "  4  \t\t 26 \t\t        7\n";
		lines++;
		constr << "  4  \t\t 27 \t\t        7\n";
		lines++;
		constr << "  5  \t\t 16 \t\t        4\n";
		lines++;
		constr.close();
	}
	
	ifstream constrin;
	int i, events[11] = {0};
	int days[11], sum, tasks[11], maxdays(0), x;
	int total = 0;
	string entries;
	//char str[100];
	//char str_copy[100];
	//string entries;
	constrin.open("construction.txt");
	cout << "EVENT NUMBER\tTASK NUMBER\n\n";
	//cout << lines;
	if(constrin.is_open())
	{
		getline (constrin, entries);
		for(i=1;i<(lines+1);i++){
		//getline(constrin, entries);
		constrin >> events[i] >> tasks[i] >> days[i];
		//cout << days[i] << "\n\n\n\n\n\n";
		//cout << events[i] << "\t" << tasks << "\t" << days[i] << "\n";
		if(days[i] >= 5){
			x = days[i];
			cout << events[i] << "\t\t" << tasks[i] << "\n\n";
		}
		
		//cout << entries;
		//constrin >> str;

		//if(str != str_copy){
		//	std::string entries;
		//	getline(constrin, entries);
		//	cout << entries <<endl;
		//	str_copy[1] = str[1];
		//}
		
		}
	//	cout << events[i-1] << "\t\t" << maxdays << "\n\n";
	//	total += maxdays;
	//	cout << "The total number of days for the project to be completed is " 
	//		 << total << ".\n\n";
	}
	
	return 0;
}