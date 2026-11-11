class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
       int ans=1;

        for(int l=0;l<n;l++){
            vector<int> freq(501,0);
            for(int r=l;r<n;r++){
                int x=nums[r];
                bool bad=false;

                for(int a=1;a<x;a++){
                    int b=x-a;

                    if(freq[a]>0 && freq[b]>0){
                        if(a!=b || freq[a]>=2){
                            bad=true;
                            break;
                        }
                    }
                }
                if(!bad){
                    for(int a=1;a<=500-x;a++){
                        if(freq[a]>0 && freq[x+a]>0){
                            bad=true;
                            break;
                        }
                    }
                }
                if(bad) break;
                freq[x]++;
                ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
};