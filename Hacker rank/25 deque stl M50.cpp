/* 
Input format
First line of input will contain the number of test cases T. For each test case, 
you will be given the size of array N and the size of subarray to be used K. 
This will be followed by the elements of the array Ai.


Sample Input

2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

Sample Output

4 6 6 4
8 8 8 10 

*/


#include<iostream>
#include <deque>
#include<algorithm>

using namespace std; 

void printKMax(int a[], int n, int s){   
    int max {-1}; 
    deque<int> deq; 
    for(int i=0; i<s; i++){
        deq.push_back(a[i]);   
    }
    max = *(max_element(deq.begin(), deq.end()));   

    cout << max; 

    for(int i=s; i<n; i++){
        // push the current element to the deq
        deq.push_back(a[i]);   
        if(max == deq[0]){
            deq.pop_front(); 
            max = *(max_element(deq.begin(), deq.end()));  
            cout << " " << max; 
            
        }else{
            deq.pop_front(); 
            if(a[i] > max){
                max = a[i];
            }
            cout << " " << max; 
        } 
    }

    cout << endl;
}  /* end of printKMax */


int main(){

    int T, n, s; // T - no of test cases, n - no of elements, s- size of the subarray to be used

    cin >> T; 

    for(int i=0; i<T; i++){
        cin >> n >> s;
        int a[n]; 
        for(int i=0; i<n; i++){ 
            cin >> a[i];
        } 

        printKMax(a, n, s);   


        // for(int i=0; i<(n-s+1); i++){   
            /* Return value
            Iterator to the greatest element in the range [first, last). If several elements in the 
            range are equivalent to the greatest element, returns the iterator to the first such 
            element. Returns last if the range is empty.  */
            // working but takes too much time because of loops
            // auto result = max_element(deq.begin()+i, deq.begin()+i+s); 
            // cout << *result << " ";  

        // }
        // cout << endl; 
    }

    return 0;

}  /* end of main() */