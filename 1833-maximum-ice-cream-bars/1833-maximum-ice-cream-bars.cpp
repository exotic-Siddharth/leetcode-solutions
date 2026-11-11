class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        long long sum=0;
        long long cnt=0;
        // if(costs[0]>coins) return -1;
        for(int i=0;i<costs.size();i++){
            sum+=costs[i];
            if(sum<=coins) cnt++;
        }
        if(cnt>0) return cnt;
        return 0;
    }
};