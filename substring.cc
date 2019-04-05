/*
    * Program: substring.cc
    * Author: Jacob Beauchamp
    * Date: April 4, 2019
    * Description: 
*/

//directives
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

//prototypes
int checkString(string mainString, string target);
void caseMatch(string &string);


//begin program
int main() {
    string mainString;
    string substring;
    string printstring;
    int count;
    cout << "Enter some text: ";
    getline(cin, mainString);
    cout << "Enter a target substring: ";
    getline(cin, substring);
    printstring = substring;
    count = checkString(mainString, substring);
    cout << "The substring " << substring << " occurs " << count << " times." << endl;
    return 0;
}

//subsidary definitions
int checkString(string mainString, string target) {
    caseMatch(mainString);
    caseMatch(mainString);
    size_t position = 0;
    size_t newPosition;
    int count = 0;
    position = mainString.find(target);
    if(position == string::npos)
    {
        return -1;
    }
    while(position != string::npos)
    {
        count ++;
        newPosition = position + 1;
        position = mainString.find(target, newPosition);
    }
/*
    {
        position ++;
        count ++;
        newPosition = mainString.find(target, position);
    }*/
    return count;
}

void caseMatch(string &string) {
    int length = string.length();
    for(int i = 0; i < length; i ++)
    {
        if(isupper(string[i]))
        {
            string[i] = tolower(string[i]);
        }
    }
}
/*
 *Guidelines:
 *
 * Extra credit: Due: Thursday April 4 (11:59 PM).
 * Write a function that counts the number of occurrences of a substring in a line
 * of text. The function should work for both upper and lowercase characters.
 * For example,
 *           number = countOccurrences("aBC", "ABCdeaBcfgAbcd");
 * should assign 3 to number.
 * Write a main program to test your function.
 * To submit the extra credit, you must create a public repository on GitHub and tag me (@nasseef) when
 * you are done.
 *
*/