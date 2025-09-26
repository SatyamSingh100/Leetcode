class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n=a.size(),i=0,cnt=0;
        sort(a.begin(),a.end());
        if(n <= 2) return 0;
        for(int i=n-1; i>=2; i--){
            int l=0,r=i-1;
            while(l<r){
                int sum = a[l] + a[r];
                if(sum > a[i]){
                    cnt += (r-l);
                    r--;
                }
                else l++;
            }
        }
        return cnt;
    }
};