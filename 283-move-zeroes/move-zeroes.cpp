class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size(),i=0,j=0;
        while(i < n && j < n){
        while(i < n && a[i] == 0) i++;
        while(j < n && a[j] != 0) j++;
        if(i >= n || j >= n) break;
        if(j < i){
            swap(a[i],a[j]);
            i++; j++;
        }
        else i++;
        }
        // return a;
    }
};