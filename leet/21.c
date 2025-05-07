#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode_t {
  int val;
  struct ListNode_t *next;
} ListNode_t;

ListNode_t *mergeTwoLists(ListNode_t *head1, ListNode_t *head2) {
  if (head1 == NULL) {
    return head2;
  } 
  if (head2 == NULL) {
    return head1;
  }
  
}

