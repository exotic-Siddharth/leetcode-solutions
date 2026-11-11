class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        long long low=0;
        long long high=nums.size()-1;
        while(low<=high){
            long long mid=(high-low)/2 +low;
            if(nums[mid]==target) return mid;
            if(target<nums[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};