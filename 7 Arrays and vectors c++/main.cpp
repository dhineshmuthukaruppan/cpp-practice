/* 
    2) arrays
    
    - compound data type or data structure
    - collection of elements
    - all elements are of the same type
    - each element can be accessed directly

    Characteristics
    ---------------
    - fixed size
    - elements are all the same type
    - stored contiguosly in memory
    - individual elements can be accessedby their position or index

    - first element is at index 0
    - last element is at indexsize - 1

    - No checking to see if you are out of bounds 

    - Always initialize arrays
    - very efficient
    - iteration is often used to process

*/



/* 3) declaring and initializing arrays

    int testscore [5]; // size is fixed so the compiler must know the size of the whatever in the square brackets in compile time
    const double days_in_year {365};   
    double hi_temperature [days_in_year];  

    - Best practice is to always initialize the array

    int testscores [5] {100, 95 90, 98, 66}
    int highscore [10] {3,5}; // init to 3,5 and remaining to 0
    const double days_in_year {365};  
    double hi_temperature [days_in_year] {0}; // init all to zero

    int another_array [] {1,2,3,4,5}; // size automatically calculated

 */



/* 4) accessing and modifying array elements
    - The name of the array represent the location of the first element in the array (index 0)
    - the [index] represents the offset from the beginning of the array
    - c++ performs the calculation to find the correct element
    - no bounds checking 

 */


/* 
    6) multidimensional arrays

    int movie_rating [3][4]
    - the total size of the array is 12 integers

        0   1   2   3
    --------------------
    0   0   4   3   5

    1   2   3   5   5

    2   1   4   4   5   
    
    movie_rating[1][2] = 5
    int movie_rating[3][4]
    {
        {0, 4, 3, 5},
        {2, 3, 5, 5},
        {1, 4, 4, 5}
    }
 */



/* 7) Declaring and initializing vectors 
    - suppose we want to store test scores for my school
    - I have no way of knowing how many students will register next year
    - options
        - pick a size that you are not likely to exceed and use static arrays
        - use a dynamic array such as vector

    vector?
    - container in the c++ STL
    - An array that can grow and shrink in size at execution time
    - provides similar semantics and syntax as array
    - very efficient
    - can provide bounds checking
    - can use lots of cool function like sort, reverse, find and more. 
    
        vector <char> vowels; // create empty vectors with no elements 
        vector <int> testscores (5); // tells compiler that you want 5 integers. Unlike array these 5 integers will be automatically set to 0.
        
        initializing
        ------------
        vector <char> vowels {'a', 'e'}; 
        vector <double> hitemperature (365, 80.0); // 365 is the size of the vector and initialize everything to 80.0

        characteristics
        ---------------
        - dynamic size
        - elements are all the same type
        - stored contiguosly in memory
        - individual elements can be accessed by their position or index
        - first element index is at 0
        - last element index is at indexsize-1
        - []- no checking to see if you are out of bounds
        - provides many useful function that do bounds check
        - elements initialized to zero automatically unlike arrays and won't contain garbage
        - very efficient
        - iteration is often used to process

*/ 


/* 8) accessing and modifying vector elements

    vector <int> test_scores {100, 95}
    test_scores[0]; // 100
    rest_scores.size(); // 2

    test_scores.at(0); 
    test_scores.at(0)=90; //assignment statement 
    test_scores.push_back(80); // add 80 to the end of the vector and automatically allocate the required space

    int score_to_add {0};  
    cin >> score_to_add; 
    test_scores.push_back(score_to_add);   

    test_scores.size(); // 4


    What is you are out of bounds?
    - arrays never do bounds checking
    - many vector methods provide bounds checking
    - An exception and error message is generated


    Example of 2D vectors

    vector <vector<int>> movie_ratings
    {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}  
    }
    movie_ratings[0][0]; // 1
    movie_ratings.at(0).at(0); //1


 */



#include <iostream>
#include <vector>


using namespace std;    


int main(){

    char vowels [] {'a', 'e', 'i', 'o', 'u'};   
    cout << "The first vowel is " << vowels[0] << endl;    
    vowels[0] = 'e';  // assignment 





    return 0;  

}  /* end of main function */