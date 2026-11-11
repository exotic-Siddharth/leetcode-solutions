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
TreeNode* findMin(TreeNode* root){
    while(root->left){
        root=root->left;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key<root->val) root->left=deleteNode(root->left,key);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else 
//zero child
        if(!root->left && !root->right) return NULL;
  //one child
  else if(!root->left) return root->right;   
  else if(!root->right) return root->left;
  //zero child
  else{
     TreeNode* mini=findMin(root->right);
        root->val=mini->val;
        root->right=deleteNode(root->right,mini->val);


  }   
  return root;
    }
};