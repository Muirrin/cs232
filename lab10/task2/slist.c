#include "slist.h"
#include "snode.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * Allocates new slist dynamically.
 *
 * @return pointer to the list
 */
struct slist *slist_create(){
  struct slist *ptr;
  ptr->size = 0;
  ptr  = (struct slist*)malloc(sizeof(struct slist));
  ptr->front =NULL;
  ptr->back=NULL;
  return ptr;
}
/**
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, void * data, int s){
//creates new node, sets temp to the front node
struct snode * new = snode_create(data,s);
 struct snode * temp = l->back;
 if(l->front == NULL){
   l->front = new;
   l->back = new;
      l->size = 1;
 }
 else if(l->back == NULL){
   l->front = new;
   l->back = new;
      l->size = 1;
 }
 else{
   temp->next = new;
   l->back = new;
     l->size++;
 }

return new;
}
/**
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, void * data, int s){

  struct snode *new = NULL;
  new = snode_create(data, s);

  if(l->front == NULL){
    l->front = new;
    l->back = new;
        l->size = 1;
  }
  else if(l->back == NULL){
    l->front = new;
    l->back = new;
        l->size = 1;
  }
  else{
    struct snode *temp = l->front;
    new->next = temp;
    l->front = new;
      l->size++;
  }
  return new;
  /*  temp = l->front;
    l->front = new;
    new->next = temp;
  while(temp->next != NULL)
  {

    temp = last;
    last = last‐>next;

  }
  new = l->back;
  new = new->next;
  strcpy(new->str, str);


  return l->front;
  */
}
/**
 * Returns the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, void * data, int s){
  struct snode *temp;
  temp = l->front;
do{
  if(memcmp(temp->data,data, s)==0)
  {
      return temp;
  }
  temp = temp->next;
}while(temp != NULL);
return NULL;
}


struct snode* slist_find_at(struct slist *l, int index){
  struct snode * temp = l->front;
  int k;
  if(index < 0)
  {
      int iterate = l->size + index;

      if(iterate<0){
        return NULL;
      }
      for(k = iterate; k > 0; k--){
          temp = temp->next;
      }
  }
  else{
      for(k = index; k > 0; k--){
          temp = temp->next;
      }
  }
  return temp;



}
/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){
  struct snode * temp = l->front;
  while(l->front!= NULL){
    temp = l->front;
    l->front = temp->next;
    snode_destroy(temp);
  //l->front = NULL;
}
free(l);
}
/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l, void(*ptr)(void*)){
  struct snode *temp;
  temp = l->front;

while(temp != NULL){

        (*ptr)(temp->data);
        temp = temp->next;
}
}
/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
  int len = l->size;
  return len;
}
/**
 * Deletes the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
void slist_delete(struct slist *l, void * data, int s){

  struct snode * temp  = l->front;
  struct snode * prev  = NULL;

  if(temp != NULL && memcmp(temp->data,data,s)==0)
  {
      l->front = temp->next;
      snode_destroy(temp);
          l->size--;
      if(l->front == NULL){
        l->back = NULL;
      }
      return;
  }
  else{
  while (temp != NULL)
  {
      if (memcmp(temp->data,data,s)==0)
      {

              prev->next = temp->next;
              snode_destroy(temp);
                l->size--;
              return;
      }
      prev = temp;
      temp = temp->next;

  }
  }
}


/*
struct snode * slist_get_front(struct slist *l){
  struct snode * temp  = l->front;
  return temp;
}

void slist_set_front(struct slist *l){
  if(l->front->next == NULL){
    return;
  }
  l->front = l->front->next;

}
struct snode * slist_get_back(struct slist *l){
  if(l==NULL){
    return NULL;
  }
  struct snode * temp  = l->back;
  return temp;
}

void * snode_get_str(struct snode * a){
  void *s = a->data;
  return s;
}

struct snode * snode_get_next(struct snode * a){
    struct snode * temp  = a->next;
  return temp;
}
*/
