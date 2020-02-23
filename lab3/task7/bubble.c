/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int main()
{
  char Strings[NUM][LEN];
  int k;
  int i;
  printf("Please enter %d strings, one per line:\n", NUM);
  for(k = 0; k < NUM; k++){
    for(i = 0; i < LEN; i++){
      fgets(Strings[k][i], LEN, stdin);
    }
  }
  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");
  for(k = 0; k < NUM; k++){
    for(i = 0; i < LEN; i++){
      putchar(Strings[k][i]);
  }
  }
  /* Write a for loop here to print all the strings. */
/*
  while(n < LEN)
  {
    if()
    if(Strings[m][n] > Strings[m+1][n]){
      temp = Strings[m][n];
      Strings[m][n] = Strings[m+1][n];
      Strings[m+1][n] = temp;
      break;
    }
    else if(Strings[m][n] < Strings[m+1][n])
    {
      break;
    }
    n++;
  }
  */
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) The swap of two strings must be done by copying them
            (using a temp variable of your choice) one character at a time,
            without using any C string library functions.
            That is, write your own while/for loop to do this.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */



  /* Output sorted list */

  puts("\nIn alphabetical order, the strings are:");
  for(k = 0; k < NUM; k++){
    for(i = 0; i < LEN; i++){
      putchar(Strings[k][i]);
  }
  }
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

}
