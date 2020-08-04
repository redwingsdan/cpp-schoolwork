#include <iostream>

using namespace std;

int main()
{
char ch;
int ecount=0, vowels=0, other=0;
cin.get(ch);
while(!cin.eof()) {
     switch(ch) {	case 'e':	 ecount++;
	case 'a':
	case 'i':
	case 'o':
	case 'u': vowels++;
	               break;
	default:	other++;
       } //end switch
       cin.get(ch);
}  //end while
cout << ecount << "," << vowels << "," << other << endl;

return 0;

}
