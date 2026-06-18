class Solution {
public:
    void f1(vector<int>& a, int idx, int sum, vector<int>& b,vector<vector<int>>& c){
        if(sum == 0){
            c.push_back(b); return;
        }
        if(sum < 0 || idx == a.size()) return;
        
        b.push_back(a[idx]);
        f1(a,idx+1,sum - a[idx], b,c);
        b.pop_back();
        f1(a,idx+1,sum,b,c);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a ={1,2,3,4,5,6,7,8,9};
        vector<int> b;
        vector<vector<int>> c,ans;
        f1(a,0,n,b,c);
        for(auto it: c){
            if(it.size() == k) ans.push_back(it);
        }
        return ans;
        
    }
};