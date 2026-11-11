class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int> blocks;
        for(int i=0;i<n;i++){
            if(i==0 || nums[i]!=nums[i-1]) blocks[nums[i]]++;
        }
        int cnt=0;
        for(auto it:blocks){
            if(it.second==1) cnt++;
        }
        return cnt;
    }
};