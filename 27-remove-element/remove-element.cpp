class Solution {
public:
    int removeElement(vector<int>& a, int k) {
        int idx=0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != k){
                a[idx++] = a[i];
            }
        }
        return idx;
    }
};