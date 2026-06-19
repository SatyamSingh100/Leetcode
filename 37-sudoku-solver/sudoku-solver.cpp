class Solution {
public:
    bool isValid(vector<vector<char>>& a, int n1, int n2, int num){
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i][n2] == (num + '0')) return false;
        }
        for(int j=0; j<n; j++){
            if(a[n1][j] == num + '0') return false;
        }
        int row = (n1/3)*3, col = (n2/3)*3;

        for(int i=row; i<row+3; i++){
            for(int j=col; j<col+3; j++){
                if(a[i][j] == num + '0') return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>& a, int i,int j){
        int n = a.size();
        if(i == 9){
            return true;
        }
        if(j == 9){
            return f(a,i+1,0);
        }
        if(a[i][j] != '.') return f(a,i,j+1);
        
            for(int k = 1; k<=9; k++){
                if(isValid(a,i,j,k)){
                    char c = k + '0';
                    a[i][j] = c;
                    if(f(a,i,j+1)) return true;
                    a[i][j] = '.';
                }
            }

        return false;
    }
    void solveSudoku(vector<vector<char>>& a) {
        int n = a.size();
        f(a,0,0);
    }
};