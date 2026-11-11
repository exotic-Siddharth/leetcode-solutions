class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           mpp[nums[i]].push_back(i);
        }
       for(auto it:mpp){
           vector<int> v=it.second;
           if(v.size()==3){
               if((v[1]-v[0])==(v[2]-v[1])) cnt++;
           }
       }
        return cnt;
    }
};