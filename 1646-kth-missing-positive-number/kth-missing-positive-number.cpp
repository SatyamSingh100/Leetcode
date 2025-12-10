class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n=a.size();
        int lo = 0,hi=(n-1);
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int miss = a[mid] - (mid+1);
            if(miss < k) lo = mid +1;
            else hi = mid -1;
        }
        return lo + k;
    }
};