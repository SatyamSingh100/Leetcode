class Solution {
public:
    void f1(vector<int>& a, int idx, int sum, vector<int>& b, vector<vector<int>>& c){
        int n =a.size();
        if(sum == 0){
            c.push_back(b);
            return;
        }
        if(sum < 0 || idx == n) return;

        for(int i= idx; i<n; i++){
            if(i > idx && a[i] == a[i-1]) continue;
            if(a[i] > sum) break;

            b.push_back(a[i]);
            f1(a,i+1,sum - a[i], b, c);
            b.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int tar) {
        sort(a.begin(),a.end());
        vector<int> b;
        vector<vector<int>> c;
        f1(a,0,tar,b,c);
        return c;
    }
};