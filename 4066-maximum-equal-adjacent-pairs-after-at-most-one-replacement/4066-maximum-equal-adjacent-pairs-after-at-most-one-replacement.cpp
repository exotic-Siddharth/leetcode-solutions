class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int bs=0;
        map<pair<int,int>,int>mp;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) bs++;
            else{
                int x=nums[i-1];
                int y=nums[i];
                if(x>y) swap(x,y);
                mp[{x,y}]++;
            }
        }
        int ans=0;
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        return ans+bs;
    }
};