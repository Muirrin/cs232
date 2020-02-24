/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 3   /* number of strings */
#define LEN 1200  /* max length of each string */

int main()
{
  char Strings[NUM][LEN];
  int k;
  int i;
  int j;
  int m = 0, n = 0;
  char temp[LEN];

  printf("Please enter %d strings, one per line:\n", NUM);
  for(k = 0; k < NUM; k++){
      fgets(Strings[k], LEN, stdin);

  }
  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */

  /* Write a for loop here to print all the strings. */
  puts("\nHere are the strings in the order you entered:");
  for(k = 0; k < NUM; k++){
    for(i = 0; i < strlen(Strings[k]); i++){
      putchar(Strings[k][i]);
  }
  }

  /* Bubble sort */
for(k = 0; k < NUM-1; k++) // iterates through the list NUM times to guarantee the list is sorted
{
  for(j=0; j < NUM - k -1; j++)
  {
    m=0;
while(m < NUM-1) // iterates through every word
{
  n=0;

  while(n < LEN) //iterates through the two words to compare each letter
  {
    if(Strings[m][n] > Strings[m+1][n]){ //compares the two strings, if bigger, then swap and exit while loop

        for(i = 0; i < LEN; i++){
          temp[i] = Strings[m][i];
          Strings[m][i] = Strings[m+1][i];
          Strings[m+1][i] = temp[i];
      }
      break;
    }
    else if(Strings[m][n] < Strings[m+1][n]) //compares two strings, if smaller then exit while loop
    {
      break;
    }
    n++;
  }
  m++;
}
}
}

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
    for(i = 0; i < strlen(Strings[k]); i++){
      putchar(Strings[k][i]);
  }
  }
  puts("\n");
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

}
