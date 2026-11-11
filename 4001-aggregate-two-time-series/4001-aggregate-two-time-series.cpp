class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        auto res=make_pair(series1,series2);
        vector<vector<int>> ans;
        int p1=0,p2=0;
        int n=series1.size();
        int m=series2.size();
        while(p1<n||p2<m){
            if(p2==m ||(p1<n && series1[p1][0]<series2[p2][0])){
              int time  =series1[p1][0];
                int sum=series1[p1][1];
                if(p2<m) sum+=series2[p2][1];
                ans.push_back({time,sum});
                p1++;
            }
             else if(p1==n || series2[p2][0]<series1[p1][0]){
              int time  =series2[p2][0];
                int sum=series2[p2][1];
                if(p1<n) sum+=series1[p1][1];
                ans.push_back({time,sum});
                p2++;
            }
            else {
                int time=series1[p1][0];
                int sum=series1[p1][1]+series2[p2][1];
                 ans.push_back({time,sum});
                p1++;
                p2++;
            }
            
        }
        return ans;
    }
};