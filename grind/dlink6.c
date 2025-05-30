#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
  struct node_t *prev;
} node_t;

typedef struct link_t {
  node_t *head;
  node_t *tail;
} link_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if(!new_node) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  new_node->data = value;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

node_t *prepend(link_t *list, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return NULL;
  }
  new_node->next = list->head;
  if (list->head != NULL) {
    list->head->prev = new_node;
  } else {
    list->tail = new_node;
  } 
  list->head = new_node;
  return new_node;
}

node_t *append(link_t *list, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return list->head;
  }
//  node_t *tmp = list->head;
//  while (tmp->next != NULL) {
//    tmp = tmp->next;
//  }
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  }
  list->tail->next = new_node;
  new_node->prev = list->tail;
  list->tail = new_node;
  return list->head;
}

node_t *insert_at(link_t *list, int value, int position) {
  node_t *new_node = create_node(value);
  if (list->head == NULL) {
    return NULL;
  }
  if (position == 0) {
    return prepend(list, value);
  }
  node_t *tmp = list->head;
  for (int i = 0; i < position - 1; i++) {
    if (tmp == NULL) {
      printf("Out of bounds\n");
      return list->head; 
    }
    tmp = tmp->next;
  }

  if (tmp == list->tail) {
    return append(list, value);
  }
  new_node->next = tmp->next;
  tmp->next = new_node;
  if (new_node->next != NULL) {
    new_node->next->prev = new_node;
  }
  new_node->prev = tmp;
  return list->head;
}

node_t *delete_at(link *list, int position) {
  if (position == 0) {
    node_t *to_delete = list->head;
    list->head = list->head->next;
    free(to_delete);
    return list->head;
  }

  node_t *tmp = list->head;
  for (int i = 0; i < position - 1; i++) {
    if (tmp == NULL || tmp->next == NULL) {
      
    } 
  }
}

