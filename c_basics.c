
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
#include <stdlib.h>

void pointers_testing_pass_by_value(int *data){
    *data=33;     

    data=NULL;     

}  

void pointers_testing_pass_by_reference(int **data){            
    **data=55; 
    *data=NULL;     
}

void fun(int a) 
{ 
    printf("\nValue of a is %d\n", a); 
}    

void add(int a, int b) 
{ 
    printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
    printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
    printf("Multiplication is %d\n", a*b); 
} 


void wrapper(void (*fn_ptr)(int, int), int a, int b){
    // fn_ptr(a,b);  /* correct */ 
    (*fn_ptr)(a,b);     
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



    /* pointer to void 
        pointer to void  is a generic pointer that can be used to represent 
        any data type during compilation or run time. Note that pointer 
        to void  is not a null pointer; it is pointing to generic data type(void)

        Any reference to void pointer must cast the pointer to the correct type
    */    
    void* p;        
    p=(int*)malloc(sizeof(int));
    if(p){
        *((int*)p)=5;    
        printf("\nMemory allocated and it's value is %d", (*(int*)p));  
    }             

    void* p1;     
    int i=10;     
    p1=&i;     
    printf("\nI contains the following value %d", (*(int*)p1));          


    /**
     * pointer to function
     * The second tool that is required to create c generic code is pointer to function
     * Functions in our program occupy memory. The name of the function is pointer constant 
     * to its first byte of memory. 
     * 
     * Just as with all other pointer types, we can define pointers to function variables
     * and store the address in them. To declarse pointer to function, e code it as if it
     * were prototype definition, with the function pointer in parantheses. The parantheses are
     * important; without them c intreprets the function return type as a pointer.
    **/
    /* fun_ptr is a pointer to function fun() */
    void (*fun_ptr)(int)=&fun;   
    /* The above line is equivalent of following two 
        void (*fun_ptr)(int); 
        fun_ptr = &fun;  
    */
    // Invoking fun() using fun_ptr 
    (*fun_ptr)(10); 
    fun_ptr(10);    
    /* If we remove bracket, then the expression “void (*fun_ptr)(int)” becomes “void *fun_ptr(int)” which is 
    declaration of a function that returns void pointer 
    
    1) Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer 
    stores the start of executable code.
    2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.
    3) A function’s name can also be used to get functions’ address. For example, in the below program, 
    we have removed address operator ‘&’ in assignment. We have also changed function call by removing *, the program still works.
    
    */
    void (*fun_ptr_1)(int)=fun;     
    fun_ptr_1(20);   

    void (*fun_ptr_2)(int);                    
    fun_ptr_2=fun;    
    fun_ptr_2(30);      

    /* 4) Like normal pointers, we can have an array of function pointers.  
    5) Function pointer can be used in place of switch case. For example, in below program, 
    user is asked for a choice between 0 and 2 to do different tasks.
    */
    // void (*fun_ptr_arr[])(int,int)={add, subtract, multiply};    
    void (*fun_ptr_arr[2])(int,int);         
    for(int i=0;i<3;i++){
        fun_ptr_arr[i]=add;    
    }        
    fun_ptr_arr[2](2,3); 
    (*fun_ptr_arr[2])(3,3);      


    /* 6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function. */
    wrapper(add, 6,5);  
    wrapper(subtract, 6,5);   
    wrapper(multiply, 6,5);        





    /**
     * pass by value
     * data value before function call 0x7ffdab2edce0
    Temp value before function call22 
    data value after  function call 0x7ffdab2edce0
    Temp value after  function call33 

    pass by reference
    data value before function call 0x7ffdab2edce4
    Temp value before function call44 
    data value after  function call (nil)
    Temp value after  function call55  
    
    pointer to void
    Memory allocated and it's value is 5
    I contains the following value 10

    pointer to function
    */            

    

    return 0;        

} /* end of main function */