#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four(int a, int b, int c, int d){
    int answer = -32768; 

    a > answer ? answer = a : NULL; 
    b > answer ? answer = b : NULL; 
    c > answer ? answer = c : NULL; 
    d > answer ? answer = d : NULL; 

    return answer;    

} // end of max_of_four


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}