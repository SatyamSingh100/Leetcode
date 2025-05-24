class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        int posi = 0,negi = 1;
        for(int i=0; i<n; i++){
            if(a[i] > 0){
                ans[posi] = a[i];   posi += 2;
            }
            else if(a[i] < 0){
                ans[negi] = a[i],  negi+= 2;
            }
        }
        return ans;
    }
};