/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
       
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
          int size=q.size();
          int prev;
          if(cnt%2==0) prev=INT_MIN;
          else prev=INT_MAX;
          while(size--){
            auto node=q.front();
            q.pop();
            int val=node->val;
            if(cnt%2==0){
                if(val%2==0 || node->val<=prev) return false; 
            }
            else{
                 if(val%2==1 || node->val>=prev) return false;; 
            }
            prev=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
          }
          cnt++;
        }
        return true;
    }
};