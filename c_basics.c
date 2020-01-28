
/* 
    VARIABLE DECLARATION AND DEFINITION
    ----------------------------------
    - A variable definition tells the compiler where and how much storage to create for the variable
    
    - Declaration of a variable is for informing to the compiler the following information: name of the 
    variable, type of value it holds and the initial value if any it takes. i.e., declaration gives details 
    about the properties of a variable. Whereas, Definition of a variable says where the variable gets stored. i.e., 
    memory for the variable is allocated during the definition of the variable.
    
    - In C language definition and declaration for a variable takes place at the same time. i.e. there is no difference 
    between declaration and definition. For example, consider the following declaration
    
    $int a;

    - Here, the information such as the variable name: a, and data type: int, which is sent to the compiler which will be 
    stored in the data structure known as symbol table. Along with this, a memory of size 2 bytes(depending upon the type of compiler) 
    will be allocated. 

    - Suppose, if we want to only declare variables and not to define it i.e. we do not want to allocate memory, 
    then the following declaration can be used

    extern int a;

    - In this example, only the information about the variable is sent and no memory allocation is done. 
    The above information tells the compiler that the variable a is declared now while memory for it will 
    be defined later in the same file or in different file.

    - Declaration of a function provides the compiler the name of the function, the number and 
    type of arguments it takes and its return type. For example, consider the following code,

    int add(int, int);

    - Here, a function named add is declared with 2 arguments of type int and 
    return type int. Memory will not be allocated at this stage.

    - Definition of the function is used for allocating memory for the function. For example 
    consider the following function definition,

    int add(int a, int b)
    {
        return (a+b);
    }

    - During this function definition, the memory for the function add will be allocated. A variable or a 
    function can be declared any number of times but, it can be defined only once.

    - A variable declaration provides assurance to the compiler that there exists a variable with 
    the given type and name so that the compiler can proceed for further compilation without requiring 
    the complete detail about the variable. A variable definition has its meaning at the time of compilation 
    only, the compiler needs actual variable definition at the time of linking the program.

    - A variable declaration is useful when you are using multiple files and you define your variable 
    in one of the files which will be available at the time of linking of the program. You will use the 
    keyword extern to declare a variable at any place. Though you can declare a variable multiple times 
    in your C program, it can be defined only once in a file, a function, or a block of code.

    STORAGE CLASSES
    ---------------
    A storage class defines the scope (visibility) and life-time of variables and/or functions 
    within a C Program. They precede the type that they modify. We have four different storage classes in a C program −
    - auto, register, static, extern

        auto
        ----
        default storage class for all local variables
        {
        int mount;
        auto int month;
        }   
        The example above defines two variables within same storage class 'auto' 
        can only be used within functions local variables.

        REGISTER
        --------
        The register storage class is used to define local variables that should be stored 
        in a register instead of RAM. This means that the variable has a maximum size equal to the 
        register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).
        {
        register int  miles;
        }
        The register should only be used for variables that require quick access such as 
        counters. It should also be noted that defining 'register' does not mean that the 
        variable will be stored in a register. It means that it MIGHT be stored in a register
        depending on hardware and implementation restrictions.

        STATIC STORAGE CLASS
        ------------------------
        The static storage class instructs the compiler to keep a local variable in existence during the 
        life-time of the program instead of creating and destroying it each time it comes into and goes out of scope. 
        Therefore, making local variables static allows them to maintain their values between function calls.

        The static modifier may also be applied to global variables. When this is done, it causes that variable's scope 
        to be restricted to the file in which it is declared.

        In C programming, when static is used on a global variable, it causes only one copy of that member to be shared by 
        all the objects of its class.
        #include <stdio.h>
        
            //function declaration 
            void func(void);
            
            static int count = 5; // global variable 
            
            main() {

            while(count--) {
                func();
            }
                
            return 0;
            }

            //function definition 
            void func( void ) {

            static int i = 5; // local static variable 
            i++;

            printf("i is %d and count is %d\n", i, count);
            }


        EXTERN STORAGE CLASS
        ----------------------
        The extern storage class is used to give a reference of a global variable that is visible to 
        ALL the program files. When you use 'extern', the variable cannot be initialized however, it points 
        the variable name at a storage location that has been previously defined.

        When you have multiple files and you define a global variable or function, which will also be used 
        in other files, then extern will be used in another file to provide the reference of defined variable or 
        function. Just for understanding, extern is used to declare a global variable or function in another file.

        The extern modifier is most commonly used when there are two or more files sharing the same global 
        variables or functions as explained below.
        
        First File: main.c
        #include <stdio.h>
        
        int count ;
        extern void write_extern();
        
        main() {
        count = 5;
        write_extern();
        }

        Second File: support.c
        #include <stdio.h>
        extern int count;
        void write_extern(void) {
        printf("count is %d\n", count);
        }

        Here, extern is being used to declare count in the second file, where as it has its definition 
        in the first file, main.c. Now, compile these two files as follows −
        $gcc main.c support.c
        It will produce the executable program a.out. When this program is executed, it produces the following result −
        count is 5


    static keyword usage:
    ---------------------
    1) when static is used with global variables, its scope is limited to the file.
    2) when static is used with local variables, memory is allotted statically instead of automatically (static variables are 
    used to preserve state and values are not lost when function execution ends)

    #include <stdio.h>
    void function()
    {
        int a = 10;
        static int sa = 10;
        a += 5;
        sa += 5;
        printf("a = %d, sa = %d\n", a, sa);
    }
    
    
    int main()
    {
        int i;
        for (i = 0; i < 10; ++i)
            function();
    }
    a = 15, sa = 15
    a = 15, sa = 20
    a = 15, sa = 25
    a = 15, sa = 30
    a = 15, sa = 35
    a = 15, sa = 40
    a = 15, sa = 45
    a = 15, sa = 50
    a = 15, sa = 55
    a = 15, sa = 60


    extern:
    ------
    1) extern keyword is not used for defining a variable, rather it is used for declaring a variable.
    2) extern is a storage class, not a data type.
    3) extern is used to let other files or components know this variable is already defined somewhere.

    $ cat test1.c 
    int test1_var = 5;
    
    $ cat test2.c
    #include <stdio.h>
    extern int test1_var;
    int main(void) {
        printf("test1_var = %d\n", test1_var);
        return 0;
    }
    $ gcc test1.c test2.c -o test
    $ ./test
    test1_var = 5 
 */



#include <stdio.h>


void pointers_testing_pass_by_value(int *data){
    *data=33;     

    data=NULL;     

}  

void pointers_testing_pass_by_reference(int **data){            
    **data=55; 
    *data=NULL;     
}



int main(){
    int *data,*data1;     
    int temp=22,temp1=44;           
    data=&temp;            
    data1=&temp1;           

    printf("data value before function call %p", data);    
        
    printf("\nTemp value before function call%d ", temp); 
    
    /* pass by value */     
    pointers_testing_pass_by_value(data);                

    printf("\ndata value after  function call %p", data);      

    printf("\nTemp value after  function call%d ", temp);       
    


    printf("\ndata value before function call %p", data1);           
        
    printf("\nTemp value before function call%d ", temp1); 
    
    /* pass by reference */           
    pointers_testing_pass_by_reference(&data1);                     

    printf("\ndata value after  function call %p", data1);      

    printf("\nTemp value after  function call%d ", temp1);             

    return 0;        

} /* end of main function */