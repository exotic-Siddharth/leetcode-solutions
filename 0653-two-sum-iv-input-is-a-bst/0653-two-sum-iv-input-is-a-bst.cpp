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
 class BSTIterator{
    stack<TreeNode*>st;
    public:
BSTIterator(TreeNode* root){
    pushAllLeft(root);
}
void pushAllLeft(TreeNode* node){
    while(node){
    st.push(node);
    node=node->left;   
}
}
int next(){
    TreeNode* temp=st.top();
    st.pop();
    pushAllLeft(temp->right);
    return temp->val;

}

 };

 class   BSTReverseIterator{
    stack<TreeNode*>st;
    public:
  BSTReverseIterator(TreeNode* root){
    pushAllRight(root);
}
void pushAllRight(TreeNode* node){
    while(node){
    st.push(node);
    node=node->right;   
}
}
int before(){
    TreeNode* temp=st.top();
    st.pop();
    pushAllRight(temp->left);
    return temp->val;

}

 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root);
        BSTReverseIterator r(root);
        int i=l.next();
        int j=r.before();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.before();
        }
        return false;
    }
};