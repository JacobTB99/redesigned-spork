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
/*
    * Purpose: Checks whether a given target substring exists within the primary string.
    * Parameters: mainString is the primary string to search, target is the substring to search for.
    * Preconditions: Both input parameters must be strings.
    * Postconditions: Returns the amount of occurrences of the substring within the primary string.
*/
void caseMatch(string &string);
/*
    * Purpose: Sets all characters of a string to be lower case.
    * Parameters: Takes the parameter string of type string by reference.
    * Preconditions: The argument must be a string.
    * Postconditions: The string is converted to all lower case.
*/

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
    if(count == -1)
    {
        cout << "The substring " << substring << " does not occur in the main string." <<  endl;
    }
    else
    {
    cout << "The substring " << substring << " occurs " << count << " times in the main string." << endl;
    }
    return 0;
}

//subsidary definitions
int checkString(string mainString, string target) {
    caseMatch(mainString);
    caseMatch(target);
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