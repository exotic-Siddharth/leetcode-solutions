class Solution {
public:
    vector<int> solve(int n){
        vector<int> fact;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){ fact.push_back(i);
            while(n%i==0) n/=i;
        }
        }
        if(n>1) fact.push_back(n);
        return fact;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> primefact(n);
        for(int i=0;i<n;i++) primefact[i]=solve(nums[i]);

          
        unordered_map<int,int> freq;
        int l=0;
        int cnt=0;
        int ans=0;
        for(int r=0;r<n;r++){

            for(int p:primefact[r]){
                if(freq[p]==0) cnt++;
                freq[p]++;
            }
            while(cnt>k){
                for(auto p:primefact[l]){
                    freq[p]--;

                    if(freq[p]==0) cnt--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};