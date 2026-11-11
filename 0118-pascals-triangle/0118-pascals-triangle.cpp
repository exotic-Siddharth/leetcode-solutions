class Solution {
public:
int NCR(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res/=i+1;
    }
    return res;
}
    vector<vector<int>> generate(int numRows) {
            int n=numRows;
        vector<vector<int>> ans;
        for(int row=1;row<=n;row++){
            vector<int> temp;
            for(int col=1;col<=row;col++){
                temp.push_back(NCR(row-1,col-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};