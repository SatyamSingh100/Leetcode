class Solution {
public:
    int numOfUnplacedFruits(vector<int>& a, vector<int>& b) {
        int n = a.size(),i=0,cnt=n;
        vector<int> check(n,0);
        while(i < n){
            for(int j=0; j<n; j++){
                if(check[j] == 0 && b[j] >= a[i]){
                    check[j] = 1; cnt--; break;
                }
            }
            i++;
        }
        return cnt;
    }
};