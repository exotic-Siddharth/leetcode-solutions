class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0,r=k-1,sum=0;
        for(int i=l;i<=r;i++) sum+=arr[i];
        int count=0;
        if((sum/k)>=threshold) count++;
        while(r<arr.size()-1){
           sum-=arr[l];
           l++;
           r++;
           sum+=arr[r];
           if((sum/k) >=threshold) count++;
        }
        return count;
    }
};