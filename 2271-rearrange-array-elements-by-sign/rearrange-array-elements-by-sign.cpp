class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size();
        int k_odd = 0, k_even = 1;
        vector<int> ans = a;
        for(int i=0; i<n; i++){
            if(a[i] > 0){
                ans[k_odd] = a[i]; k_odd += 2;
            }
            else {
                ans[k_even] = a[i]; k_even += 2;
            }
        }
        return ans;
    }
};