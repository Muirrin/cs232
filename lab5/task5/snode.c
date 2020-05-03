#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(void * d)
{
 //TODO: implement snode_create, change the prototype to
 //match with header file

 struct snode * n1= (struct snode*)malloc(sizeof(struct snode));
 n1->data = (void*)malloc(sizeof(void));
 n1->data = d;
 n1->next = NULL;
 return n1;
/*
struct snode *node;
node = (struct snode*)malloc((strlen(s)+1) * sizeof(struct snode));
temp->str = s;
return temp;
*/

}
void snode_destroy(struct snode * s)
{
 //TODO: implement snode_destroy
free(s->data);
free(s);


}
