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

    std::cout << std::showpos; // default - std::noshowpos
    std::cout << num1; // +255



*/



/* 6) stream manipulators - floating point 

    formatting floating point types
    - default when displaying floating point values is:
        - setprecision - number of digits displayed (6)
        - fixed - not fixed to a specific number of digits after the decimal point
        - noshowpoint - trailing zeroes are not displayed
        - nouppercase - when displaying in scientific notation
        - noshowpos - no + is displayed for positive numbers

    - these manipulators affect all further output to the stream

    // Section 19
    // Stream manipulators - Floating point manipulators
    // scientific, setprecision, fixed, showpoint, showpos, uppercase
    #include <iostream>
    #include <iomanip>

    int main() {
        double num1 {123456789.987654321};
        double num2 {1234.5678};                     
        double num3 {1234.0};                          
    
        //using default settings
        std::cout << "--Defaults ----------------------------" << std::endl;
        std::cout << num1 << std::endl;	 // 1.23457e+008
        std::cout << num2<< std::endl;	// 1234.57
        std::cout << num3<< std::endl;	// 1234
        
        //Note how since we can't display in precision 2 scientific notation is used
        std::cout << std::setprecision(2);
        std::cout << "--Precision 2----------------------------" << std::endl;
        std::cout << num1 << std::endl;	 // 1.2e+008
        std::cout << num2<< std::endl;	 // 1.2e+003
        std::cout << num3<< std::endl;	 // 1.2e+003
        
        // Using precision 5
        std::cout << std::setprecision(5);
        std::cout << "--Precision 5----------------------------" << std::endl;
        std::cout << num1 << std::endl;	// 1.2345e+008
        std::cout << num2<< std::endl;	// 1234.6
        std::cout << num3<< std::endl;	//1234

        // Using precision 9
        std::cout << std::setprecision(9);
        std::cout << "--Precision 9----------------------------" << std::endl;
        std::cout << num1 << std::endl;	// 123456790
        std::cout << num2<< std::endl;	// 1234.568
        std::cout << num3<< std::endl;	// 1234

        // Using precision 3 and fixed
        std::cout << std::setprecision(3) << std::fixed;
        std::cout << "--Precision 3 - fixed ----------------------------" << std::endl;
        std::cout << num1 << std::endl;	// 123456789.988
        std::cout << num2<< std::endl;	// 1234.568
        std::cout << num3<< std::endl;	// 1234.000
        
        // Using precision  3, fixed and scientific notation
        // Note precision is after the decimal
        std::cout << std::setprecision(3)<< std::scientific;
        std::cout << "--Precision 3 - scientific  ----------------------------" << std::endl;
        std::cout << num1 << std::endl;	
        std::cout << num2<< std::endl;	
        std::cout << num3<< std::endl;	
        
        // Same but display capital 'E' in scientific 
        std::cout << std::setprecision(3) << std::scientific << std::uppercase;
        std::cout << "--Precision 3 - scientific - uppercase  ----------------------------" << std::endl;
        std::cout << num1 << std::endl;	
        std::cout << num2<< std::endl;	
        std::cout << num3<< std::endl;	
        
        // Show '+' symbol for positive numbers
        std::cout << std::setprecision(3) << std::fixed << std::showpos;
        std::cout << "--Precision 3 - fixed - showpos ----------------------------" << std::endl;
        std::cout << num1 << std::endl;	
        std::cout << num2<< std::endl;	
        std::cout << num3<< std::endl;	
        
        
        // Back to defaults
        std::cout.unsetf(std::ios::scientific | std::ios::fixed);
        std::cout << std::resetiosflags(std::ios::showpos);
        
        // Show trailing zeroes up to precision 10
        
        std::cout << std::setprecision(10) << std::showpoint;
        std::cout << "-- precision 10 - showpoint ----------------------------" << std::endl;
        std::cout << num1 << std::endl;	
        std::cout << num2<< std::endl;	
        std::cout << num3<< std::endl;	

    // Back to defaults
        std::cout.unsetf(std::ios::scientific | std::ios::fixed);
        std::cout << std::setprecision(6);
        std::cout << std::resetiosflags(std::ios::showpos);
        std::cout << std::resetiosflags(std::ios::showpoint);

        std::cout << "--Back to defaults----------------------------" << std::endl;
        std::cout << num1 << std::endl;	
        std::cout << num2<< std::endl;	
        std::cout << num3<< std::endl;	
        
        return 0;
    }


*/



/* 7) stream manipulators align and fill 

    - field width, align and fill

    - default when displaying floating point values is
        - setw - not set by default
        - left - when no field width, right- when using field width
        - fill - not set by default - blank space is used

    - some of these manipulators affect only the next data element put on the stream

    // Section 19
    // Stream manipulators - Field width, justification and setfill
    // setw, left, right, setfill
    #include <iostream>
    #include <iomanip>

    void ruler() {
        std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
    }

    int main() {
        int num1 { 1234 };
        double num2 {1234.5678};
        std::string hello  {"Hello"};
        
        // Defaults
        std::cout << "\n--Defaults -------------------------------------------------------------------" << std::endl;
        ruler();
        std::cout << num1 
                    << num2 
                    << hello 
                    << std::endl;
        
        // Defaults - one per line
        std::cout << "\n--Defaults - one per line-----------------------------------------------------" << std::endl;
        ruler();
        std::cout << num1 <<std::endl;
        std::cout << num2 << std::endl;
        std::cout << hello << std::endl;
        
    // Set field width to 10 
    // Note the default justification is right for num1 only!
        std::cout << "\n--width 10 for num1-----------------------------------------------------------" << std::endl;
        ruler(); 
        std::cout << std::setw(10)  << num1 
                    << num2          
                    << hello 
                    << std::endl;
        
        // Set field width to 10 for the first 2 outputs
    // Note the default justification is right for both
        std::cout << "\n--width 10 for num1 and num2------------------------------------------------" << std::endl;
        ruler(); 
        std::cout << std::setw(10) << num1 
                    << std::setw(10) << num2  
                    << hello 
                    << std::endl;
                    
    // Set field width to 10 for all 3 outputs
    // Note the default justification is right for all
        std::cout << "\n--width 10 for num1 and num2 and hello--------------------------------------" << std::endl;
        ruler(); 
        std::cout << std::setw(10) << num1 
                    << std::setw(10) << num2  
                    << std::setw(10) << hello 
                    << std::endl;
                    
        // Set field width to 10 for all 3 outputs and justify all left
        std::cout << "\n--width 10 for num1 and num2 and hello left for all---------------------------" << std::endl;
        ruler(); 
        std::cout << std::setw(10) << std::left << num1 
                    << std::setw(10) << std::left << num2  
                    << std::setw(10) << std::left <<  hello 
                    << std::endl;
                    
        // setfill to a dash
        // this is persistent
        // Then repeat the previous display
        std::cout << std::setfill('-');
        std::cout << "\n--width 10 for num1 and num2 and hello left for all setfill to dash------------" << std::endl;
        ruler(); 
        std::cout << std::setw(10) << std::left << num1 
                    << std::setw(10) << std::left << num2  
                    << std::setw(10) << std::left <<  hello 
                    << std::endl;
    //    
        // Set width to 10 for all, left justify all and cary the setfill character
        std::cout << "\n--width 10 for num1 and num2 and hello - setfill varies------------------------" << std::endl;
        ruler(); 
        std::cout << std::setw(10) << std::left << std::setfill('*') << num1 
                    << std::setw(10) << std::left << std::setfill('#' )<< num2  
                    << std::setw(10) << std::left <<  std::setfill('-') << hello 
                    << std::endl;
    //    
        std::cout << std::endl << std::endl;
        return 0;
    }

*/



