//preprocessor directives
#include <iostream>
#include <string>
#include <windows.h>

//the use of only what you need in the namespace reduces the bulk of your code.
using std::cout;
using std::cin;
using std::endl;
using std::string;

//check if number is string before proceding and make sure to pass by reference to avoid any unneccessary copying
bool isNumberString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}
//the Luhn Check
bool checkLuhn(const string& cardNo)
{
    int nDigits = cardNo.length();

    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {

        int d = cardNo[i] - '0';

        if (isSecond == true)
            d = d * 2;

        // We add two digits to handle
        // cases that make two digits after
        // doubling
        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}
int main() {
    string ccNumber;

    cout << "This program uses the Luhn Algorigthm to validate a CC number." << endl;
    cout << "You can enter 'exit' anytime to quit." << endl;

    while (true) {

        cout << "Please enter a CreditCard number to validate: ";
        cin >> ccNumber;

        if (ccNumber == "exit")
            break;

        else if (!isNumberString(ccNumber)) {
            cout << "Bad input! " << endl;
            continue;
        }
        else if (isNumberString(ccNumber)) 
        {
            if (checkLuhn(ccNumber))
                cout << "This is a valid card" << endl;
            else
                cout << "This card is invalid" << endl;
        }
        Sleep(2000);
        

        continue;
    }
    return 0;
}