#include <stdio.h>
#include <stdlib.h>

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;

    if(!head || !head->next ){
        return head;
    }

    while (curr) {
        next = curr->next;  // Save the next node
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev to the current node
        curr = next;        // Move curr to the next node
    }

    return prev;  // 'prev' is now the new head of the reversed list
}
