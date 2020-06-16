/* 20) associative containers - sets 


From the C++ Standard (23.2.4 Associative containers)

3 The phrase “equivalence of keys” means the equivalence relation imposed by the comparison 
and not the operator== on keys. That is, two keys k1 and k2 are considered to be equivalent 
if for the comparison object comp, comp(k1, k2) == false && comp(k2, k1) == false. For any 
two keys k1 and k2 in the same container, calling comp(k1, k2) shall always return the same 
value.

Member function find seeks a key according to the comparison object comp

If you did not specify explicitly the comparison object then the class uses by default 
standard functional object std::less that uses operator < within its operator function. So 
your class has to have the operator < defined.

If you want to use operator == for comparison values in the set then you can use standard 
algorithm std::find instead of the method find.


    - associative containers
        - collection of stored objects that allow fast retrieval using a key
        - stl provides sets and maps
        - usually implemented as a balanced binary tree such as red black trees or hash sets
        - most operations are very efficient
        - will use operator< for s.find() operations
    
    sets
        std::set
        std::unordered_set
        std::multiset
        std::unordered_multiset

    std::set
    #include <set>
    - similar to mathematical set
    - ordered by key
    - no duplicate elements
    - all iterators available and invalidate when corresponding element is deleted


    std::multi_set
    #include <set>
    - sorted by key
    - allows duplicate element
    - all iterators are available


    std::unordered_set
    #include <unordered_set>
    - elements are unordered
    - no duplicate elements allowed
    - elements cannot be modified
        - must be erased and new element inserted
    - no reverse iterators are allowed

    std::unordered_multiset
    #include <unordered_set>
    - elements are unordered
    - allows duplicate elements
    - no reverse iterators are allowed


    // Section 20
    // Set
    #include <iostream>
    #include <set>

    class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    public:
        Person() : name{"Unknown"}, age{0} {}
        Person(std::string name, int age) 
            : name{name}, age{age}  {}
        bool operator<(const Person &rhs) const {
            return this->age < rhs.age;
        }
        bool operator==(const Person &rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }
    };

    std::ostream &operator<<(std::ostream &os, const Person &p) {
        os << p.name << ":" << p.age;
        return os;
    }

    template <typename T>
    void display(const std::set<T> &l) {
        std::cout << "[ ";
        for (const auto &elem: l) {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }

    void test1() {
        // Sets
        std::cout << "\nTest1 =========================" << std::endl;
        std::set<int> s1 {1, 4, 3, 5, 2};
        display(s1);
        
        s1 = {1,2,3,1,1,2,2,3,3,4,5};
        display(s1);
        
        s1.insert(0);
        s1.insert(10);
        
        display(s1);
        
        if (s1.count(10)) 
            std::cout << "10 is in the set" << std::endl;
        else
            std::cout << "10 is NOT in the set" << std::endl;

        auto it = s1.find(5);
        if (it != s1.end())
            std::cout << "Found: " << *it << std::endl;    
            
        s1.clear();
        
        display(s1);
    }

    void test2() {
        std::cout << "\nTest2 =========================" << std::endl;
        std::set<Person> stooges {
            {"Larry", 1},
            {"Moe", 2},
            {"Curly", 3}
        };
        display(stooges);           // Note the order of display!  operator<

        stooges.emplace("James", 50);   
        display(stooges);

        stooges.emplace("Frank", 50); // NO -- 50 already exists
        display(stooges);
        
        auto it = stooges.find(Person{"Moe", 2});
        if (it != stooges.end())
            stooges.erase(it);
        
        display(stooges);
        
        it = stooges.find(Person("XXXX", 50));      // Will remove James!!!!
                                                    // uses operator<
        if (it != stooges.end())
            stooges.erase(it);
        display(stooges); 
    }

    void test3() {
        std::cout << "\nTest3 =========================" << std::endl;
        
        std::set<std::string> s {"A", "B", "C"};
        display(s);
        
        auto result = s.insert("D");
        display(s);
        
        std::cout << std::boolalpha;
        std::cout << "first: " <<  *(result.first)<< std::endl;
        std::cout  << "second: " << result.second << std::endl; 
        
        std::cout << std::endl;

        result = s.insert("A");
        display(s);
        
        std::cout << std::boolalpha;
        std::cout << "first: " <<  *(result.first)<< std::endl;
        std::cout  << "second: " << result.second << std::endl; 
    }

    int main() {
        test1();
        test2();
        test3();
        return 0;
    }


*/




/* 21) associative containers maps 

    STL map containers
    - associative containers
        - collection of stored objects that allow fast retrieval using a key
        - stl provides sets and maps
        - usually implemented as balanced binary tree or hashsets
        - most operations are very efficient

    -maps
        - std::map
        - std::multimap
        - std::unordered_map
        - std::unordered_multimap


    std::map
    #include <map>
    - similar to a dictionary
    - elements are stored as key, value pairs (std::pair)
    - ordered by  key
    - no duplicate elements (keys are unique)
    - direct element access using the key
    - all iterators available and invalidate when corresponding element is deleted



    std::multi_map
    #include <map>
        - ordered by key
        - allows duplicate elements
        - all iterators are available


    std::unordered_map
    #include <unordered_map>
    - elements are unordered
    - no duplicate elements allowed
    - no reverse iterators are allowed


    std::unordered_multimap
    #include <unordered_map>
    - elements are unordered
    - allows duplicate element
    - no reverse iterators are allowed

    // Section 20
    // Map

    #include <iostream>
    #include <map>
    #include <set>


    void display(const std::map<std::string, std::set<int>> &m) {
        std::cout << "[ ";
        for (const auto &elem: m) {
            std::cout << elem.first << ": [ " ;
                for (const auto &set_elem : elem.second)
                    std::cout << set_elem <<  " ";
                std::cout << "] " ;
        }
        std::cout << "]  " << std::endl;
    }

    template <typename T1, typename T2>
    void display(const std::map<T1, T2> &l) {
        std::cout << "[ ";
        for (const auto &elem: l) {
            std::cout << elem.first << ":" << elem.second << " ";
        }
        std::cout << "]  " << std::endl;
    }

    void test1() {
        // Maps
        std::cout << "\nTest1 =========================" << std::endl;
        std::map<std::string, int> m {
            {"Larry", 3},
            {"Moe", 1},
            {"Curly", 2}
        };
        display(m);      
        
        m.insert( std::pair<std::string, int>("Anna", 10));
        display(m);
        
        m.insert(std::make_pair("Joe", 5));
        display(m);
        
        m["Frank"] = 18;
        display(m);
        
        m["Frank"] += 10;               
        display(m);
        
        m.erase("Frank");
        display(m);
        
        std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
        std::cout << "Count for Frank: " << m.count("Frank") << std::endl;
        
        auto it = m.find("Larry");
        if (it != m.end())
            std::cout << "Found: " << it->first << " : " << it->second << std::endl;    
            
        m.clear();
        
        display(m);

    }

    void test2() {
        std::cout << "\nTest2 =========================" << std::endl;
        
        std::map<std::string, std::set<int>> grades  {
            {"Larry", {100, 90} },
            {"Moe",  {94} },
            {"Curly", {80, 90, 100} }
        };
        
        display(grades);
        
        grades["Larry"].insert(95);                 // insert 95 into the set of grades for "Larry"
        
        display(grades);
        
        auto it = grades.find("Moe");
        if (it != grades.end())                         // found "Moe"
        {
                it->second.insert(1000);            // insert 1000 into Moe's set of grades
        }                                                         // it->first is the key, it->second is the value (set)
        display(grades);
    }

    int main() {
        test1();
        test2();
        return 0;
    }

*/


/* 22) section challenge 3 

    // Section 20
    // Challenge 3 - Solution 
    // Maps and Sets

    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <map>
    #include <set>
    #include <string>
    #include <iomanip>

    // Used for Part1
    // Display the word and count from the 
    // std::map<std::string, int>

    void display_words(const std::map<std::string, int> &words) {
        std::cout << std::setw(12) << std::left << "\nWord"
                    << std::setw(7) << std::right << "Count"<< std::endl;
        std::cout << "===================" << std::endl;
        for (auto pair: words)
            std::cout << std::setw(12) << std::left << pair.first 
                        << std::setw(7) << std::right << pair.second << std::endl;
    }

    // Used for Part2
    // Display the word and occurences from the 
    // std::map<std::string, std::set<int>>

    void display_words(const std::map<std::string, std::set<int>> &words)
    {
        std::cout << std::setw(12) << std::left << "\nWord"
                    << "Occurrences"<< std::endl;
        std::cout << "=====================================================================" << std::endl;
        for (auto pair: words) {
            std::cout << std::setw(12) << std::left << pair.first 
                        << std::left << "[ ";
            for (auto i: pair.second) 
                std::cout << i << " ";
            std::cout << "]" << std::endl;
        }
    }

    // This function removes periods, commas, semicolons and colon in 
    // a string and returns the clean version
    std::string clean_string(const std::string &s) {
        std::string result;
        for (char c: s) {
            if (c == '.' || c == ',' || c == ';' || c == ':')
                continue;
            else
                result += c;
        }
        return result;
    }

    // Part1 process the file and builds a map of words and the 
    // number of times they occur in the file

    void part1() {
        std::map<std::string, int> words;
        std::string line;       
        std::string word;   
        std::ifstream in_file {"../words.txt"};
        if (in_file) {
            while (std::getline(in_file, line)) {
                //std::cout << line;
                std::stringstream ss(line);
                while (ss >> word) {
                    word = clean_string(word);
                    words[word]++;      // increment the count for the word in the map
                }
            }
            in_file.close();
            display_words(words);
        } else {
            std::cerr << "Error opening input file" << std::endl;
        }
    }
        
    // Part1 process the file and builds a map of words and a 
    // set of line numbers in which the word appears
    void part2() {
        std::map<std::string, std::set<int>> words;
        std::string line;
        std::string word;
        std::ifstream in_file {"../words.txt"};
        if (in_file) {
            int line_number = 0;
            while (std::getline(in_file, line)) {
                //std::cout << line;
                line_number++;
                std::stringstream ss(line);
                while (ss >> word) {
                word = clean_string(word);
                words[word].insert(line_number);
                }  
            }
            in_file.close();
            display_words(words);
        } else {
            std::cerr << "Error opening input file" << std::endl;
        }
    }

    int main() {
        part1();
        part2();
        return 0;
    }

*/



/* 24) container adapter - stack

    std::stack
    - last in first out data structure
    - implemented as an adapter over other stl container
        can be implemented as a vector, list, or deque
    - all operations occur on one end of the stack(top)
    - no iterators are supported


    std::stack
    #include <stack>
    - push - insert an element at the top of the stack
    - pop - remove an element from the top of the stack
    - top - access the top element of the stack
    - empty - is the stack empty
    - size - number of elements in the stack

    // Section 20
    // Stack
    #include <iostream>
    #include <stack>
    #include <vector>
    #include <list>

    // This function displays a stack of 
    // by repeatedly topping and popping the stack
    // Note theat the stack is passed in by value so we
    // don't affect the passed in stack.

    template <typename T>
    void display(std::stack<T> s) {
        std::cout << "[ ";
        while (!s.empty()) {
            T elem = s.top();
            s.pop();
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }

    int main() {
        std::stack<int> s;
        std::stack<int, std::vector<int>> s1;
        std::stack<int, std::list<int>> s2;
        std::stack<int, std::deque<int>> s3;
        
        for (int i: {1,2,3,4,5}) 
            s.push(i);
        display(s);

        s.push(100);
        display(s);
        
        s.pop();
        s.pop();
        display(s);
        
        while (!s.empty())
            s.pop();
        display(s);
        
        std::cout << "Size: " << s.size() << std::endl;
        
        s.push(10);
        display(s);
        
        s.top() = 100;
        display(s);
        return 0;
    }


*/




/* 25) container adapter - queue 

    std::queue
    - first in first out data structure
    - implemented as an adapter over other stl container
        can be implemented as a list or deque
    - elements are pushed at the back and popped from the front
    - no iterators are supported


    std::queue
    #include <queue>

    - push - insert an element at the back of the queue
    - pop - remove an element from the front of the queue
    - front- access the element at the front
    - back - access the element at the back 
    - empty - is the queue empty?
    - size - number of elements in the queue

    // Section 20
    // Queue
    #include <iostream>
    #include <queue>

    // This function displays a queue of 
    // by repeatedly removing elements from the front
    // Note theat the queue is passed in by value so we
    // don't affect the passed in queue.

    template <typename T>
    void display(std::queue<T> q) {
        std::cout << "[ ";
        while (!q.empty()) {
            T elem = q.front();
            q.pop();
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }

    int main() {
        std::queue<int> q;
        
        for (int i: {1,2,3,4,5}) 
            q.push(i);
        display(q);
        std::cout << "Front: " << q.front() << std::endl;
        std::cout << "Back:  " << q.back() << std::endl;

        q.push(100);
        display(q);

        q.pop();
        q.pop();
        display(q);
        
        while (!q.empty())
            q.pop();
        display(q);

        std::cout << "Size: " << q.size() << std::endl;
        
        q.push(10);
        q.push(100);
        q.push(1000);
        display(q);
        
        std::cout << "Front: " << q.front() << std::endl;
        std::cout << "Back:  " << q.back() << std::endl;
        
        q.front() = 5;
        q.back() = 5000;
        
        display(q);
        std::cout << "Front: " << q.front() << std::endl;
        std::cout << "Back:  " << q.back() << std::endl;
        
        return 0;
    }


*/



/* 27) section challenge 4 


// Section 20
// Challenge 4 - Solution
// Determine if a string is a palindrome
// Use a queue and a stack to solve the problem

#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    std::stack<char> stk;
    std::queue<char> q;

    // add all the string characters that are alpha to the back of the queue  in uppercase
    // push all the string characters that are alpha on the stack
    
    for(char c : s)
        if(std::isalpha(c)) {
            c = std::toupper(c);
            q.push(c);
            stk.push(c);
        }

    char c1{};
    char c2{};    
    
    // while the queue is not empty
    //      compare and remove the character at the top of the stack 
    //      and the chacterter at the front of the queue
    //      if they are not the same - return false since it can't be a palindrome
    // if you complete the loop then the string must be a palindrome so return true
    while(!q.empty()) {
        c1 = q.front();
        q.pop();
        c2 = stk.top();
        stk.pop();
        if(c1 != c2)
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
    
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}


*/



/* 28) container adapters - priority queues 

    std::priority_queue
    - allows insertion and removal of elements in order from the from of the container
    - elements are stored internally as a vector by default
    - elements are inserted in priority order(largest value will always be at the front)
    - no iterators are supported

    #include <queue>
    - push - insert an element into sorted order
    - pop - removes the top element(greatest)
    - top - access the top element
    - element - is the queue empty
    - size - number of elements in the queue

    // Section 20
    // Priority Queue
    #include <iostream>
    #include <queue>

    class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    public:
        Person() : name{"Unknown"}, age{0} {}
        Person(std::string name, int age) 
            : name{name}, age{age}  {}
        bool operator<(const Person &rhs) const {
            // return this->age < rhs.age;
            return this->name < rhs.name;
        }
        bool operator==(const Person &rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }
    };

    std::ostream &operator<<(std::ostream &os, const Person &p) {
        os << p.name << ":" << p.age;
        return os;
    }
    // This displays the priority queue by
    // repeatedly topping and popping the priority queue
    // It is being passed by value so we don't modify the 
    // priority queue being passed in

    template <typename T>
    void display(std::priority_queue<T> pq)  {
        std::cout << "[ ";
        while (!pq.empty()) {
            T elem = pq.top();
            pq.pop();
            std::cout << elem << " ";
        }
        std::cout <<  "]" << std::endl;
    }

    void  test1() {
        std::cout << "\nTest1 =========================" << std::endl;

        std::priority_queue<int> pq;
        for (int i : {3,5,7,12,23,12,4,100,0, 3,5,7})
            pq.push(i);
            
        std::cout << "Size: " << pq.size() << std::endl;
        std::cout << "Top: " << pq.top() << std::endl;
            
        display(pq);
        
        pq.pop();
        display(pq);
    }

    void test2() {
        std::cout << "\nTest2 =========================" << std::endl;

        std::priority_queue<Person> pq;
        pq.push(Person{"A", 10});
        pq.push(Person{"B", 1});
        pq.push(Person{"C", 14});
        pq.push(Person{"D", 18});  
        pq.push(Person{"E", 7});  
        pq.push(Person{"F", 27});
        
        display(pq);
    }

    int main() {
        test1();
        test2();
        return 0;
    }





*/

