class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        vector<int> ans;
int n=nums.size();
        vector<int> prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++) prefix[i]=prefix[i-1]+nums[i];
        for(int i=0;i<nums.size();i++){
            int leftSum=prefix[i];
            int rightSum=prefix[n-1]-prefix[i];

            int leftContri=nums[i]*(i+1)-leftSum;
            int rightContri=rightSum-nums[i]*(n-i-1);

            ans.push_back(leftContri+rightContri);
        }
        return ans;
    }
};