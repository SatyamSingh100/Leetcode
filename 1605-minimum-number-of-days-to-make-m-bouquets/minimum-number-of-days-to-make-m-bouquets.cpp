class Solution {
public:
    int f1(vector<int>& a, int k, int d){
        long long sum =0,cnt=0;
        for(int i=0; i<a.size(); i++){
            bool check = true;
            if(a[i] <= d) cnt++;
            else check = false;
            if(cnt == k){
                sum++; check = false;
            }
            if(!check) cnt = 0;
        }
        return sum;
    }
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        long long  l = *min_element(a.begin(),a.end()), r = *max_element(a.begin(),a.end());
        long long ans = 1e9 + 11;
        while(l <=  r){
            long long mid = (l+r)/2;
            long long num = f1(a,k,mid);
            if(num >= m){
                ans = min(ans,mid); r = mid -1;
            }
            else l = mid + 1;
        }
        if(ans == 1e9 + 11) ans = -1;
        return ans;
    }
};