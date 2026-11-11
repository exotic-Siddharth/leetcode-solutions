class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        unordered_map<int,bool> mp;
        for(int x:nums) mp[x]=true;
        int i=lower;
        while(i<=upper){
            if(mp.find(i)!=mp.end()){
                i++;
                continue;
            }
            int start=i;
            while(i<=upper && mp.find(i)==mp.end()){
                i++;
            }
            ans.push_back({start,i-1});
        }
        return ans;
    }
};