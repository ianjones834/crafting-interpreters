#ifndef DOUBLY_LINKED_H
#define DOUBLY_LINKED_H

#include<stdbool.h>

struct DoublyLinkedListNode {
  int value;
  struct DoublyLinkedListNode *next;
  struct DoublyLinkedListNode *prev;
};


struct DoublyLinkedList {
  struct DoublyLinkedListNode *head;
  struct DoublyLinkedListNode *tail;
  int length;
};

struct DoublyLinkedListNode* dlln_create(void);
void dlln_delete(struct DoublyLinkedListNode*);

struct DoublyLinkedList* dll_create(void);
void dll_delete(struct DoublyLinkedList*);

void _dll_add_head(struct DoublyLinkedList*, int);
void _dll_add_tail(struct DoublyLinkedList*, int);

void _dll_delete_head(struct DoublyLinkedList*);
void _dll_delete_tail(struct DoublyLinkedList*);

void dll_add_node (struct DoublyLinkedList*, int, int);
void dll_delete_node (struct DoublyLinkedList*, int);

int dll_get(struct DoublyLinkedList*, int);

bool is_dll_empty(struct DoublyLinkedList*);

char* _print_dll(struct DoublyLinkedList*);

#endif
