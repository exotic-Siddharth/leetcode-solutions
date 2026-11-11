class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        if(n==1) return 0;
        vector<int> left(n);
        vector<int>right(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<m && station[j]!=skill[i]) j++;
            left[i]=j;
            j++;
        }
        j=m-1;
        for(int i=n-1;i>=0;i--){
            while(j>=0 && station[j]!=skill[i]) j--;
            right[i]=j;
            j--;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            int gap=right[i]-left[i-1];
            ans=max(ans,gap);
        }
        return ans;
    }
};