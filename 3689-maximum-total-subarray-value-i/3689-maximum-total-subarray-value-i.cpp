class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn=INT_MAX;
        long long mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
                 if(mx<nums[i]) mx=nums[i];
                if(mn>nums[i]) mn=nums[i];
        }
        return (mx-mn)*k;
    }
};