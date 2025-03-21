class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(a[i][j],a[j][i]);
            }
        }
        for(int i=0; i<n; i++){
           reverse(a[i].begin(),a[i].end());
        }
        for(auto it:a){
            for(auto elem: it){
                cout<<elem<<" ";
            }
        }
        // cout<<endl;
    }
};