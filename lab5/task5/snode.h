

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _snode_H_
#define _snode_H_

struct snode {
  //TODO: change str to dynamic allcoation
  void * data;
  struct node * next;

};

//TODO: change prototypes of functions to remove

struct snode *snode_create(void * d,int s);
void snode_destroy(struct snode * s);

#endif /* _slist_H_ */
