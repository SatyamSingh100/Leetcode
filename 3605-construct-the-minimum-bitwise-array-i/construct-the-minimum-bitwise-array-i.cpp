class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            int num = a[i],cnt=0;
            while(num > 1){
                num = num/2; cnt++;
            }
            for(int j=cnt; j>=0; j--){
                int val = a[i] - (1 << j);
                if((val | (val+1)) == a[i]) ans[i] = val;
                if(ans[i] != -1) break;
            }
        }
        return ans;
    }
};