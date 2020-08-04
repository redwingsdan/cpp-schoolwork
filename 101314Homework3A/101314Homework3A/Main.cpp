#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int lines;

	ofstream accountingout("accounting2.txt");
	if(accountingout.is_open())
	{
		accountingout << "$3200,$100, 67\n";
		lines++;
		accountingout << "$287.63,$82.13\n";
		lines++;
		accountingout << "$67093.10,$32.50\n";
		lines++;
		accountingout << "$(200.56),(15.67)\n";
		lines++;
		accountingout.close();
	}

	ofstream accountingoriginal("accounting1.txt");
	if(accountingoriginal.is_open())
	{
		accountingoriginal << "$3200,$100\n";
		accountingoriginal << "$287.63,$82.13\n";
		accountingoriginal << "$67093.10,$32.50\n";
		accountingoriginal << "$(200.56),(15.67)\n";
		accountingoriginal.close();
	}


	fstream accountingin("accounting2.txt");
	
	int i;
	char chChar;
	while(accountingin.get(chChar)){

		switch(chChar)
		{
		case '$':
			accountingin.seekg(-1, ios::cur);
			accountingin << ' ';
			accountingin.seekg(accountingin.tellg(), ios::beg);
			break;
		case ',':
			accountingin.seekg(-1, ios::cur);
			accountingin << ' ';
			accountingin.seekg(accountingin.tellg(), ios::beg);
			break;
		case '(':
			accountingin.seekg(-1, ios::cur);
			accountingin << '-';
			accountingin.seekg(accountingin.tellg(), ios::beg);
			break;
		case ')':
			accountingin.seekg(-1, ios::cur);
			accountingin << ' ';
			accountingin.seekg(accountingin.tellg(), ios::beg);
			break;
		}
		if (accountingin){
			continue;
		}
		else{
		accountingin.close();
	}
	}

	ifstream accountingio ("accounting2.txt");

	if(accountingio.is_open()){
		for(i=0;i<lines;i++){
		std::string entries;
		getline(accountingio, entries);
		cout << entries << endl;
		}
	}
	return 0;
}