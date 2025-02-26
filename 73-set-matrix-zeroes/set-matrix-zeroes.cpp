class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m= a.size();
        int n = a[0].size();
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == 0){
                    m1[i]++;
                    m2[j]++;
                }
            }
        }
        for(auto it: m1){
            int num = it.first;
            for(int j=0; j<n; j++) a[num][j] =0;
        }
        for(auto it: m2){
            int num = it.first;
            for(int i=0; i<m; i++) a[i][num] =0;
        }
        cout<<"[";
        for(int i=0; i<m; i++){
            cout<<"[";
            for(int j=0; j<n; j++){
                cout<<a[i][j];
                if(j!=n-1) cout<<",";
            }
            cout<<"]";
            if(i!= m-1) cout<<",";
        }
    }
};