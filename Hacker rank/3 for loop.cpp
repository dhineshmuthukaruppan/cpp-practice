#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b; 

    vector<string> vec {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i=a; i<=b; i++){
        if(i>9){
            // if it is even, print even 
            if(i % 2 == 0){
                cout << "even" << endl; 
            }else{
                cout << "odd" << endl;
            } // else print odd in new line
        }else{
            cout << vec[i-1] << endl;
        }
    }

    // Write Your Code Here

    return 0;
}