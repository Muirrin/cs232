#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(void * var)
{
 //TODO: implement snode_create, change the prototype to
 //match with header file

 struct snode * n1= (struct snode*)malloc(sizeof(struct snode));
// n1->str = (char*)malloc(sizeof(char)*(strlen(s)+1));
 //strcpy(n1->str, s);
 n1->data = malloc(sizeof(var));
 n1->data = var;
 n1->next = NULL;
 return n1;
}
void snode_destroy(struct snode * s)
{
 //TODO: implement snode_destroy
//free(s->data);
free(s);
}
