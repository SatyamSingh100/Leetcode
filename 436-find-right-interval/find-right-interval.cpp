class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& interv) {
        int n = interv.size();
        vector<vector<int>> a;
        for(int i=0; i<n; i++){
            int num1 = interv[i][0];
            a.push_back({num1,i});
        }
        vector<int> ans(n,-1);
        sort(a.begin(),a.end(), [](vector<int>& a1,vector<int>& b1){ return a1[0] < b1[0]; });
        for(int i=0; i<n; i++){
            int num = interv[i][1];
            int l =0,r=n-1;
            while(l <= r){
                int mid = (l + r)/2;
                if(num <= a[mid][0]){
                    ans[i] = a[mid][1]; r = mid - 1;
                }
                else l = mid + 1;
            }
        }
        return ans;
    }
};