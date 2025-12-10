class Solution {
public:
    int f1(vector<int>& a, int d){
        int sum =0,days=0;
        for(int i=0; i<a.size(); i++){
            if(sum + a[i] > d){
                days++; sum =a[i];
            }
            else sum += a[i];
        }
        if(sum > 0) days++;
        return days;
    }
    int shipWithinDays(vector<int>& a, int d) {
        int n = a.size();
        int l = *max_element(a.begin(),a.end()), r = (n*l);
        int ans = 1e9;
        while(l <= r){
            int mid = (l+r)/2;
            int days = f1(a,mid);
            if(days <= d){
                ans = mid; r = mid -1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};