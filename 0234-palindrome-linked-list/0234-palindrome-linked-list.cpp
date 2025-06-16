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
ListNode*reverse(ListNode*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode*newHead=reverse(head->next);
    ListNode*front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newHead=reverse(slow->next);
        ListNode*first=head,*sec=newHead;
        while(sec!=NULL){
            if(first->val!=sec->val)return false;
            first=first->next;
            sec=sec->next;
        }
        return true;
    }
};