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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int mx=INT_MIN;
            int size=q.size();
         for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            mx=max(mx,node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
         }
         ans.push_back(mx);

        }
        return ans;
    }
};