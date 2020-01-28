#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node NODE;     

struct Node{
    int data;     
    struct Node* link;     
};  

void display(NODE* temp);    /* not needed */    



#endif