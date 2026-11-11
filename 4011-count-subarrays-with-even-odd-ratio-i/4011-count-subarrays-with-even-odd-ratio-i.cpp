class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
       
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
             int y=0;
             int x=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) x++;
                 else y++;
                if(y>0 && 1LL*x*b<=1LL*a*y) count++;
            }
        }
        return count;
    }
};