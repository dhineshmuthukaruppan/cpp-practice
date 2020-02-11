/* 
status - accepted  - 77


Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   

void push_to_stack(int stack[],int element,int pos){
    stack[pos]=element;         
    
}    

int* plusOne(int* A, int n1) {
    
    
    int *len1;     
    
    int stack[n1+1];   
    
    printf("stack n value %d \n", stack[n1]);  //32764
    
    
    int sum=0;              
    int power=0;
    int k,leading_zeros_count=0, non_zero_numbers_started=0, pushed_count=0;                         


    for(k=0; k<n1+1; k++){
        stack[k]=0;     
    }    
    
    


    for(k=n1-1; k>=0; k--){
        sum+= *(A+k) * pow(10,power) ;   
        power++;                  
    }      
    
    sum++;    
    
    printf("intermediate sum %d \n",sum);  // 130 
    

    while(sum!=0){     
        push_to_stack(stack,sum%10, pushed_count++);           
        sum=floor(sum/10); 
    }


    for(k=n1; k>=0; k--){    
        if(stack[k] != 0 ){     
            break; 
        }else{
            leading_zeros_count++;     
        }
    }
    
    printf("Leading zeros %d \n", leading_zeros_count );      
    
    pushed_count-=leading_zeros_count;          
    
    printf("pushed count %d \n", pushed_count);      

    if(pushed_count==0){
        len1= (int *) malloc(sizeof(int) + 4);             
    }else{
        len1= (int *) malloc(sizeof(int) * pushed_count + 4);        
    }

    
    int *out=len1;      
    
    
    for(k=n1; k>=0; k--){   
        
        if(stack[k]==0){
            if(non_zero_numbers_started==0){
                non_zero_numbers_started=1; 
            
            }else{     
                *out=stack[k];
    
                out++;  
            }
        }else{
            
            non_zero_numbers_started=1;             
            
            *out=stack[k];             
            
            out++;    
        }   

    }  
    
    *out=99999;    
    
    

    return len1;     
}



int main() {
    
    int a[2] = {5,6};          
    

    
    int *len1=plusOne(a, 2);           
    
    printf("console log starting \n");           
    
    while(*len1 != 99999){
        
        printf("%d ", *len1);          
        len1++;    
    }      
    
    printf("\n");    
    
    
    return 0; 
}

/* output
    2 5 6 8 6 1 2 4 6 
 */




/* 
    Javascript solution

    plusOne : function(A){

        var carry=1;        
        for(var i=A.length-1; i>=0; i--){
            if(A[i]==9){
                if(carry==1){
                    A[i]=0;
                    carry=1;    
                }     
            }else{
                A[i]+=carry;        
                carry=0;        
            }    
        }

        if(carry==1){
            A.unshift(1);    
        }

        var remove_zero_first=true;    
        var new_array=[];     

        for(var i=0;i<A.length; i++){
            //console.log(A);  
            if(A[i]==0){
            
                if(remove_zero_first==true){     
                    //A.shift();    
                    //console.log("shifted one");
                    // do nothing
                }else{
                
                    new_array.push(A[i]);
                }   
            }else{
                
                new_array.push(A[i]);
                remove_zero_first=false;    
                //console.log(i);   
            
            }
            
        }  
        return new_array;     

    }

*/  


