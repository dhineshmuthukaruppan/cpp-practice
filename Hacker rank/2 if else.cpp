#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> vec {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if(n > 9){
        cout << "Greater than 9"; 
    }else{
        cout << vec[n-1];
    }

    // Write Your Code Here

    return 0;
}