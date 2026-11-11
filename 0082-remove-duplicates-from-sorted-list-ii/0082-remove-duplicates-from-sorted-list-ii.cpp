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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
         ListNode* slow=head;
         ListNode* fast=head->next;
         ListNode* prev=nullptr;
         while(slow && fast){
            if(slow->val!=fast->val) {
                prev=slow;
                slow=fast;
                fast=fast->next;
         }
         else{
            while(fast && fast->val==slow->val) fast=fast->next;
            if(prev) prev->next=fast;
            else head=fast;
         
         slow=fast;
         if(fast)fast=fast->next;
         }
         }
    return head;
    }
};