/*
#ifndef FILENAME_H  
#define FILENAME_H 

Declarations...

#endif

The reason we write our declarations in between the #ifndef, #define and #endif 
is to prevent multiple declarations of identifiers such as data types, variables etc. 
when the same header file is invoked in new file belonging to the same project.  

One very important thing to remember is that compiler can see declarations in header file 
but if you try to write code INVOLVING definition of the declaration declared elsewhere, it will 
lead to error since compiler compiles each .c file individually before the proceeding to the linking stage.
*/


#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"   
#include "insert.h"    


void display(NODE* temp){        

    printf("List elements are  \n");           
    while(temp!=NULL){
        printf("%d ", temp->data);   
        temp=temp->link;        
    }             
    printf("\n");       

}  /* end of display */



int main(){
    
    NODE* head=NULL;             

    int choice, data, pos;     

    printf("LINKED LIST IMPLEMENTATION");
    while(1){
        printf("\n 1. Insert in the beginning");
        printf("\n 2. Insert in the Nth position");
        printf("\n 3. Insert in the end");    
        printf("\n 4. Display");  
        printf("\n 0. Exit");        
        printf("\n Enter your choice: ");          
        scanf("%d",&choice);     

        switch(choice){
            case 1:
                /* Insert data in the beginning */
                printf("Enter the data: ");
                scanf("%d",&data);  
                b_insert(&head, data);                
                break;    
            
            case 2: 
                /* Insert data in the nth position */     
                printf("Enter the data: ");
                scanf("%d", &data);     

                printf("Enter the position: ");    
                scanf("%d", &pos);    
                
                n_insert(&head, data, pos);          
                break;   
            
            case 3:
                /* insert data in the end */
                printf("Enter the data: ");
                scanf("%d", &data);  
                
                e_insert(&head, data);       
                break;   

            case 4:
                /* display */   
                display(head);            
                break; 

            case 0:
                return 0;     

            default:
                printf("wrong choice");  
        }  /* end of switch */


    }  /* end of while loop */

    return 0;    

}  /* end of main function */