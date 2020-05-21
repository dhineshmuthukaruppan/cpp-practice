/* 6) c++ strings

    std::string is a class in the STL
    - #include <string>
    - std namespace
    - contiguous in memory
    - dynamic size
    - work with input and output streams
    - lots of useful member functions
    - our familiar operations can be used (+, =, <, <=, >, >=, +=, ==, !=, []...)
    - can be easily converted to cstyle string if needed
    - safer


    #include <string>

    using namespace std;  
    
    string s1; // empty unlike c style string it will not be garbage
    string s2 {"frank"}; // frank is a cstyle literal
    string s3 {s2}; // frank
    string s4 {"frank", 3}; //fra
    string s5 {s3, 0, 2}; // fr - starting integer and length as parameter
    string s6(3, 'X'); // XXX


    assignment
    ----------
        string s1; 
        s1="c++ rocks"; 

        string s2 {"hello"}; 
        s2=s1;  // in this case s2 will no longer contain hello and it will contain a copy of s1 "c++ rocks"

    concatenation
    ------------
        string part1 {"c++"};
        string part2 {" is a powerful"};
        string sentence; 
        sentence = part1 + "" + part2 + " language"; // c++ is a powerful language

        sentence="c++" + " is powerful"; //illegal - because you can't concatenate cstyle literals and a combination of c++ strings and 
                                        // cstyle strings is ok though


    Accessing characters [] and at() method
    --------------------------------------
        strings s1; 
        string s2 {"frank"}

        cout << s2[0]; // f
        cout << s2.at(0); // f
        
        s2[0] = 'F'; // Frank
        s2.at(0) = 'P'; // Prank

        for(char c: s1){
            cout << c << endl; 
        }
        P
        r
        a
        n
        k

        for(int c: s1){
            cout << c << endl; 
        }
        70 114 97 110 107 0


    comparison
    ----------
    ==  != > >= < <=
    - the objects are compared character by character lexically
    - can compare
        - two std::string objects
        - std::string object and c-style string literal
        - std::string object and c-style string variable


        string s1 {"Apple"}; 
        string s2 {"Banana"}; 
        string s3 {"Kiwi"}; 
        strign s4 {"apple"}; 
        string s5 {s1}; 

        s1 == s5 // true
        s1 == s2 // false
        s1 != s2 // true
        s1 < s2 // true
        s2 > s1 // true
        s4 < s5 // false
        s1 == "Apple" // true


    substrings- substr()
    --------------------
    - extracts a substring from std::string

        object.substr(start_index, length);

        string s1 {"This is a test"}
        cout << s1.substr(0, 4); // This
        cout << s1.substr(5, 2); // is
        cout << s1.substr(10, 4); // test 


    substrings- find()
    - returns the index of a substring in a std::string

        object.find(search_string)

        string s1 {"this is a test"}

        s1.find("this"); // 0
        s1.find("is"); // 2
        s1.find("test"); // 10
        s1.find('e'); // 11
        s1.find("is", 4); // 5 - "is" substring startig from index 4
        s1.find('XX'); // string::npos 


    removing characters - erase() and clear()
    ------------------------------------------
    - removes a substrign of characters from std::string

        object.erase(start_index, length);

        string s1 {"this is a test"}; 
        s1.erase(0,5); // is a test
        s1.erase(5,4); // is a 
        s1.clear(); // empty string
        

    other useful method
    ------------------
    string s1 {"frank"}; 
    s1.length(); // 5

    s1+="james";
    cout << s1; // frank james


    input >> and getline()
    ----------------------
    - reading std::string from cin

        string s1; 
        cin >> s1; // hello there
                    // only acceprs up to the first space
        cout << s1; // hello

        getline(cin, s1); // read entire line until \n
        cout << s1; // hello there

        getline(cin, s1, 'x'); // this isx
        cout << s1; // this is


*/