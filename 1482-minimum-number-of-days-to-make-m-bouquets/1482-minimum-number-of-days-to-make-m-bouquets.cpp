class Solution {
public:
bool possible(vector<int>& bloomDay,int mid, int m, int k){
  int cnt=0,numOfBloom=0;
  long long n=bloomDay.size();
    for(long long i=0;i<n;i++){
        if(bloomDay[i]<=mid) cnt++;
        else{
            numOfBloom+=cnt/k;
            cnt=0;
        }
    }
    numOfBloom+=cnt/k;
 return numOfBloom>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        if(1LL * m * k > n) return -1;
        int mn=INT_MAX,mx=INT_MIN;
        for(long long i=0;i<n;i++){
            mn=min(mn,bloomDay[i]);
            mx=max(mx,bloomDay[i]);
        }
        int low=mn,high=mx;
        int ans=high;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};