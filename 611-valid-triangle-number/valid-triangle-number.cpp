class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n=a.size(),i=0,cnt=0;
        sort(a.begin(),a.end());
        if(n <= 2) return 0;
        while(i < n-2){
        int j = i+1;
        while(j<n-1){
            int k = j+1;
            while(k<n && a[k] < a[i] + a[j]){
                k++; cnt++;
            }
            j++;
        }
        i++;
        }
        return cnt;
    }
};