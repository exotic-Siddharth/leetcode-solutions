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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int preIndex = 0;

    unordered_map<int,int> mp;

    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int postStart, int postEnd) {

        if(postStart > postEnd)
            return NULL;

        TreeNode* root =
            new TreeNode(preorder[preIndex++]);

        if(postStart == postEnd)
            return root;

        int leftRoot = preorder[preIndex];

        int index = mp[leftRoot];


        root->left =   build(preorder, postorder,
                  postStart, index);

    
        root->right =build(preorder, postorder,index + 1, postEnd-1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        for(int i = 0; i < postorder.size(); i++) {

            mp[postorder[i]] = i;
        }

        return build(preorder, postorder,
                     0, postorder.size() - 1);
    }
};