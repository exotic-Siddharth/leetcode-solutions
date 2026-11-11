class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        int cnt=0;
        for(auto it:mpp){
            vector<int> v=it.second;
            if(v.size()>=3){
                bool ans=true;
                int d=v[1]-v[0];
                for(int i=1;i<v.size()-1;i++){
                   if((v[i+1]-v[i])!=d){
                       ans=false;
                       break;
                   }
                }
                if(ans==true) cnt++;
            }
        }
        return cnt;
    }
};