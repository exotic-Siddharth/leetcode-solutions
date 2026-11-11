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
int minSwap(vector<int> &level){

    vector<pair<int,int>> ans;
    int n=level.size();
    int swaps=0;
    for(int i=0;i<n;i++){
        ans.push_back({level[i],i});
    }
    sort(ans.begin(),ans.end());

    for(int i=0;i<n;i++){
        if(ans[i].second==i) continue;
        else{
            swap(ans[i],ans[ans[i].second]);
            swaps++;
            i--;
        
        }
    }
    return swaps;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            while(size--){
                auto node=q.front();
                q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            }
            count+=minSwap(level);
        }
        return count;
    }
};