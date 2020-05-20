
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"                     

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
