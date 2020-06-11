#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string str1; 
    string str2;

    cin >> str1; 
    cin >> str2; 

    cout << str1.length() << " " << str2.length() << endl; 
    cout << str1+str2 << endl;
    char temp_c= str1[0];
    str1[0] = str2[0];
    str2[0] = temp_c; 
    cout << str1 << " " << str2 << endl;   


    return 0;
}