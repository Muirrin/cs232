

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _snode_H_
#define _snode_H_

struct snode {
  //TODO: change str to dynamic allcoation
  void * data;
  struct snode *next;
};

//TODO: change prototypes of functions to remove

struct snode *snode_create(void * data);
void snode_destroy(struct snode * s);

#endif /* _slist_H_ */
