#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val)
        :prev(p),next(n),key(k),value(val){};
    
    Node(int k, int val)
        :prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

    protected: 
        map<int,Node*> mp; //map the key to the node in the linked list
        int cp;  //capacity
        Node* tail; // double linked list tail pointer
        Node* head; // double linked list head pointer
        virtual void set(int, int) = 0; //set function
        virtual int get(int) = 0; //get function

};



class LRUCache : public Cache{


    public:    

        LRUCache(int capacity){   
            cp = capacity;  // capacity of the cache
            head = tail = NULL;   // head and tail are not pointing to anything initially   
            
        }

        virtual void set(int key, int value) override{
            
            // element found in the cache
            // - capacity of the cache reached. Then in that case erase that element and insert 
            // it before the first element
            // - capacity of the cache not reached then also erase that element and insert it 
            // before the first element.


            // element not found in the cache
            // - capacity of the cache reached. Then in that case erase the last element 
            // and insert the new element before the first element
            // - capacity of the cache not reached- Then in that case insert the element
            // before the first element
            auto it = mp.find(key);    
            if(it != mp.end()){  
                // element found in the cache. 

                // if the found element is already the first element then leave it as it is
                if(it->second == head){   
                    // leave the element as it is. Because it is already it its correct position
                    // cout << "Element is found and it is the head element " << key <<  endl; 

                    // only set the node value to value which is passes as argument
                    it->second->value = value; 

                }else{
                    // That found element is not the head then we have to bring that element to the front
                    // cout << "Element is found and it is not the head element" << key << ", " << it->second->value << endl;    

                    Node *current_element = it->second; 
                    // cout << "current element prev's key: " << current_element->prev->key << endl;   

                    if(current_element == tail && mp.size() > 1){
                        tail = current_element->prev; 
                    }  

                    current_element->prev->next = current_element->next;
                    if(current_element->next){
                        current_element->next->prev = current_element->prev; 
                    }      
                    current_element->prev = NULL;      
                    current_element->next = head; 
                    head->prev = current_element;  
                    head = current_element;   



                    // set that element's value as a passed value
                    current_element->value = value; 
                
                }                

            }else{
                // element not found in the cache
                if(mp.size() == 0 && mp.size() < cp){   
                    // cout << "Element not found in the cache and no elements found in the cache and less than cache capacity" << endl;

                    // In that case insert the insert element and make it as a head and tail of the cache  
                    Node *temp = new Node(NULL, NULL, key, value);
                    head = tail = temp;  // make the first element as head and tail of the cache

                    mp[key] = temp; 
                }else if(mp.size() != 0 && mp.size() < cp){  
                    // cout << "element not found in the cache and size of the cache is > 0 and less than cache capacity" << endl; 

                    // 1) create a new node and make it's next to point to head
                    // 2) make the head's prev to point to this node
                    // 3) make this node as head node
                    Node *temp = new Node(NULL, head, key, value); 
                    head->prev = temp; 
                    head = temp;  

                    mp[key] = temp; 
                }else{
                    // capacity of the cache reached to full
                    // cout << "element not found and size of the cache == cache capacity" << endl; 

                    // 1) create a new node and make it's next to point to head   
                    // 2) make the head's prev to point to this node
                    // 3) make this node as a head node
                    // 4) remove the tail node and make the tail's prev's next points to null 
                    // 5) erase the tail node's key from the map datastructure

                    Node *temp = new Node(NULL, head, key, value);
                    head->prev = temp; 
                    head = temp; 
                    
                    Node *prev_tail = tail;     
                    tail->prev->next = NULL; 
                    tail = tail->prev; 
                    
                    mp.erase(prev_tail->key);
                    delete prev_tail; 

                    mp[key] = temp; 

                } // else block - capacity of the cache reached and element not found

            }  /* end of else block */

        }

        virtual int get(int key) override{       

            // get the value of the key if found 
            // else return -1

            auto it = mp.find(key); 
            if(it != mp.end()){
                return it->second->value; 
            }else{
                return -1; 
            }
        }  /* end of get() */

        void display(){
            Node *temp = head; 
            while(temp != NULL){
                cout << temp->key << ", " << temp->value << endl; 
                temp = temp->next;     
            }
        }

        void display_reverse(){   
            Node *temp = tail; 
            while(temp != NULL){   
                cout << temp->key << ", " << temp->value <<endl;
                temp = temp->prev; 
            }
        }

        void display_map(){
            auto it = mp.begin(); 
            while(it != mp.end()){
                cout << it->first << ", " << it->second->value << endl; 
                ++it; 
            }      
        }

};



int main() {
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } 
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
        else if(command=="display"){  
            l.display(); 
        }else if(command == "display_reverse"){  
            l.display_reverse();   
        }   
        else if(command == "display_map"){
            l.display_map();    
        }
    }
    return 0;
}



/* 

- if run separately it's working else it's not working


-1
-1
-1
-1
-1
-1
-1
-1
-1
-1
1195
125
-1
-1
1498
1628
1498
1162
Segmentation fault (core dumped)

500000 644
get 3                       
get 19                     
get 8
set 1 1195
set 5 1404
get 6
set 15 1020
set 7 1010
get 8
set 7 1628
set 16 1498
get 11
get 14
get 19
get 8
set 12 267
set 19 125
get 8               -1   // 10 -1's 
set 15 1241
set 8 1936
get 1               1195
set 17 1162
set 13 151
get 19              125
get 20              -1
get 14              -1
get 16              1498
get 7               1628
set 2 1305
set 12 287
set 9 160
get 16              1498
get 17              1162

                        - working perfectly in till here

set 5 1524  +
                - after inserting 5 
                - missing element in linked list
                7, 16, 19 

                - breaks after this

set 16 81   
set 4 312
set 9 89
                - completely breaks after this    
set 19 1306
set 18 1041
set 16 237
get 8
set 11 387
get 1
get 8
set 7 1733
set 1 1652
get 17
get 8
set 20 1992
set 5 1290
set 13 270
set 3 1236
set 5 1441
set 15 743
set 19 165
get 18
get 17
set 16 193
set 14 1146
get 1
get 9
set 9 831
set 5 444
set 3 302
set 12 1973
get 19


 */

