#include <stdio.h>

 int main(void)
 {

   char str[10090];
   int ch, n = 0;

printf("Please enter a letter or a string to be converted to uppercase:");

   while ((ch = getchar()) != EOF && n < 1000) {
     if(ch >= 'a' && ch <= 'z'){
       str[n] = ch - 32;
       ++n;
     }
     else if(ch >= 'A' && ch <= 'Z'){
       str[n] = ch;
       ++n;
     }
     else{
       str[n] = ch;
       ++n;
     }

   }

printf("\n");

   for (int i = 0; i < n-1; ++i){





      putchar(str[i]);



}

   putchar('\n'); /* trailing '\n' needed in Standard C */



   return 0;

 }
