class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int>freq(101,0);
        for(int x:nums) freq[x]++;

        while(true) {
            bool found=false;

            for(int x=1;x<=100;x++){
                if(freq[x]>0){
                    ans.push_back(x);
                    freq[x]--;
                    found=true;
                }
            }
            if(!found) break;
        }
        return ans;
    }
};