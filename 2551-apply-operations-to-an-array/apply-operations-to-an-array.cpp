class Solution {
public:
    vector<int> applyOperations(vector<int>& a) {
        int n= a.size(),cnt=0;
        vector<int> v;
        for(int i=0; i<n-1; i++){
            if(a[i] == a[i+1]){
                a[i] = a[i] *2;
                a[i+1] = 0;
            }
        }
        for(int i=0; i<n; i++){
            if(a[i] == 0) cnt++;
            else v.push_back(a[i]);
        }
        for(int i=0; i<cnt; i++) v.push_back(0);
        return v;
    }
};