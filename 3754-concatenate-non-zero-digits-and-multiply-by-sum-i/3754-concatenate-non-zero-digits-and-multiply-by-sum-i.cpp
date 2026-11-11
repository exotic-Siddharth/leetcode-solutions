class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long ans=0,place=1;
        while(n>0){
            long long rem=n%10;
            sum+=rem;
            if(rem!=0){
                ans+=rem*place;
                place*=10;
            }
            n/=10;
        }
        return ans*sum;
    }
};