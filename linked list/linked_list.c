#include <stdio.h>
#include <stdlib.h>

/**
 * Declaration - start 
 **/

typedef struct Node NODE;       


/**  
 * Declaration - end 
 **/

struct Node{
    int data;     
    struct Node* link;     
};     

NODE* create_node(int data){
    NODE* temp=(NODE *)malloc(sizeof(NODE));     
    temp->data=data;     
    temp->link=NULL; 
    return temp;    

}  /* end of create_node */

void b_insert(NODE** head, int data){    
    NODE* new_node=create_node(data);     

    new_node->link=*head;     
    *head=new_node;     
    printf("Data Inserted in the beginning is %d", new_node->data);        

}  /* end of b_insert */      

void n_insert(NODE** head, int data, int pos){     

    if(*head == NULL){
        b_insert(head, data);     
        return ;         
    }

    NODE* new_node=create_node(data);     
    NODE* temp= *head;     

    for(int i=0; i<pos-2; i++){
        temp=temp->link;  
    }

    new_node->link=temp->link;     
    temp->link=new_node;    

}  /* end of n_insert */

void e_insert(NODE** head, int data){        

    if(*head==NULL){
        b_insert(head, data); 
        return;      
    }

    NODE* new_node=create_node(data);       
    NODE* temp=*head;    

    while(temp->link != NULL){    
        temp=temp->link;     
    }

    temp->link=new_node;     

}  /* end of e_insert */


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

