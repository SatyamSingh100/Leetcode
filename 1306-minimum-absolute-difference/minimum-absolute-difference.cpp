class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        int n = a.size(),mini=1e9;
        sort(a.begin(),a.end());
        for(int i=0; i<n-1; i++){
            int diff = a[i+1] - a[i];
            mini = min(mini,diff);
        }
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++){
            if(a[i+1] - a[i] == mini){
                vector<int> v = {a[i],a[i+1]};
                ans.push_back(v);
            }
        }
        return ans;
    }
};