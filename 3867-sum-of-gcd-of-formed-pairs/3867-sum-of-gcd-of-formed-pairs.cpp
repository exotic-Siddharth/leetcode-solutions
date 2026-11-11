class Solution {
public: 
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        vector<int>prefGcd;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefGcd.push_back(gcd(nums[i],mx));
        }
        sort(prefGcd.begin(),prefGcd.end());
        long long sum=0;
       for(int i=0;i<n/2;i++){
    sum += gcd(prefGcd[i], prefGcd[n-1-i]);
}
        return sum;
    }
};