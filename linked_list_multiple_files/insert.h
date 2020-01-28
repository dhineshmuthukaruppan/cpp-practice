#ifndef INSERT_H 
#define INSERT_H 

typedef struct Node NODE;  
NODE* create_node(int data);
void b_insert(NODE** head, int data);     
void n_insert(NODE** head, int data, int pos);    
void e_insert(NODE** head, int data);      

#endif



