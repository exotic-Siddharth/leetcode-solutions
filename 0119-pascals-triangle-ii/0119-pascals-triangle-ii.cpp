class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
        vector<int> res;
        long long ans=1;
        res.push_back(ans);
        for(int i=1;i<=n;i++){
            ans=ans*(n+1-i);
            ans/=i;
            res.push_back(ans);
        }
        return res;
    }
};