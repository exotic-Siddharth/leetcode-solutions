class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen=0;
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r]==1) maxLen=max(maxLen,r-l+1);
            if(nums[r]==0) l=r+1;
            r++;
        }
        return maxLen;
    }
};