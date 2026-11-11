class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,bool> mpp;
        for(int it:nums) mpp[it]=true;
        int x=k;
        while(mpp.find(x)!=mpp.end()) x+=k;
        return x;
    }
};