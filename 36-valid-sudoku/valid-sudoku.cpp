class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        int n = a.size(),p=0;
        
        for(int i=0; i<9; i++){
            unordered_set<char> row;
            for(int j=0; j<9; j++){
                if(a[i][j] != '.'){
                if(row.find(a[i][j]) != row.end()) return false;
                row.insert(a[i][j]);
                }
            }
        }

        for(int j=0; j<9; j++){
            unordered_set<char> col;
            for(int i=0; i<9; i++){
                if(a[i][j] != '.'){
                if(col.find(a[i][j]) != col.end()) return false;
                col.insert(a[i][j]);
                }
            }
        }
        for(int p=0; p<3; p++){
        for(int k=0; k<3; k++){
            unordered_set<char> val;
            for(int i=(3*k); i<(3*(k+1)); i++){
                for(int j=(3*p); j<(3*(p+1)); j++){
                    if(a[i][j] != '.'){
                    if(val.find(a[i][j]) != val.end()) return false;
                    val.insert(a[i][j]);
                    }
                }
            }
        }
        }
        return true;
    }
};