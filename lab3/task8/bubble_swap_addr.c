#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>
#define NUM 5   /* number of strings */
#define LEN 1200  /* max length of each string */

int main()
{
  char * Strings[NUM];
  int k;
  int i;
  int m = 0, n = 0;
  char * temp;

  printf("Please enter %d strings, one per line:\n", NUM);
  for(k = 0; k < NUM; k++){
      fgets(Strings[k], LEN, stdin);
  }

  puts("\nHere are the strings in the order you entered:");
  for(k = 0; k < NUM; k++){
      printf("%s\n", Strings[k]);
  }


for(k = 0; k < NUM-1; k++) // iterates through the list NUM times to guarantee the list is sorted
{
    m=0;
while(m < NUM-1) // iterates through every word
{
  n=0;

  while(n < LEN) //iterates through the two words to compare each letter
  {
    char * ptr1;
    char * ptr2;

    if(ptr1>ptr2){ //compares the two strings, if bigger, then swap and exit while loop
        for(i = 0; i < LEN; i++){
ptr1 = Strings[k];
ptr2 = Strings[i];

          temp = ptr1;
          ptr1 = ptr2;
          ptr2 = temp;

    }
    ptr1++;
    ptr2++;
  }
    else if(ptr1 < ptr2) //compares two strings, if smaller then exit while loop
    {
      break;
    }
    n++;
  }
  m++;
}
}

  puts("\nIn alphabetical order, the strings are:");
  for(k = 0; k < NUM; k++){
      printf("%s\n", Strings[k]);
  }
  puts("\n");


}
