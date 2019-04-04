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
using namespace std;

//prototypes
int checkString(string mainString, string target);


//begin program
int main(int argc, const char *argv[]) {
    string mainString;
    string substring;
    cout << "Enter some text: ";
    getline(cin, mainString);
    //cout << mainString << endl;
    checkString(mainString, substring);
    return 0;
}

//subsidary definitions
int checkString(string mainString, string target) {
    int unsigned position = 0;
    int counter = 0;
    while(position != string::npos)
    {
        position = mainString.find(target, position);
        if(position != string::npos)
        {
            counter ++;
            position ++;
        }
    }    
    return counter;
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