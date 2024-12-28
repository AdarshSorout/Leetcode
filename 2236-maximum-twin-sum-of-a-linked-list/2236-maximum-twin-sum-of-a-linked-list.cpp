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
    int pairSum(ListNode* head) {
        vector<int>vec;
        while(head!=NULL){
            vec.push_back(head->val);
            head=head->next;
        }
        int n=vec.size();
        int i=0;
        int j=n-1;
        int res=0;
        while(i<j){
         int pSum=vec[i]+vec[j];
         i++;
         j--;
         res=max(res,pSum);
        }
        return res;
    }
};