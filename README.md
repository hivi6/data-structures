# data-structures

Implementation of data-structures in C

## linked list

You can checkout `llist.h` for the implementation of linked list data structure

### usage

```c
#include <stdio.h>

#include "llist.h"

#define DEBUG_LIST(list) { \
    printf("list: { head:%p tail:%p len:%d }\n", list.head, list.tail, list.len); \
    struct llist_node *node = list.head; \
    while (node) { \
      printf("node: { self:%p data:%d next:%p }\n", \
             node, *(int*)node->data, node->next); \
      node = node->next; \
    } \
  }

int main() {
  int a = 1, b = 2, c = 3;
  int x = 5, y = 6, z = 7;

  struct llist list = llist_init();

  printf("Testing llist_pushback\n");
  llist_pushback(&list, &a);
  DEBUG_LIST(list);
  llist_pushback(&list, &b);
  DEBUG_LIST(list);
  llist_pushback(&list, &c);
  DEBUG_LIST(list);
  printf("\n");

  printf("Testing llist_pushfront\n");
  llist_pushfront(&list, &x);
  DEBUG_LIST(list);
  llist_pushfront(&list, &y);
  DEBUG_LIST(list);
  llist_pushfront(&list, &z);
  DEBUG_LIST(list);
  printf("\n");

  printf("Testing llist_popback\n");
  int *data;
  data = llist_popback(&list);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  data = llist_popback(&list);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  data = llist_popback(&list);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  printf("\n");
  
  printf("Testing llist_popfront\n");
  data = llist_popfront(&list);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  data = llist_popfront(&list);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  data = llist_popfront(&list);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  printf("\n");

  printf("Testing llist_insert\n");
  llist_insert(&list, &x, 0);
  DEBUG_LIST(list);
  llist_insert(&list, &y, 1);
  DEBUG_LIST(list);
  llist_insert(&list, &z, 1);
  DEBUG_LIST(list);
  llist_insert(&list, &a, 1);
  DEBUG_LIST(list);
  printf("\n");

  printf("Testing llist_remove\n");
  data = llist_remove(&list, 1);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  data = llist_remove(&list, 1);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  data = llist_remove(&list, 1);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  data = llist_remove(&list, 0);
  DEBUG_LIST(list);
  printf("data_prt:%p data:%d\n", data, *(int*)data);
  printf("\n");

  llist_delete(list);
  return 0;
}
```
