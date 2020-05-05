#include <stdio.h>
#include "slist.h"
#include "snode.h"

struct slist *song_list;

void printer(void* print){
  char * s = (char*)(print);
  printf("%s\n", s);
}

int main(void)   {

    struct snode *node;

    song_list = slist_create();

    slist_add_back(song_list, "Thinking Out Loud",strlen("Thinking Out Loud"));
    slist_add_back(song_list, "See You Again",strlen("See You Again"));
    slist_add_back(song_list, "Trap Queen",strlen("Trap Queen"));
    slist_add_back(song_list, "Sugar",strlen("Sugar"));
    slist_add_back(song_list, "Shut Up and Dance",strlen("Shut Up and Dance"));
    slist_add_back(song_list, "Blank Space",strlen("Blank Space"));
    slist_add_back(song_list, "Watch Me",strlen("Watch Me"));
    slist_add_front(song_list, "Uptown Funk",strlen("Uptown Funk"));
    slist_add_back(song_list, "Earned It",strlen("Earned It"));
    slist_delete(song_list, "Sugar",strlen("Sugar"));
    printf("Here are the top %d songs:\n", slist_length(song_list));

    printf("Content of the list as follows.\n");
    slist_traverse(song_list, printer);

    node = slist_find(song_list, "Uptown Funk",strlen("Uptown Funk"));
    printf("Search 'Uptown Funk', node address %p\n", node);
    node = slist_find(song_list, "Earned It",strlen("Earned It"));
    printf("Search 'Earned It', node address %p\n", node);
    node = slist_find(song_list, "Sugar",strlen("Sugar"));
    printf("Search 'Sugar', node address %p\n", node);
    node = slist_find(song_list, "My Heart Will Go On", strlen("My Heart Will Go On"));
    printf("Search 'My Heart Will Go On', node address %p\n", node);  // should be NULL

    slist_destroy(song_list);

    return 0;
}
