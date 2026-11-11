class Solution {
public:  const long long mod=1e9+7;
    long long power(long long x,long long y){
        long long ans=1;

        while(y>0){
            if(y&1) ans=(ans*x)%mod;
            x=(x*x)%mod;
            y/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
      
        long long ans=0;
        for(int i=0;i<n;i++){
            int width=nums[i]%10;
            long long d=floor(nums[i]/10);
              string s=to_string(d);
            string xs=s.substr(0,width);
            string ys=s.substr(width);
            long long x=stoll(xs);
            long long y=stoll(ys);
             ans=(ans+power(x,y)%mod)%mod;
        }
        return ans;
    }
};