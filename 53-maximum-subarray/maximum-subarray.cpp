class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        int cur_sum = 0, max_sum = -1e9;
        for(int i=0; i<n; i++){
            cur_sum += a[i];
            max_sum = max(max_sum , cur_sum);
            if(cur_sum < 0 ) cur_sum = 0;
        }
        return max_sum;
    }
};