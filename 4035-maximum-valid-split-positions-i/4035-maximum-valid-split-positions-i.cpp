class Solution {
public:
    int count(vector<int>& nums){
         int n=nums.size();
      vector<int> pre(n);
        vector<int> suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=gcd(pre[i-1],nums[i]);
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=gcd(suf[i+1],nums[i]);
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]==suf[i+1]) cnt++;
        }
           return cnt;
    }
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        ans=max(ans,count(nums));

        for(int i=0;i<n;i++){
            vector<int> arr;
            for(int j=0;j<n;j++){
                if(j!=i) arr.push_back(nums[j]);
            }
            ans=max(ans,count(arr));
        }
        return ans;
    }
};