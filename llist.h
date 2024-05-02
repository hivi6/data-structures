#include <stdlib.h>

struct llist_node {
  void *data;
  struct llist_node *next;
};

struct llist {
  struct llist_node *head;
  struct llist_node *tail;
  int len;
};

struct llist llist_init();
void llist_delete(struct llist list);
int llist_pushback(struct llist *list, void *data);
void *llist_popback(struct llist *list);
int llist_pushfront(struct llist *list, void *data);
void *llist_popfront(struct llist *list);
int llist_insert(struct llist *list, void *data, int index);
void *llist_remove(struct llist *list, int index);

struct llist llist_init() {
  struct llist list = {
    .head = NULL,
    .tail = NULL,
    .len = 0
  };
  return list;
}

void llist_delete(struct llist list) {
  struct llist_node *node = list.head;
  while (node) {
    struct llist_node *temp = node;
    node = node->next;
    free(temp);
  }
}

int llist_pushback(struct llist *list, void *data) {
  if (list == NULL) {
    return -1;
  }

  struct llist_node *node = malloc(sizeof(struct llist_node));
  if (node == NULL) {
    return -1;
  }
  node->data = data;

  if (list->len == 0) {
    list->head = node;
    list->tail = node;
  }
  else {
    list->tail->next = node;
    list->tail = node;
  }
  list->len++;
  
  return 0;
}

void *llist_popback(struct llist *list) {
  if (list == NULL || list->len == 0) {
    return NULL;
  }

  void *res = list->tail->data;
  struct llist_node *node = list->head;
  while (node != list->tail && node->next != list->tail) {
    node = node->next;
  }
  free(list->tail);
  list->tail = node;
  node->next = NULL;
  if (list->len == 1) {
    list->head = NULL;
    node->next = NULL;
  }
  list->len--;

  return res;
}

int llist_pushfront(struct llist *list, void *data) {
  if (list == NULL) {
    return -1;
  }

  struct llist_node *node = malloc(sizeof(struct llist_node));
  if (node == NULL) {
    return -1;
  }
  node->data = data;

  if (list->len == 0) {
    list->head = node;
    list->tail = node;
  } 
  else {
    node->next = list->head;
    list->head = node;
  }
  list->len++;

  return 0;
}

void *llist_popfront(struct llist *list) {
  if (list == NULL || list->len == 0) {
    return NULL;
  }

  void *res = list->head->data;
  struct llist_node *node = list->head;
  list->head = list->head->next;
  free(node);
  if (list->len == 1) {
    list->head = NULL;
    list->tail = NULL;
  }
  list->len--;
  
  return res;
}

int llist_insert(struct llist *list, void *data, int index) {
  if (list == NULL || index < 0 || index > list->len) {
    return -1;
  }

  struct llist_node *node = malloc(sizeof(struct llist_node));
  if (node == NULL) {
    return -1;
  }
  node->data = data;

  if (index == 0) {
    return llist_pushfront(list, data);
  } 
  else if (index == list->len) {
    return llist_pushback(list, data);
  }

  struct llist_node *temp = list->head;
  struct llist_node *temp_next = temp->next;
  for (int i = 0; i < index - 1; i++) {
    temp_next = temp_next->next;
    temp = temp->next;
  }
  temp->next = node;
  node->next = temp_next;
  list->len++;

  return 0;
}

void *llist_remove(struct llist *list, int index) {
  if (list == NULL || index < 0 || index >= list->len) {
    return NULL;
  }

  if (list->len == 0) {
    return llist_popfront(list);
  }
  else if (list->len - 1 == index) {
    return llist_popback(list);
  }

  struct llist_node *temp = list->head;
  struct llist_node *temp_next = temp->next;
  void *res = NULL;
  for (int i = 0; i < index - 1; i++) {
    temp = temp->next;
    temp_next = temp_next->next;
  }
  temp->next = temp_next->next;
  res = temp_next->data;
  free(temp_next);
  list->len--;

  return res;
}
