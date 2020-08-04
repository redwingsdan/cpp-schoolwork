/*
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("ctesting.txt");
  if(myfile.is_open()) {
	 myfile << "Writing this to a file. This is a test.\n";
  }
  myfile.close();
  return 0;
}
*/
//myfile.open("ctesting.txt", ios::out, | ios::app | ios::binary);
//ios::trunc | ios::in;

//out - output (ofstream default)
//in - input (ifstream default)
//binary - binary mode
//app - append content at the end
//trunc - delete content and the fill in with new
/*

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("ctesting.txt");	//opens file for reading
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )	//reads the line from myfile and stores it in the string line
    {
      cout << line << '\n';	//outputs the line that was read
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
*/

