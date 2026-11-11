class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int m=2;
        int cnt=0;
        for(int i=0;i<n;i++){
                  int s1=intervals[i][0];
                 int e1=intervals[i][1];
            for(int j=i+1;j<n;j++){
                 int s2=intervals[j][0];
                 int e2=intervals[j][1];
                if(max(s1,s2)<=min(e1,e2)) cnt++;
            }
        }
        return cnt;
    }
};