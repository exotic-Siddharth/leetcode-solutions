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
 * };
 */

class Solution {
public:

    vector<int> ans;

    void inorder(TreeNode* root) {

        if(root == NULL)
            return;

        inorder(root->left);

        ans.push_back(root->val);

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {

        inorder(root);

        unordered_map<int,int> mp;

        // Count frequency
        for(auto x : ans) {
            mp[x]++;
        }

        int maxi = 0;

        // Find maximum frequency
        for(auto it : mp) {
            maxi = max(maxi, it.second);
        }

        vector<int> res;

        // Store elements having max frequency
        for(auto it : mp) {

            if(it.second == maxi) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};