class Solution {
public:
    int countPairs(vector<int>& a, int k) {
        int n = a.size(),cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int idx=  i*j;
                if(idx % k == 0 && a[i] == a[j]) cnt++;
            }
        }
        return cnt;
    }
};