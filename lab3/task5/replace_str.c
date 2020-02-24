/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CS232(char* src, int srcLength) {
     char *srcptr, *replaceptr;
     // char *srcptr, *replaceptr;
     char replacement[15] = "232 is awesome!";
     srcptr = src;
     replaceptr = replacement;

     if (srcLength <= 15) {
         for (int i = 0; i < 15; i++)
	      *srcptr++ = *replaceptr++;
     }
}
char * replace_string() {
    char *str_ptr;
    str_ptr = (char*)malloc(sizeof(char*)*15);
    int srcLength = strlen(str_ptr);
    CS232(str_ptr,srcLength);
    return str_ptr;
}
int main(int argc, char ** argv) {
    char * ret = replace_string();
    printf("replaced string = %s\n", ret);
    free(ret);
    return 0;
}
