class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:nums) pq.push(it);
        long long mod=1e9+7;
        for(int i=k;i>0;i--){
        int x=pq.top();
        pq.pop();
        pq.push(x+1);
        }
        long long ans=1;
        while(pq.size()!=0){
         int x=pq.top();
         pq.pop();
         ans=(ans*x)%mod;
        }
        return ans;
    }
};