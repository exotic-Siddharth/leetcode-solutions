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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
          int size=q.size();
          vector<TreeNode*> temp;
          while(size--){
            auto node=q.front();
            q.pop();
            temp.push_back(node);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
          }
          if(cnt%2==1) {
            int i=0,j=temp.size()-1;
            while(i<j){
                swap(temp[i]->val,temp[j]->val);
                i++;
                j--;
            }
          }
        
          cnt++;
        }
        return root;
    }
};