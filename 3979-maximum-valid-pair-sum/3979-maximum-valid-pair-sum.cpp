class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
       int n=nums.size();
        long long ans=0;
        long long mx=INT_MIN;
        for(int i=k;i<n;i++){
            mx=max(mx,(long long)nums[i-k]);
            ans=max(ans,mx+nums[i]);
        }
        return ans;
    }
};