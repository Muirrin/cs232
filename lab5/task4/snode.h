#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct snode {
  char str[101];
  int length;
  struct snode *next;
};

struct snode *snode_create(char *s, int length) ;
void snode_destroy(struct snode * s) ;
 
