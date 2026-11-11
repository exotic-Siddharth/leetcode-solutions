class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
       for(int x:nums){
           mp[x]++;

           if(mp[x]<=k) ans.push_back(x);
       }
     return ans;
    
    }
};