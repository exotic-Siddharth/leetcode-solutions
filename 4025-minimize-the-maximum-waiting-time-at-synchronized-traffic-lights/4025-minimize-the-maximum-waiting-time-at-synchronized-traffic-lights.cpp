class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mxG=0;
        for(int it:lights) mxG=max(mxG,it);
        int ans=0;
        for(auto t:arrivalTime){
            int r=t%period;
            int wait=0;
            if(r>=mxG) wait=period-r;
            ans=max(ans,wait);
        }
        return ans;
    }
};