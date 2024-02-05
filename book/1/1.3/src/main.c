#include "doubly-linked.h"

int main(void) {
  struct DoublyLinkedList* list = dll_create();

  dll_add_node(list, 0, 0);


  return 0;
}
