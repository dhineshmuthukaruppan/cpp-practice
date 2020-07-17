#include<bits/stdc++.h>

using namespace std;

class Workshop{
    public:
        int start_time; 
        int duration;
        int end_time;   

};  /* end of class Workshop */


class Available_Workshops{

    public:
        int n; 
        Workshop *W;    
        
        Available_Workshops(int n){
            this->n = n; 
            this->W = new Workshop[this->n]; 
        }

};  /* end of class Available_Workshops */


Available_Workshops* initialize(int *start_time, int *duration, int n){

    Available_Workshops *node = new Available_Workshops(n);     

    for(int i=0; i<n; i++){
        (node->W)[i].start_time = start_time[i];
        (node->W)[i].duration = duration[i];
        (node->W)[i].end_time = start_time[i] + duration[i]; 
    }

    return node;    

}  /* end of initialize() */

bool compare(const Workshop &a, const Workshop &b)
{
    if(a.end_time < b.end_time)
        return true;
    return false;
}

int CalculateMaxWorkshops(Available_Workshops *ptr){

    sort(ptr->W, ptr->W + ptr->n, compare); 

    int count = 1, current_running_time;     

    for(int i=0; i<ptr->n; i++){
        if(i == 0){
            current_running_time = (ptr->W[i]).end_time; 
            continue; 
        }

        if((ptr->W[i]).start_time >= current_running_time){
            count++; 
            current_running_time = (ptr->W[i]).end_time; 
        }

    }

    return count;   

}  /* end of CalculateMaxWorkshops */



int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops *ptr;     
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
