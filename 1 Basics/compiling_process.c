/* 
    Written By: Dhinesh Viper
    Date: 27-01-2020
 */


/* How c program is getting compiled
    Important things to remember:

    “.h” files contain only Prototype declarations (such as Functions, Structures) and global variables.
    “.c/.cpp” files contain the real implementation (Definitions of declaration in the header files)
    When compiling all the source files together, make sure there are no multiple definitions of a same functions, variable etc. for the same project. (VERY IMPORTANT)
    Use static functions to restrict to the file where they are declared.
    Use extern keyword to use variable(s) that reference external files.
    If using C++, be careful about namespaces always use namespace_name::function() to avoid collision.

    > gcc -Wall hello.c -o hello
    
    -Wall enables all compiler's warning messages. This option is recommended
    to generate better code. 

    > ./hello

    Compilation process
    -------------------
    1) preprocessing
    2) compilation
    3) Assembly
    4) Linking

    gcc -Wall --save-temps hello.c -o hello

    Preprocessing
    -------------
    This is the first phase through which source code is passed. 
    This phase include
        - Removal of comments
        - Expansion of macros
        - Expansion of Included File
        - conditional compilation

    The preprocessed output is stored in the hello.i 
    
    Compiling
    ---------
    The next step is to compile hello.i and produce an intermediate
    compiled output file hello.s 
    This file is in assembly level instructions which assembler can understand

    Assembly
    --------
    In this phase, the hello.s is taken as input and turned into hello.o
    by assembler. This file contain machine level instructions. At this phase, only
    existing code is converted into machine language. The functions calls like 
    printf() are not resolved. 

    Linking
    ---------
    This is the final phase in which all the linking of function calls with their
    definitions are done. Linker knows where all these functions are implemented. 
    Linker does some extra work also. It adds some extra code to our program which 
    is required for setting up the environment like passing command line arguments. 
    

 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main(int argc, char** argv){   
    
    printf("Hello world! %d",argc);    
    
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
        
    /*
    CHAR_MAX    :   127
    CHAR_MIN    :   -128
    INT_MAX     :   2147483647
    INT_MIN     :   -2147483648
    LONG_MAX    :   9223372036854775807
    LONG_MIN    :   -9223372036854775808
    SCHAR_MAX   :   127
    SCHAR_MIN   :   -128
    SHRT_MAX    :   32767
    SHRT_MIN    :   -32768
    UCHAR_MAX   :   255
    UINT_MAX    :   4294967295
    ULONG_MAX   :   18446744073709551615
    USHRT_MAX   :   65535 
    
    char	            1 byte	-128 to 127 or 0 to 255
    unsigned char	    1 byte	0 to 255
    signed char	        1 byte	-128 to 127
    int	                2 or 4 bytes	-32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
    unsigned int	    2 or 4 bytes	0 to 65,535 or 0 to 4,294,967,295
    short	            2 bytes	-32,768 to 32,767
    unsigned short	    2 bytes	0 to 65,535
    long	            8 bytes	-9223372036854775808 to 9223372036854775807
    unsigned long	    8 bytes	0 to 18446744073709551615

    */

    // printf("Storage size for float : %d \n", sizeof(float));
    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN); 
    printf("-FLT_MAX    :   %g\n", (float) -FLT_MAX);
    printf("-FLT_MIN    :   %g\n", (float) -FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
    printf("Precision value: %d\n", FLT_DIG );

    /* 
    3.4x10^38

    Storage size for float : 4 
    FLT_MAX      :   3.40282e+38
    FLT_MIN      :   1.17549e-38
    -FLT_MAX     :   -3.40282e+38
    -FLT_MIN     :   -1.17549e-38
    DBL_MAX      :   1.79769e+308
    DBL_MIN      :   2.22507e-308
    -DBL_MAX     :  -1.79769e+308
    Precision value: 6 
    
    
    float	        4 byte	    1.2E-38 to 3.4E+38	    6 decimal places
    double	        8 byte	    2.3E-308 to 1.7E+308	15 decimal places
    long double	    10 byte	    3.4E-4932 to 1.1E+4932	19 decimal places
    */

    return 0;            

}  /* end of main function */