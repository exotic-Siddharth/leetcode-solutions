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
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> ans;

        ListNode* slow = head;

        while(slow) {

            ListNode* fast = slow->next;

            while(fast && fast->val <= slow->val)
                fast = fast->next;

            if(fast)
                ans.push_back(fast->val);
            else
                ans.push_back(0);

            slow = slow->next;
        }

        return ans;
    }
};