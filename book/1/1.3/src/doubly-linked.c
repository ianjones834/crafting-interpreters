#include "doubly-linked.h"
#include <stdio.h>
#include <stdlib.h>

struct DoublyLinkedListNode* dlln_create(void) {
  return malloc(sizeof(struct DoublyLinkedListNode));
}

void dlln_delete(struct DoublyLinkedListNode * node) {
  free(node);
  return;
}

struct DoublyLinkedList* dll_create(void) {
  struct DoublyLinkedList* list = malloc(sizeof(struct DoublyLinkedList));

  list->head = dlln_create();
  list->tail = dlln_create();

  list->head->next = list->tail;
  list->tail->prev = list->head;

  list->length = 0;

  return list;
}

void dll_delete(struct DoublyLinkedList* list) {
  while (is_dll_empty(list) == false) {
    dll_delete_node(list, 0);
  }

  free(list->head);
  free(list->tail);
  free(list);

  return;
}

void _dll_add_head(struct DoublyLinkedList* list, int val) {
  struct DoublyLinkedListNode* newNode = dlln_create();
  
  newNode->next = list->head->next;
  newNode->prev = list->head;
  list->head->next = newNode;

  list->length = list->length + 1;

  printf("added node with value: %d\n", val);
  return;
}

void _dll_add_tail(struct DoublyLinkedList* list, int val) {
  struct DoublyLinkedListNode* newNode = dlln_create();

  newNode->prev = list->tail->prev;
  newNode->next = list->tail;
  list->tail->prev = newNode;

  list->length = list->length + 1;

  printf("added node with value: %d\n", val);
  return;
}

void dll_add_node(struct DoublyLinkedList *list, int val, int index) {
  if (index < 0 || index >= list->length) {
    printf("cannot add node, index outside bounds\n");
    return;
  }

  if (index == 0) {
    _dll_add_head(list, val);
    return;
  }

  if (index == list->length - 1) {
    _dll_add_tail(list, val);
    return;
  }

  if (2*index < list->length) {
    struct DoublyLinkedListNode* scan = list->head->next;

    for (int i = 0; i < index - 1; i++) {
      scan = scan->next;
    }

    struct DoublyLinkedListNode* newNode = dlln_create();

    newNode->next = scan->next;
    newNode->prev = scan;
    
    scan->next = newNode;
  }
  else {
    struct DoublyLinkedListNode* scan = list->tail->prev;

    for (int i = 0; i < list->length - index; i++) {
      scan = scan->prev;
    }

    struct DoublyLinkedListNode* newNode = dlln_create();

    newNode->prev = scan->prev;
    newNode->next = scan;

    scan->prev = newNode;
  }

  printf("added node with value: %d\n", val);
  return;
}
