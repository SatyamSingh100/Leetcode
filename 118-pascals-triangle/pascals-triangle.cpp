class Solution {
public:
    vector<int> f(int n){
    vector<int> ans;
    ans.push_back(1);
    for(int i=1; i<n; i++){
        ans.push_back((ans[i-1]*(n-i))/i);
    }
    return ans;
}
    vector<vector<int>> generate(int n) {
        vector<vector<int>> fAns;
        for(int i=0; i<n; i++){
            vector<int> ans = f(i+1);
            fAns.push_back(ans);
        }
        return fAns;
    }
};