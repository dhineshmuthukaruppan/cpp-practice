#include <iostream>
#include <cstdlib>

using namespace std;         


int sumOfElements(int* a, int size){    
    int sum=0;

    cout << "2nd element value" << *(++a) << endl;     //2

    cout << size << endl;               

    return sum;        
}  /* emd of sumOfElements */


void doubleTheElements(int a[]){      
    //size of array cannot be find by using sizeof operator. 
    //because only reference to first array element is what we
    //have received from the above parameter int a[]. If i put
    //sizeof(a) then it would return 4 bytes as a result instead 
    //20 bytes since the actual size of the array is 20 bytes

    cout << "3rd element value" << *(a+2) << endl;     //3  
    cout << "1st element again " << *a <<endl;     //1

    while(*a != 99999){     

        *a=*a*2;    

        // cout << "doubled" << endl;                 

        a++;           
    }


    //a++;   // a++ is possible because what we have here is 
        // pointer to array a. 


}  /* end of doubleTheElements */         


int main(){      

    int a[]={1,2,3,4,5,99999};



    cout << a << endl;   /* 0x7ffcc4211c20 */
    cout << &a[0] << endl;  /* 0x7ffcc4211c20 */ 

    cout << *a << endl;    //1
    cout << a[0] << endl;  //1     

    int *p = a;    
    cout << *(p++) <<endl;   //2 

    // a++;   is not possible but p++ is possible because it is pointer to 
    //         array 
    // but p++ is possible because it is pointer 

    int *fourth_element = a+3;   
    cout << "fourth element value is " << *fourth_element << endl;               

    cout << "3rd element value address on main function "<< a+2 << endl;  
    cout << "3rd element value on main function " << *(a+2) << endl;     //3

    int sizeOfArray=sizeof(a)/sizeof(a[0]);                      

    int sum=sumOfElements(a, sizeOfArray);  

    cout << "Sum of array" << sum << endl;       


    doubleTheElements(a);        


    /* array after calling the doubleTheElements */      

    // while(*a != 99999){

    //     cout << "Array after calling doubleTheElements " << *a;     

    //     a++;     // this is not possible
    // }            


    int i=0;
    while(a[i] != 99999){
        cout << "Array after doubling the elements " << a[i] << endl;      
        i++;       
    }

    return 0;    
}
