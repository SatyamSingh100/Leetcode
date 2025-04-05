class Solution {
public:
    void f(vector<int>& a, int idx, vector<int>& curr, vector<vector<int>>& ans){
        if(idx == a.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(a[idx]);
        f(a,idx+1,curr,ans);
        curr.pop_back();
        f(a,idx+1,curr,ans);
    }
    int subsetXORSum(vector<int>& a) {
        int n = a.size();
        vector<int> curr;
        vector<vector<int>> ans;
        f(a,0,curr,ans);
        int sum = 0;
        for(int i=0; i<ans.size(); i++){
            int num =0;
            for(int j=0; j<ans[i].size(); j++){
                num = num^ans[i][j];
            }
            sum += num;
        }
        return sum;
    }
};