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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            bool foundX=false;
            bool foundY=false;

            while(size--){
                auto node=q.front();
                q.pop();
                if(node->val==x) foundX=true;
                if(node->val==y) foundY=true;
              if(node->left && node->right){  
                int left=node->left->val;
                int right=node->right->val;
                if((left==x && right==y) || (left==y && right==x)) return false;
              }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            
            }
             if(foundX==true && foundY==true ) return true;
             if(foundX==true || foundY==true) return false;
        }
        return false;
    }
};