class Solution {
public:
    int maxSum(vector<int>& a) {
        int n = a.size(),curr=0,maxi=-1e9;
        vector<int> ans;
        set<int> s;
        for(int i=0; i<n; i++){
            if(s.find(a[i]) == s.end()){
            ans.push_back(a[i]);
            s.insert(a[i]);
            }
        }
        if(ans.size() == 1) return ans[0];
        for(int i=0; i<ans.size(); i++){
            if(maxi >= 0){
                if(ans[i] > 0) curr += ans[i];
                maxi = max(maxi,curr);
            }
            else{
                curr += ans[i]; maxi = max(maxi,curr);
                if(curr < 0) curr =0;
            }
        }
        return maxi;
    }
};