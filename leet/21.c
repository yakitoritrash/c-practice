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
  if (head1->val <= head2->val) {
    head1->next = mergeTwoLists(head1->next, head2);
    return head1;
  } else {
    head2->next = mergeTwoLists(head1, head2->next);
    return head2;
  }
}

void printlist(ListNode_t *tmp) {
  while (tmp->next != NULL) {
    printf("%d -> ", tmp->val);
    tmp = tmp->next;
  }
  printf("NULL ");
}

ListNode_t *create_node(int val) {
  ListNode_t *new_node = malloc(sizeof(ListNode_t));
  if (!new_node) {
    printf("Memory allocation failed.");
    return NULL;
  }

}
