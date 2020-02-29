// pointer_mixer was created for examination of several aspects
// of pointers:
//   - sizeof() vs. strlen()
//   - string init: pointer init. vs array init.
//   - pointer arithmetics and manipulation
//   - structs & pointers
//
//Dr. Jun Yuan-Murray,  Feb 2020 -- prepared for CS232, Pace University
// credits: Prof. Adam J. Aviv & Prof. Mike Lam.
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ----------------------------------------------------------------------------
// "Again, read comments carefully because I spent a lot of time writing self-"
// "explainable comments like a tutorial~ ᕦ(ò_óˇ)ᕤ.." -Jun---------------------
//
// -------------------------------- Prototypes --------------------------------
//
// ----------------------------------------------------------------------------
void trace_pointers();
void trace_structs_pointers();
void strlen_vs_sizeof();
void pointer_math();
void pointer_casting();
void byte_ordering();
void simple_double_array();
void string_double_array_pointer_array();
void string_equal();
void readonly_vs_stack();

// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------
int main(void) {
    printf("---------------------------------------------\n");
    trace_pointers();
    //42 42
    //7 42
    //8 7 8 8
    //123 8 7 123 123
    printf("---------------------------------------------\n");
    trace_structs_pointers();
    //a=0 b=1
    //a=2 b=1
    //a=4 b=5
    printf("---------------------------------------------\n");
    strlen_vs_sizeof();
    //strlen(str):6 sizeof(str):7 sizeof(str2):8 sizeof(s):4, sizeof(*s):1
    printf("---------------------------------------------\n");
    pointer_math();
    //a[3]:3 str[3]:l
    //a=address of a[0], a+3=address of a[3], (a+3-a)=3
    //str=address of str[0], str+3=address of str[3], (str+3-str)=3
    printf("---------------------------------------------\n");
    pointer_casting();
    //*i = -1
    printf("---------------------------------------------\n");
    byte_ordering();
    //0x02dead
    printf("---------------------------------------------\n");
    simple_double_array();
    //darray[0] = { 1 2 3 4}
    //darray[1] = { 5 6 7 8}
    //darray[2] = { 9 10 11 12}
    //darray[3] = { 13 14 15 16}
    printf("---------------------------------------------\n");
    string_double_array_pointer_array();
    //str1: Address of str1
    //str2: Address of str2 (has a higher address because it is added as a stack)
    //strings: Address of strings [lower address because its added as a heap]
    //strings[0]: 'Go Pace!' address of strings[i], higher address
    //strings[1]: 'Beat CUNY!' address of strings[i], higher address
    //strings[2]: 'Crash SUNY!' address of strings[i], higher address
    //strings[3]: 'Enjoy CS232!' address of strings[i], higher address
    printf("---------------------------------------------\n");
    string_equal();
    //Beat CUNY!
    //s1: address of s1 == s2: address of s2? (will not match)
    //s3: address of s3 == s4: address of s4? (will match)
    printf("---------------------------------------------\n");
    readonly_vs_stack();
    //str1: this is a locust tree
    //str2: This is also a locust tree
}

// ----------------------------------------------------------------------------
//
// -------------------------- Subprogram Definitions --------------------------
//
// ----------------------------------------------------------------------------
//To differentiate the length of the string from the size of the string.

//string length: how many characters, not including the null character, are in the string
//sizeof : how many bytes required to store the string.

void strlen_vs_sizeof() {
    char str[]="Hello!";
    char str2[8]="Hello!";
    char * s = str;

    printf("strlen(str):%d sizeof(str):%d sizeof(str2):%d sizeof(s):%d, sizeof(*s):%d\n",
         (int) strlen(str),  //the length of the str
         (int) sizeof(str),  //the memory size of the str
         (int) sizeof(str2),  //the memory size of the str2
         (int) sizeof(s),    //the memory size of a pointer
         (int) sizeof(*s)    //the memory size of a char
         );
//strlen(str):6 sizeof(str):7 sizeof(str2):8 sizeof(s):4, sizeof(*s):1
}
/* ----------------------------------------------------------------------------
       <------------------------ 24 bytes ---------------------------->
       .---------------.----------------.--- - - - ---.----------------.
a   -> |             0 |              1 |             |              7 |
       '---------------'----------------'--- - - - ---'----------------'

       .---.---.---.---.---.---.
str -> | H | e | l | l | o | \0|
       '---'---'---'---'---'---'
       <-------  7 bytes ------>
*/
void pointer_math() {
    int a[] = {0,1,2,3,4,5,6,7};
    char str[] = "Hello!";
    //pointer arithmetic consideration of typing
    printf("a[3]:%d str[3]:%c\n", *(a+3),*(str+3));
    //a[3]:3 str[3]:l
    // I know you would not know what the actual addresses are, just comment
    // what you think (a+3-a) and (str+3-str) are.
    printf("a=%p a+3=%p (a+3-a)=%ld\n",a,a+3, ((long) (a+3)) - (long) a);
    //a=address of a[0], a+3=address of a[3], (a+3-a)=3
    printf("str=%p str+3=%p (str+3-str)=%ld\n",str,str+3, ((long) (str+3)) - (long) str);
    //str=address of str[0], str+3=address of str[3], (str+3-str)=3
}
// ----------------------------------------------------------------------------

//Do we have to store chars in char array?
void pointer_casting() {
    char s[4]; //allocate 4bytes
    s[0] = 255;//255 is largest uint value in 1-byte
    s[1] = 255;
    s[2] = 255;
    s[3] = 255;//we usually store '\0' here as terminator, but we do not have to
    	       //we can store any arbitrary data here

    int * i = (int *) s;  //cast s to an integer pointer
    printf("*i = %d\n", *i);
    //*i = -1
    //use characters as a generic container for data and then used pointer casting
    //to determine how to interpret that data. char array is an arbitrary container
    //that stores a bunch of bytes.
}

// ----------------------------------------------------------------------------
void byte_ordering() {
  unsigned int a = 0xdeadbeef;    //hex number
  unsigned char * p = (unsigned char *) &a;

  int i;
  printf("0x");
  for(i=0;i<4;i++){
    printf("%02x",p[i]);
  }
  printf("\n");
  //0x02dead
}
// ----------------------------------------------------------------------------

//a very simple double array to warm you up:
//wait, isn't double-array supposed to be covered in Java 1&2. Anyway, do it.
void simple_double_array() {
    //We can also do static declarations of values with { }. What does this
    //nested {} mean? Hmm
    //it means a double array is essentially an array of arrays. :P
    int darray[][4] = { {1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15, 16}};
    int i,j;
    //you can skip commenting the following printfs in loop when doing your lab4
    for(i=0;i<4;i++){
        printf("darray[%d] = { ",i);
        for(j=0;j<4;j++){
           printf("%d ",darray[i][j]); //<---
        }
        printf("}\n");
        //darray[0] = { 1 2 3 4}
        //darray[1] = { 5 6 7 8}
        //darray[2] = { 9 10 11 12}
        //darray[3] = { 13 14 15 16}
    }
   //"What do you mean by an array of arrays?" I meant this:
   /*                           .---.---.---.---.
            .---.  _.----> | 0 | 0 | 0 | 0 |  <-- darray[0]
darray ---> | --+-'        '---'---'---'---'
            |---|          .---.---.---.---.
            | --+--------> | 1 | 1 | 1 | 1 |  <-- darray[1]
            |---|          '---'---'---'---'
            | --+-._       .---.---.---.---.
            |---|   '----> | 2 | 2 | 2 | 2 |  <-- darray[2]
            | --+-._       '---'---'---'---'
            '---'   '._    .---.---.---.---.
                       '-> | 3 | 3 | 3 | 3 |  <-- darray[3]
                           '---'---'---'---'
*/
    //darray is actually a int **  it is a pointer that references a memory address
    //that stores another pointer that references a memory address of an integer.
    // adarray equals to &darray[0] which equals to &(&array[0])
    // a double array is a double pointer
    printf("*(*(darray+2)+2) = %d\n", *(*(darray+2)+2)); //this is just a different way to access the value at darray[2][2]
    //*(*(darray+2)+2) = 11
    printf("     darray[2][2] = %d\n", darray[2][2]); //finds the value at darray[2][2]
    //     darray[2][2] = 11
}
// ----------------------------------------------------------------------------
void string_double_array_pointer_array() {
    //these are two strings
    char str1[] = "This is a locust tree"; //str1 is a statically alloc-ed array
    char * str2 = "This is also a locust tree"; //str2 is a pointer to char

    printf("str1:%p\n",str1);
    printf("str2:%p\n",str2); //which is at the higer address? why?
                              //check the memory layout of your process
                              //what lays at the bottom?
    //str1: Address of str1
    //str2: Address of str2 (has a higher address because its added as a stack)
    //this is an array of strings, each string is a char *
    char * strings[]={"Go Pace!",
                     "Beat CUNY!",
                     "Crash SUNY!",
                     "Enjoy CS232!"};
    int i;

    printf("strings: %p\n",strings); //higher address or lower address? why?
    //strings: Address of strings [lower address because it's added as a heap]
    for(i=0;i<4;i++){
      printf("strings[%d]: '%s' %p\n",i,strings[i],strings[i]);
      //are they in higher address or lower address? why?
      //strings[i]: 'string' address of strings[i], lower address because it is a value
  }
        //strings[0]: 'Go Pace!' address of strings[i], lower address because it is a char
        //strings[1]: 'Beat CUNY!' address of strings[i], lower address because it is a char
        //strings[2]: 'Crash SUNY!' address of strings[i], lower address because it is a char
        //strings[3]: 'Enjoy CS232!' address of strings[i], lower address because it is a char
}
// ----------------------------------------------------------------------------
//a common mistake for Java programmers to manipulate C strings:
void string_equal() {
    char s1[]="Pace";
    char s2[]="Pace";
    char * s3 = "Pace";
    char * s4 = "Pace";
    if(s1 == s2){
        printf("Go Pace!\n");
    }else if(s3 == s4) {
        printf("Beat CUNY!\n");
    }else {
        printf("Crash SUNY!\n");
    }
    printf("\n");
    printf("s1: %p == s2: %p? \n", s1, s2);
    printf("s3: %p == s4: %p? \n", s3, s4);
    //Beat CUNY!
    //s1: address of s1 == s2: address of s2? (will not match)
    //s3: address of s3 == s4: address of s4? (will match)
}
//Now do you understand why we need string lib, like strcmp?
// ----------------------------------------------------------------------------
// Just simple trace for pointers, just a warm up
void trace_pointers() {
    int a = 42;
    int b = 7;
    int c = 999;
    int *t = &a;
    int *u = NULL;
    printf("%d %d\n", a, *t);

    c = b;
    u = t;
    printf("%d %d\n", c, *u);

    a = 8;
    b = 8;
    printf("%d %d %d %d\n", b, c, *t, *u);

    *t = 123;
    printf("%d %d %d %d %d\n", a, b, c, *t, *u);

    //42 42
    //7 42
    //8 7 8 8
    //123 8 7 123 123
}

// ----------------------------------------------------------------------------
// Yet another simple trace for pointers and structs
typedef struct {
    int *a;
    int b;
} stuff_t;

static void foo(stuff_t value)
{
    *(value.a) = 2;
    value.b = 3;
}

static void bar(stuff_t *value)
{
    *(value->a) = 4;
    value->b = 5;
}

void trace_structs_pointers()
{
    stuff_t my_stuff;
    int temp = 0;

    my_stuff.a = &temp;
    my_stuff.b = 1;
    printf("a=%d b=%d\n", *(my_stuff.a), my_stuff.b);
    //a=0 b=1
    foo(my_stuff); //only changes a, as b is not returned nor is it a pointer
    printf("a=%d b=%d\n", *(my_stuff.a), my_stuff.b);
    //a=2 b=1
    bar(&my_stuff); //changes both because it reallocates the values
    printf("a=%d b=%d\n", *(my_stuff.a), my_stuff.b);
    //a=4 b=5
}

// ----------------------------------------------------------------------------
void readonly_vs_stack() {
  char str1[] = "This is a locust tree"; //str1 is a statically alloc-ed array
  char * str2 = "This is also a locust tree"; //str2 is a pointer to char

  str1[0] = 't';
  printf("str1: %s \n",str1);
  //str1: this is a locust tree
  str2[0] = 't';
  printf("str2: %s \n",str2);
  //str2: This is also a locust tree
  //review&Correction: Trying to change the value inside of a pointer array messes with the memory, which is why there is a segmentation fault
}
