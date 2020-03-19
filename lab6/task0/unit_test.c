#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "slist.h"

// Helpers

#define test(fn) \
	puts("... \x1b[33m" # fn "\x1b[0m"); \
	test_##fn();

typedef struct snode node_t;
typedef struct slist list_t;

// Tests
static void
test_list_node_new() {
  char *val = "some value";
  node_t *node = snode_create(val);
  assert(strcmp(snode_get_str(node), val)==0);
  snode_destroy(node);
}

static void
test_list_add_back() {
  // Setup, think about it, why 3 nodes?
  // because this tests front, middle, and end
  list_t *list = slist_create();

  // a b c
  slist_add_back(list, "a");
  slist_add_back(list, "b");
  slist_add_back(list, "c");

  // Assertions
  node_t *a, *b, *c;
  a = slist_get_front(list);
  assert(strcmp(snode_get_str(a), "a") == 0);

  c = slist_get_back(list);
  assert(strcmp(snode_get_str(c), "c") == 0);

  assert(3 == slist_length(list));

  b = snode_get_next(a);
  assert(strcmp(snode_get_str(b), "b") == 0);
  assert(c == snode_get_next(b));
  assert(NULL == snode_get_next(c));

  //slist_destroy calls snode_destroy
  slist_destroy(list);
}

static void
test_list_add_front() {
  // Setup
  list_t *list = slist_create();

  // c b a
  slist_add_front(list, "a");
  slist_add_front(list, "b");
  slist_add_front(list, "c");

  node_t *a, *b, *c;
  c = slist_get_front(list);
  assert(strcmp(snode_get_str(c), "c") == 0);

  a = slist_get_back(list);
  assert(strcmp(snode_get_str(a), "a") == 0);

  assert(3 == slist_length(list));

  b = snode_get_next(c);
  assert(strcmp(snode_get_str(b), "b") == 0);
  assert(a == snode_get_next(b));
  assert(NULL == snode_get_next(a));

  slist_destroy(list);
}

static void
test_list_find() {
  list_t *list = slist_create();

  // a b c
  slist_add_back(list, "a");
  slist_add_back(list, "b");
  slist_add_back(list, "c");

  node_t *a, *b, *c, *z;
  a = slist_find(list, "a");
  b = slist_find(list, "b");
  c = slist_find(list, "c");
  z = slist_find(list, "z");

  assert(a != 0);
  assert(b != 0);
  assert(c != 0);
  assert(z == NULL);

  slist_destroy(list);

}

static void
test_list_delete() {
  // Setup
  list_t *list = slist_create();

  // a b c
  slist_add_back(list, "a");
  slist_add_back(list, "b");
  slist_add_back(list, "c");

  // Assertions
  assert(3 == slist_length(list));

  slist_delete(list, "b");
  assert(2 == slist_length(list));

  node_t * a = slist_get_front(list);
  assert(strcmp(snode_get_str(a), "a") == 0);

  node_t * c = slist_get_back(list);
  assert(strcmp(snode_get_str(c), "c") == 0);
  assert(c == snode_get_next(a));
  assert(NULL == snode_get_next(c));

  slist_delete(list, "a");
  assert(1 == slist_length(list));

  c = slist_get_front(list);
  assert(strcmp(snode_get_str(c), "c") == 0);
  assert(c == slist_get_back(list));
  assert(NULL == snode_get_next(c));

  slist_delete(list, "c");
  assert(0 == slist_length(list));
  assert(NULL == slist_get_front(list));
  assert(NULL == slist_get_back(list));

  slist_destroy(list);
}
int main(void){
  test(list_node_new);
  test(list_add_front);
  test(list_add_back);
  test(list_find);
  test(list_delete);
  puts("... \x1b[32m100%\x1b[0m\n");
  return 0;
}
