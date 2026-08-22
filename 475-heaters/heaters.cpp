class Solution {
public:
    bool check(vector<int>& houses,vector<int>& heaters, long long mid){
        int n = houses.size(), m =heaters.size();
        int i=0,j=0;
        while(i < n && j < m){
            long long mini = heaters[j] - mid, maxi = heaters[j] + mid;
            if(houses[i] >= mini && houses[i] <= maxi) i++;
            else j++;
        }
        if(i == n) return true;
        return false;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(),m =heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int mini = 0, maxi = 0;
        maxi = max(maxi,max(abs(heaters[0]-houses[0]), abs(heaters[m-1] - houses[n-1])));
        for(int i=1; i<m; i++){
            maxi = max( maxi , ((heaters[i] - heaters[i-1])/2) );
        }
        long long l = mini, r = maxi;
        long long ans =0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(check(houses, heaters, mid) == true){
                ans = mid; r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};