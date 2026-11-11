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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* cur=slow->next;
        while(cur){
            ListNode* nextNode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextNode;
        }
        ListNode* first=head;
        ListNode* second=prev;
        while(second){
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;

    }
};