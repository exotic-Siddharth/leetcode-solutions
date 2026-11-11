class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;int high=nums.size()-1;
        int mn=INT_MAX;
        while(low<=high){
            int mid=(high-low)/2+low;
       
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                mn = min(mn, nums[low]);
                low++;
                high--;
            }


         else  if(nums[low]<=nums[mid]){
                mn=min(mn,nums[low]);
                low=mid+1;
            }

            else{
                mn=min(mn,nums[mid]);
                high=mid-1;
            }
        }
        return mn;
    }
};