/* 1) overview

    - streams and IO
    - stream manipulator
    - reading and writingto a text file
    - using string streams


 */

/* 2) files streams and IO

    - c++ uses streams as an interface between the program and input and output devices
    - independent of the actual device
    - sequence of bytes
    - input stream provides data to the program
    - output stream receives data from the program

    header file
    ------------
    iostream - provides definitions for formatted input and output from/to streams
    fstream - provides definitions for formatted input and output from/to file streams
    iomanip - provides definitions for manipulators used to format stream I/O

    commonly used stream class
    ----------------------------
    - ios - provides basic support for formatted and unformatted I/O operations. Base class most other classes
    - ifstream - provides for high level input operations on file based streams
    - ofstream - provides for high level output operations on file based streams
    - fstream - provides for highlevel I/O operations on file based streams. Derived from ofstream and ifstream
    - stringstream - provides for high level I/O operations on memory based strings. Derived from istringstream and ostringstream

    global stream objects
    ---------------------
    cin - standard input stream - by default 'connected' to the standard input device (keyboard). Instance of istream
    cout - standard output stream - by default 'connected' to the standard output device(console) - instance of ostream
    cerr - stanard error stream - by default 'connected' to the standard error device (console) - instance of ostream(unbuffered)
    clog - standard log stream - by default 'connected' to the standard log device (console) - instance of ostream (unbuffered)

    - global objects - initialized before main executes
    - best practice is to use cerr for error messages and clog for log messages
*/


/* 3) stream manipulators 

    - streams have useful member functions to control formatting
    - can be used on input and output streams
    - the time of the effect on the stream values
    - can be used as member functions or as manipulator
        std::cout.width(10); // member function
        std::cout << std::setw(10); // manipulator

        we'll focus on manipulator usage


    common stream manipulators
    --------------------------
    - Boolean 
        - boolalpha, noboolalpha
    - Integer
        - dec, hex, oct, showbase, noshowbase, showpos, noshowpos, uppercase, nouppercase
    - floating point
        - fixed, scientific, setprecision, showpoint, noshowpoint, showpos, noshowpos
    - Field width, justification and fill
        - setw, left, right, internal, setfill
    - others
        - endl, flush, skipws, noskipws, ws

*/


/* 4) stream manipulator - boolean 

    - default when displaying boolean values is 1 or 0
    - sometimes the strings true or false are more appropriate


    std::cout << std::boolalpha; 
    std::cout << (10 == 10); // true
    std::cout << (10 == 20); // false

    All further boolean output will be affected
    ------------------------------------------------
    cout << noboolalpha; // 1 or 0
    cout << boolalpha; // true or false


    Formatting boolean types
    -----------------------
    - method version
        std::cout.setf(std::ios::boolalpha);
        std::cout.setf(std::ios::noboolalpha);

    - reset to default
        std::cout << std::resetiosflags(std::ios::boolalpha);      

    // Section 19
    // Stream manipulators - Boolean
    // boolalpha and noboolalpha

    #include <iostream>
    #include <iomanip>  // Must include for manipulators

    int main() {
    
        std::cout << "noboolalpha - default  (10 == 10) : " << (10 == 10)  << std::endl;
        std::cout << "noboolalpha - default  (10 == 20) : " << (10 == 20)  << std::endl;
        
        // Set to true/false formatting
        std::cout << std::boolalpha;    // change to true/false
        std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
        std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
        
        // setting still stays for future boolean insertions
        std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
        std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
        
        // Toggle to 0/1
        std::cout << std::noboolalpha;
        std::cout << "noboolalpha  (10 == 10) : " << (10 == 10)  << std::endl;
        std::cout << "noboolalpha  (10 == 20) : " << (10 == 20)  << std::endl;
        
        // Set back to true/false using setf method
        std::cout.setf(std::ios::boolalpha);
        std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
        std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
        
        // resets to default which is 0/1
        std::cout << std::resetiosflags(std::ios::boolalpha);
        std::cout << "Default  (10 == 10) : " << (10 == 10)  << std::endl;
        std::cout << "Default  (10 == 20) : " << (10 == 20)  << std::endl;
        return 0;
    }

*/


/* 5) stream manipulator - integers 

    formatting integer types
    - default when displaying integer values is:
        - dec(base 10)
        - noshowbase - prefix used to show hexadecimal or octal
        - nouppercase - when displaying a prefix and hex values it will be lower case
        - noshowpos - no'+' is displayed for positive numbers

    - these manipulators affect all further output to the stream


    int num {255};

    std::cout << std::dec << num << endl;   // 255 
    std::cout << std::hex << num << endl;   // ff
    std::cout << std::oct << num << endl;   // 277



    int num {255};

    std::cout << std::showbase; // std::noshowbase - default

    std::cout << std::dec << num << endl;   // 255 
    std::cout << std::hex << num << endl;   // 0xff = note the 0x prefix for hexadecimal
    std::cout << std::oct << num << endl;   // 0277 = note the 0 prefix for octal


    int num {255};

    std::cout << std::showbase; << std::uppercase; 
    
    std::cout << std::hex << num << endl;   // 0XFF = note the 0x prefix for hexadecimal

*/