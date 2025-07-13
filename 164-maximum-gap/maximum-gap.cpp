class Solution {
public:
    int maximumGap(vector<int>& a) {
        int ans = 0;
        sort(begin(a),end(a));
        if(a.size() == 1) return 0;
        for(int i=1; i<a.size(); i++){
            int num = a[i] - a[i-1];
            ans = max(ans,num);
        }
        return ans;
    }
};