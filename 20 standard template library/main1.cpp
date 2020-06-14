/* 13) vectors 

    #include <vector>

    - dynamic size
        - handled automatically
        - can expand and contract as needed
        - elements are stored in contiguous memory as needed

    - direct element access(constant time)
    - rapid insertion and deletion at back(constant time)
    - insertion or removal of elements(linear time)
    - all iterators available and may invalidate
    
    // Section 20
    // Vector

    #include <iostream>
    #include <vector>
    #include <algorithm>

    class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    public:
        Person() = default;
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

    // Use for_each and a lambda expression to display vector elements
    void display2(const std::vector<int> &vec) {
        std::cout << "[ ";
        std::for_each(vec.begin(), vec.end(),
            [](int x) { std::cout << x << " ";});
        std::cout << "]" << std::endl;
    }

    // template function to display any vector
    template <typename T>
    void display(const std::vector<T> &vec) {
        std::cout << "[ ";
        for (const auto &elem: vec)
            std::cout << elem << " ";
        std::cout <<  "]"<< std::endl;
    }


    void test1() {
        std::cout << "\nTest1 =========================" << std::endl;

        std::vector<int> vec {1,2,3,4,5};
        display(vec);
        
        vec = {2,4,5,6};
        display2(vec);
        
        std::vector<int> vec1 (10, 100);    // ten 100s in the vector
        display(vec1);
    }

    void test2() {
        std::cout << "\nTest2 =========================" << std::endl;

        std::vector<int> vec {1,2,3,4,5};
        display(vec);
        std::cout << "\nvec size: " << vec.size() << std::endl;
        std::cout << "vec max size: " << vec.max_size() << std::endl;
        std::cout << "vec capacity: " << vec.capacity() << std::endl;
        
        vec.push_back(6);
        display(vec);
        std::cout << "\nvec size: " << vec.size() << std::endl;
        std::cout << "vec max size: " << vec.max_size() << std::endl;
        std::cout << "vec capacity: " << vec.capacity() << std::endl;
        
        vec.shrink_to_fit();    // C++11
        display(vec);
        std::cout << "\nvec size: " << vec.size() << std::endl;
        std::cout << "vec max size: " << vec.max_size() << std::endl;
        std::cout << "vec capacity: " << vec.capacity() << std::endl;
        
        vec.reserve(100);
        display(vec);
        std::cout << "\nvec size: " << vec.size() << std::endl;
        std::cout << "vec max size: " << vec.max_size() << std::endl;
        std::cout << "vec capacity: " << vec.capacity() << std::endl;
        
    }
    void test3() {
        std::cout << "\nTest3 =========================" << std::endl;

        std::vector<int> vec {1,2,3,4,5};
        display(vec);
        
        vec[0] = 100;
        vec.at(1) = 200;
        
        display(vec);
    }

    void test4() {
        std::cout << "\nTest4 =========================" << std::endl;
        std::vector<Person> stooges;
        
        Person p1 {"Larry", 18};
        display(stooges);
        
        stooges.push_back(p1);
        display(stooges);
        
        stooges.push_back(Person{"Moe", 25});
        display(stooges);
        
        stooges.emplace_back("Curly", 30);      // Use emplace_back!!!
        display(stooges);
    }

    void test5() {
        std::cout << "\nTest5 =========================" << std::endl;

        std::vector<Person> stooges {
            {"Larry", 18},
            {"Moe", 25},
            {"Curly", 30}
        };
        
        display(stooges);
        std::cout << "\nFront: " << stooges.front() << std::endl;
        std::cout << "Back: " << stooges.back() << std::endl;
        
        stooges.pop_back();
        display(stooges);
    }

    void test6() {
        std::cout << "\nTest6 =========================" << std::endl;
        std::vector<int> vec {1,2,3,4,5};
        display(vec);
        
        vec.clear();    // remove all elements
        display(vec);
        
        vec = {1,2,3,4,5,6,7,8,9,10};
        display(vec);
        vec.erase(vec.begin(), vec.begin() + 2);
        display(vec);
        
        vec = {1,2,3,4,5,6,7,8,9,10};
        // erase all even numbers
        auto it = vec.begin();
        while (it != vec.end()) {
            if (*it %2 == 0)
                vec.erase(it);  
            else
                it++;   // only increment if not erased!
        }
        display(vec);
    }

    void test7() {
        std::cout << "\nTest7 =========================" << std::endl;
        
        std::vector<int> vec1 {1,2,3,4,5};
        std::vector<int> vec2 {10,20,30,40,50};
        
        display(vec1);
        display(vec2);
        std::cout << std::endl;

        vec2.swap(vec1);
        display(vec1);
        display(vec2);
    }

    void test8() {
        std::cout << "\nTest8  =========================" << std::endl;

        std::vector<int> vec1 {1,21,3,40,12};    
        
        display(vec1);
        std::sort(vec1.begin(), vec1.end());
        display(vec1);
    }

    void test9() {
        // std::back_inserter contructs a back-insert iterator that inserts new elements 
        // at the end of the container it applied to. It's a special output iterator
        // It's awesome!!!!   and  very efficient
        // There is also a front_inserter we can use with deques and lists
        // Copy one list to another using an iterator and back_inserter
        
        std::cout << "\nTest9  =========================" << std::endl;
        
        std::vector<int> vec1 {1,2,3,4,5};   
        std::vector<int> vec2 {10,20};
        
        display(vec1); 
        display(vec2);
        std::cout << std::endl;

        std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
        display(vec1);
        display(vec2);
        std::cout << std::endl;

        
        // Copy_if the element is even
        
        vec1 = {1,2,3,4,5,6,7,8,9,10};
        vec2 = {10,20};
        
        display(vec1);
        display(vec2);
        std::cout << std::endl;
        
        std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
                [](int x) { return x%2 == 0; });
        display(vec1);
        display(vec2);
        
        
    }

    void test10() {
        std::cout << "\nTest10  =========================" << std::endl;
        // transform over 2 ranges
        
        std::vector<int> vec1 {1,2,3,4,5};   
        std::vector<int> vec2 {10,20,30,40,50};
        std::vector<int> vec3;
        
        
        // 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
        std::transform(vec1.begin(), vec1.end(), vec2.begin(),
            std::back_inserter(vec3),
            [](int x, int y) { return x * y;});
            
        display(vec3);
        
    }



    // Insertion from another vector
    // Insert vec2 into vec1 before the 5
    void test11() {
        std::cout << "\nTest11  =========================" << std::endl;
        std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
        std::vector<int> vec2 {100,200,300,400};
        
        display(vec1);
        display(vec2);
        std::cout << std::endl;

        
        auto it = std::find(vec1.begin(), vec1.end(), 5);
        if (it != vec1.end()) {
            std::cout << "inserting..." << std::endl;
            vec1.insert(it, vec2.begin(), vec2.end());
        } else {
            std::cout << "Sorry, 5 not found" << std::endl;
        }
        display(vec1);
    }

    int main()  {    

        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
        test9();
        test10();
        test11();
        
        return 0;
    }

*/



/* 14) sequence container - deque

    std::deque(double ended queue)

    #include <deque>

    - dynamic size 
        - handled automatically
        - can expand and contract as needed
        - elements are not stored in contiguous memory but blocks of contigous memory 
    - direct element access (constant time)
    - rapid insertion and deletion at the front and back (constant time)
    - insertion or removal of elements (linear time) and insertion or 
        deletion at any other position is not as efficient
    - all iterators available and may invalidate

    // Section 20
    // Deque
    #include <iostream>
    #include <deque>
    #include <vector>
    #include <algorithm>

    // template function to display any deque
    template <typename T>
    void display(const std::deque<T> &d) {
        std::cout << "[";
        for (const auto &elem: d)
            std::cout << elem << " ";
        std::cout <<  "]"<< std::endl;
    }

    void test1() {
        std::cout << "\nTest1 =========================" << std::endl;

        std::deque<int> d {1,2,3,4,5};
        display(d);
        
        d = {2,4,5,6};
        display(d);
        
        std::deque<int> d1 (10, 100);    // ten 100s in the deque
        display(d1);
        
        d[0]  = 100;
        d.at(1) = 200;
        display(d);
    }

    void test2() {
        // push and pops
        std::cout << "\nTest2 =========================" << std::endl;

        std::deque<int> d {0,0,0};
        display(d);
        
        d.push_back(10);
        d.push_back(20);
        display(d);
        
        d.push_front(100);
        d.push_front(200);
        display(d);
        
        std::cout << "Front: " << d.front() << std::endl;
        std::cout << "Back : " << d.back() << std::endl;
        std::cout << "Size  : " << d.size() << std::endl;
        
        d.pop_back();
        d.pop_front();
        display(d);
    }

    void test3() {
        // insert all even numbers into the back of a deque and all 
        // odd numbers into the front
        std::cout << "\nTest3 =========================" << std::endl;
        
        std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
        std::deque<int> d;
        
        for (const auto &elem: vec) {
            if (elem % 2 == 0)
                d.push_back(elem);
            else
                d.push_front(elem);
        }
        display(d);
    }

    void test4() {
        // push front vs. back ordering
        std::cout << "\nTest4 =========================" << std::endl;

        std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
        std::deque<int> d;
        
        for (const auto &elem: vec) {
            d.push_front(elem);
        }    
        display(d);
        
        d.clear();
        
        for (const auto &elem: vec) {
            d.push_back(elem);
        }
        display(d);
    }

    void test5() {
        // Same as test4 using std::copy
        std::cout << "\nTest5 =========================" << std::endl;

        std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
        std::deque<int> d;
        
        std::copy(vec.begin(), vec.end(), std::front_inserter(d));
        display(d);
        
        d.clear();
        
        std::copy(vec.begin(), vec.end(), std::back_inserter(d));
        display(d);
    }

    int main() {
        test1();
        test2();
        test3();
        test4();
        test5();
        return 0;
    }
*/



/* 16) section challenge 1 

    // Section 20
    // Challenge 1 - Solution
    // Identifying palindrome strings using a deque
    #include <cctype>
    #include <deque>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iomanip>

    bool is_palindrome(const std::string& s)
    {
        std::deque<char> d;

        // add all the string characters that are alpha to the back of the deque in uppercase
        for(char c : s)
            if(std::isalpha(c))
                d.push_back(std::toupper(c));

        char c1{};
        char c2{};
        // while are more than 1 characters in the deque
        //      remove and compare the front character with the back character
        //      if they are not the same - return false since it can't be a palindrome
        // if you complete the loop then the string must be a palindrome so return true
        while(d.size() > 1) {
            c1 = d.front();
            c2 = d.back();
            d.pop_front();
            d.pop_back();
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



/* 17) sequence container - list and forward list 

    std::list and std::forward_list

    - sequence containers
    - non contiguous in memory
    - no direct access to elements
    - very efficient for inserting and deleting elements once an element is found

    #include <list>
        - dynamic size
            - list of elements
            - list is bidirectional - doubly linked
        - direct element access is not provided
        - rapid insertion and deletion of elements anywhere in the container(constant time)
        - all iterators available and invalidate when corresponding element is deleted


    #include <forward_list>
        - dynamic size
            - lists of elements
            - list unidirectional (singly linked)
            - less overhead than std::list
        - direct element access is not provided
        - rapid insertion and deletion of elements anywhere in the container(constant time)
        - reverse iterators not available. Iterators invalidate when corresponding element is deleted


    // Section 20
    // List
    #include <iostream>
    #include <list>
    #include <algorithm>
    #include <iterator> // for std::advance

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
    void display(const std::list<T> &l) {
        std::cout << "[ ";
        for (const auto &elem: l) {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }

    void test1() {
        std::cout << "\nTest1 =========================" << std::endl;

        std::list<int> l1 {1,2,3,4,5};
        display(l1);
        
        std::list<std::string> l2;
        l2.push_back("Back");
        l2.push_front("Front");
        display(l2);
        
        std::list<int> l3;
        l3 = {1,2,3,4,5,6,7,8,9,10};
        display(l3);
        
        std::list<int> l4 (10, 100);
        display(l4);
    }

    void test2() {
        std::cout << "\nTest2 =========================" << std::endl;

        std::list<int> l {1,2,3,4,5,6,7,8,9,10};
        display(l);
        std::cout << "Size: " << l.size() << std::endl;
        
        std::cout << "Front : " << l.front() << std::endl;
        std::cout << "Back  : " << l.back() << std::endl;
        
        l.clear();
        display(l);
        std::cout << "Size: " << l.size() << std::endl;
    }

    void test3() {
        std::cout << "\nTest3 =========================" << std::endl;

        std::list<int> l {1,2,3,4,5,6,7,8,9,10};
        display(l);
        
        l.resize(5);
        display(l);
        
        l.resize(10);
        display(l);
        
        std::list<Person> persons;
        persons.resize(5);             // uses the Person default constructor
        display(persons);
        
    }
    void test4() {
        std::cout << "\nTest4 =========================" << std::endl;

        std::list<int> l {1,2,3,4,5,6,7,8,9,10};
        display(l);
        auto it = std::find(l.begin(), l.end(), 5);
        if (it != l.end()) {
            l.insert(it, 100);
        }
        display(l);
        
        std::list<int> l2 {1000,2000,3000};
        l.insert(it, l2.begin(), l2.end());
        display(l);
        
        std::advance(it, -4);       // point to the 100
        std::cout << *it << std::endl;
        
        l.erase(it);                    // remove the 100 - iterator becomes invalid
        display(l);
        
    }

    void test5() {
        std::cout << "\nTest5 =========================" << std::endl;

        std::list<Person>  stooges {
            {"Larry", 18},
            {"Moe", 25},
            {"Curly", 17}
        };
        
        display(stooges);
        std::string name;
        int age{};
        std::cout << "\nEnter the name of the next stooge: ";
        getline(std::cin, name);
        std::cout << "Enter their age: ";
        std::cin >> age;
        
        stooges.emplace_back(name, age);
        display(stooges);
        
        // Insert Frank before Moe
        auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
        if (it != stooges.end())
            stooges.emplace(it, "Frank", 18);
        display(stooges);    
    }

    void test6() {
        std::cout << "\nTest6 =========================" << std::endl;
        
        std::list<Person>  stooges {
            {"Larry", 18},
            {"Moe", 25},
            {"Curly", 17}
        };
        
        display(stooges);
        stooges.sort();
        display(stooges);
    }


    int main() {
        
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        std::cout << std::endl;
        return 0;
    }

*/


/* section challenge 2 

    // Section 20
    // Challenge 2 - Solution
    //  Lists

    #include <iostream>
    #include <list>
    #include <string>
    #include <cctype>
    #include <iomanip>
    #include <limits>

    class Song {
        friend std::ostream &operator<<(std::ostream &os, const Song &s);

        std::string name;
        std::string artist;
        int rating;
    public:
        Song() = default;
        Song(std::string name, std::string artist, int rating)
                : name{name}, artist{artist}, rating{rating} {}

        std::string get_name() const {
            return name;
        }

        std::string get_artist() const {
            return artist;
        }
        
        int get_rating() const {
            return rating;
        }
        
        bool operator<(const Song &rhs) const  {
            return this->name < rhs.name;
        }
        
        bool operator==(const Song &rhs) const  {
            return this->name == rhs.name;
        }
    };

    std::ostream &operator<<(std::ostream &os, const Song &s) {
        os << std::setw(20) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;
        return os;
    }

    void display_menu() {
        std::cout << "\nF - Play First Song" << std::endl;
        std::cout << "N - Play Next song" << std::endl;
        std::cout << "P - Play Previous song" << std::endl;
        std::cout << "A - Add and play a new Song at current location" << std::endl;
        std::cout << "L - List the current playlist" << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cout << "Enter a selection (Q to quit): ";
    }

    void play_current_song(const Song &song) {
        std::cout << "Playing: " << std::endl;
        std::cout << song << std::endl;
    }

    void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
        for (const Song &song: playlist) {
            std::cout << song << std::endl;
        }
        std::cout << "Current song: " << std::endl;
        std::cout << current_song << std::endl;
    }

    int main() {

        std::list<Song> playlist{
                {"God's Plan",        "Drake",                     5},
                {"Never Be The Same", "Camila Cabello",            5},
                {"Pray For Me",       "The Weekend and K. Lamar",  4},
                {"The Middle",        "Zedd, Maren Morris & Grey", 5},
                {"Wait",              "Maroone 5",                 4},
                {"Whatever It Takes", "Imagine Dragons",           3}          
        };

        std::list<Song>::iterator current_song = playlist.begin();
        display_playlist(playlist, *current_song);
        
        char selection{};
        do {
            display_menu();
            std::cin >> selection;
            selection = std::toupper(selection);
            if (selection == 'F') {
                std::cout << "Playing first song" << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
            }
            else if (selection == 'N') {
                std::cout << "Playing next song" << std::endl;
                current_song++;
                if (current_song == playlist.end()) {
                    std::cout << "Wrapping to start of playlist" << std::endl;
                    current_song = playlist.begin();
                }
                play_current_song(*current_song);
            }
            else if (selection == 'P') {
                std::cout << "Playing previous song" << std::endl;
                if (current_song == playlist.begin()) {
                    std::cout << "Wrapping to end of playlist" << std::endl;
                    current_song = playlist.end();
                }
                current_song--;
                play_current_song(*current_song);
            } else if (selection == 'A') {
                std::string name, artist;
                int rating;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Adding and playing new song" << std::endl;
                std::cout << "Enter song name:";
                getline(std::cin, name);
                std::cout << "Enter song artist: ";
                getline(std::cin, artist);
                std::cout << "Enter your rating (1-5): ";
                std::cin >> rating;
                playlist.insert(current_song, Song{name, artist, rating});
                current_song--;
                play_current_song(*current_song);
            } else if (selection == 'L') {
                std::cout << std::endl;
                display_playlist(playlist, *current_song);            
            } else if (selection == 'Q')
                std::cout << "Quitting" << std::endl;
            else
                std::cout << "Illegal choice, try again...";
        } while (selection != 'Q');

        std::cout << "Thanks for listening!" << std::endl;
        return 0;
    }

*/









