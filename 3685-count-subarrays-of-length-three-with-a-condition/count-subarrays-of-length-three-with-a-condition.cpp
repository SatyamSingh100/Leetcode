class Solution {
public:
    int countSubarrays(vector<int>& a) {
        int n= a.size(),cnt=0;
        for(int i=0; i<n-2; i++){
            if(a[i+1] == 2*(a[i] + a[i+2])) cnt++;
        }

        return cnt;
    }
};