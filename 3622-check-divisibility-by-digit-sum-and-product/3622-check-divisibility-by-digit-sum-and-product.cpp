class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int org=n;
        while(n){
            int rem=n%10;
            sum+=rem;
            product*=rem;
            n/=10;
        }
        if(org%(sum+product)==0) return true;
        return false;
    }
};