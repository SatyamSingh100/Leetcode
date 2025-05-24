class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int piv = -1;
        for(int i= n-2; i>=0; i--){
            if(a[i] < a[i+1]){
                piv = i; break;
            }
        }
        if(piv == -1) {
            reverse(begin(a),end(a));
            return;
        }

        for(int i= n-1; i>piv; i--){
            if(a[i] > a[piv]){
                swap(a[i],a[piv]);
                break;
            }
        }
        sort(a.begin() + piv+1, a.end());
    }
};