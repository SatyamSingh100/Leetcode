class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int k) {
        int n = a.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int st = max(i-k,0),end = min(i+k,n-1);
            for(int j = st; j<=end; j++){
                if(a[j] == key){
                    ans.push_back(i); break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};