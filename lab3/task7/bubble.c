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
  int j;
  int m = 0, n = 0;
  char temp[LEN];
int holdLength;
  printf("Please enter %d strings, one per line:\n", NUM);
  for(k = 0; k < NUM; k++){
      fgets(Strings[k], LEN, stdin);

  }
  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");
  for(k = 0; k < NUM; k++){
    for(i = 0; i < strlen(Strings[k]); i++){
      putchar(Strings[k][i]);
  }
  }
  /* Write a for loop here to print all the strings. */
for(k = 0; k < NUM-1; k++)
{
  for(j=0; j < NUM - k -1; j++)
  {
    m=0;
while(m < NUM-1)
{
  n=0;

  holdLength = strlen(Strings[m]);
  if(strlen(Strings[m])<strlen(Strings[m+1]))
    holdLength = strlen(Strings[m+1]);

  while(n < holdLength)
  {
    if(Strings[m][n] > Strings[m+1][n]){

        for(i = 0; i < holdLength; i++){
          temp[i] = Strings[m][i];
          Strings[m][i] = Strings[m+1][i];
          Strings[m+1][i] = temp[i];
      }
      break;
    }
    else if(Strings[m][n] < Strings[m+1][n])
    {
      break;
    }
    n++;
  }
  m++;
}
}
}

/*
for(m = 0; m < NUM-1; m++)
{

  for(n = 0; n < LEN-2; n++)
  {
    if(Strings[m][n] > Strings[m+1][n]){

        for(i = 0; i < LEN-2; i++){
          temp[i] = Strings[m][i];
          Strings[m][i] = Strings[m+1][i];
          Strings[m+1][i] = temp[i];
      }

  }
}
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
    for(i = 0; i < strlen(Strings[k]); i++){
      putchar(Strings[k][i]);
  }
  }
  puts("\n");
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

}
