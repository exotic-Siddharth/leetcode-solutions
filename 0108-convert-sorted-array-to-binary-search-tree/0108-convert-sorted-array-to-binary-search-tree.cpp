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
vector<int> ans;
TreeNode* balanced(vector<int>& nums,int low,int high){
     int mid=(low+high)/2;
     if(low>high) return NULL;
     TreeNode* root=new TreeNode(nums[mid]);
     root->left=balanced(nums,low,mid-1);
     root->right=balanced(nums,mid+1,high);
     return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return balanced(nums,0,nums.size()-1);
    }
};