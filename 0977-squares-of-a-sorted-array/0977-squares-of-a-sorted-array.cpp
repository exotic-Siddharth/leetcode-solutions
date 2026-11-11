class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1,ind=nums.size()-1;
         vector<int> ans(nums.size());
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                ans[ind]=nums[l]*nums[l];
                l++;
            }
            else {
                ans[ind]=nums[r]*nums[r];
                r--;
            }
            ind--;
        }
        return ans;

    }
};