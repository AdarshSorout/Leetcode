/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != tail) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; ++i) {
                kth = kth->next;
                if (!kth) return dummy->next; 
            }

            ListNode* groupNext = kth->next;
            ListNode* prev = groupPrev->next;
            ListNode* curr = prev->next;
            for (int i = 1; i < k; ++i) {
                prev->next = curr->next;
                curr->next = groupPrev->next;
                groupPrev->next = curr;
                curr = prev->next;
            }

            groupPrev = prev; 
        }

        return dummy->next;
    }
};
