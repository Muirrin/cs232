/*memleak_example.c*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int * a = malloc(sizeof(int *));

  *a = 10;

  printf("%d\n", *a);
//free a, because calloc later
free(a);
  a = calloc(3, sizeof(int *));
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;

  printf("%d %d %d\n", a[0], a[1], a[2]);
//free a, because a is no longer in use
free(a);
}
