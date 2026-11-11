class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> arr;
        int start=0;
        arr.push_back(0);
        for(int i=0;i<n;i++){
           start+=gain[i];
           arr.push_back(start);
        }
        int mx=INT_MIN;
        for(int i=0;i<n+1;i++){
         mx=max(mx,arr[i]);
        }
        return mx;
    }
};