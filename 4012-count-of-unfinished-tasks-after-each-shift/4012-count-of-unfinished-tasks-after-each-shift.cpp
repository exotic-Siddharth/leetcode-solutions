class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+tasks[i];
        }
        long long total=pref[n];
        long long done=0;
        vector<int> ans;

        for(long long t:shifts){
            if(done+t>=total){
                ans.push_back(0);
                done=0;
            }
            else{
                done+=t;
                int ind=upper_bound(pref.begin(),pref.end(),done)-pref.begin()-1;
                ans.push_back(n-ind);
            }
        }
        return ans;
    }
};