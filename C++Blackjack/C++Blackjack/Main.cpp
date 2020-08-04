#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Card {
    string newName;
    int newValue;
public:
    Card();

    Card(string, int);

    ~Card();

    string getname() const{
        return newName;
    }

    int getvalue(void) const{
        return newValue;
    }
   
};

Card::Card()  {
    newValue = 0;
}

Card::Card(string a, int b) {
    newName = a;
    newValue = b;
}

Card::~Card() {

}


int main()
{

    srand(time(0));

    string names[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Joker", "Queen", "King", "Ace"};
    string objects[13] = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "joker", "queen", "king", "ace"};

    string* p;

    p = objects;

    int drawagain = 1, total = 0, sum = 0, i, n;
    unsigned int output = rand() % 13;

    Card two (names[0], 2);
    Card three (names[1], 3);
    Card four (names[2], 4);
    Card five (names[3], 5);
    Card six (names[4], 6);
    Card seven (names[5], 7);
    Card eight (names[6], 8);
    Card nine (names[7], 9);
    Card ten (names[8], 10);
    Card joker (names[9], 10);
    Card queen (names[10], 10);
    Card king (names[11], 10);
    Card ace (names[12], 11);

    cout << two.getname() << "-" << two.getvalue() << "\n" <<
        three.getname() << "-" << three.getvalue() << "\n" <<
        four.getname() << "-" << four.getvalue() << "\n" <<
        five.getname() << "-" << five.getvalue() << "\n" <<
        six.getname() << "-" << six.getvalue() << "\n" <<
        seven.getname() << "-" << seven.getvalue() << "\n" <<
        eight.getname() << "-" << eight.getvalue() << "\n" <<
        nine.getname() << "-" << nine.getvalue() << "\n" <<
        ten.getname() << "-" << ten.getvalue() << "\n" <<
        joker.getname() << "-" << joker.getvalue() << "\n" <<
        queen.getname() << "-" << queen.getvalue() << "\n" <<
        king.getname() << "-" << king.getvalue() << "\n" <<
        ace.getname() << "-" << ace.getvalue() << "\n" << endl;


    output = rand() % 13;
    p = p + output;
    cout << "The card you drew is: " << *p << "\n";
    p = p - output;

    cout << "-----------------------------------RULES------------------------------------" << "\n" <<
        "This is a game of Blackjack. You will draw cards with the goal of reaching a " <<"\n" <<
        "total value of '21'. The number cards are worth face value, while the JOKER" <<
        ", " <<"\n" <<"QUEEN,"<< " and KING are worth 10 each. The ACE is worth 11. You will enter the " <<
        "totalnumber of credits you would like to use and will then recieve a card." <<
        " If you "<< "\n" << "would like to receive another card, you will input '1'. If you input " <<
        "ANYTHING" << "\n" <<"else, you will not receive a card and the current game will end. " <<
        "If you have" << "\n" << "additional credits, then a new game will automatically begin." <<"\n\n";
   

    cout << "Please enter the number of credits you would like to use: ";
    cin >> n;

    for(i=0; i<n; i++){
    cout << "-----------------------------------NEW GAME-----------------------------------" << "\n\n";
   
    while(drawagain == 1) {
        output = rand() % 13;
        switch(output) {
    case 1:
    cout << "You drew a: " << three.getname() << "-" << three.getvalue() << "\n";
    total = three.getvalue();
    sum = total + sum;
    break;
    case 2:
    cout << "You drew a: " << four.getname() << "-" << four.getvalue() << "\n";
    total = four.getvalue();
    sum = total + sum;
    break;
    case 3:
    cout << "You drew a: " << five.getname() << "-" << five.getvalue() << "\n";
    total = five.getvalue();
    sum = total + sum;
    break;
    case 4:
    cout << "You drew a: " << six.getname() << "-" << six.getvalue() << "\n";
    total = six.getvalue();
    sum = total + sum;
    break;
    case 5:
    cout << "You drew a: " << seven.getname() << "-" << seven.getvalue() << "\n";
    total = seven.getvalue();
    sum = total + sum;
    break;
    case 6:
    cout << "You drew a: " << eight.getname() << "-" << eight.getvalue() << "\n";
    total = eight.getvalue();
    sum = total + sum;
    break;
    case 7:
    cout << "You drew a: " << nine.getname() << "-" << nine.getvalue() << "\n";
    total = nine.getvalue();
    sum = total + sum;
    break;
    case 8:
    cout << "You drew a: " << ten.getname() << "-" << ten.getvalue() << "\n";
    total = ten.getvalue();
    sum = total + sum;
    break;
    case 9:
    cout << "You drew a: " << joker.getname() << "-" << joker.getvalue() << "\n";
    total = joker.getvalue();
    sum = total + sum;
    break;
    case 10:
    cout << "You drew a: " << queen.getname() << "-" << queen.getvalue() << "\n";
    total = queen.getvalue();
    sum = total + sum;
    break;
    case 11:
    cout << "You drew a: " << king.getname() << "-" << king.getvalue() << "\n";
    total = king.getvalue();
    sum = total + sum;
    break;
    case 12:
    cout << "You drew an: " << ace.getname() << "-" << ace.getvalue() << "\n";
    total = ace.getvalue();
    sum = total + sum;
    break;
    default:
    cout << "You drew a: " << two.getname() << "-" << two.getvalue() << "\n";
    total = two.getvalue();
    sum = total + sum;
    break;
        }
        cout << "Your total so far is: " << sum << "\n\n";
        if(sum < 21){
        cout << "Enter '1' to draw again. Enter any other number to stop.";
        cin >> drawagain;
        cout << "\n";
        }
        else if(sum == 21){
            cout << "YOU HAVE ACHIEVED BLACKJACK. YOU WIN! " << "YOU HAVE EARNED TWO CREDITS.";
            drawagain = 0;
            n = n + 2;
        }
        else{
            cout << "YOU HAVE GONE OVER BLACKJACK. YOU LOSE.";
            drawagain = 0;
        }
    }
    if(sum == 20){
        cout << "YOU HAVE RESULTED IN A DRAW. YOU EARN ONE CREDIT." << "\n";
        n = n + 1;
    }

    cout << "\n\n" << "Your total card sum was: " << sum << "\n\n\n\n";
    if(i<n){
        drawagain = 1;
        sum = 0;
    }

    }
    return 0;
}