class Solution {
public:
    vector<int> sumZero(int n) {
        int val = -n / 2;
        vector<int> ans;
        if(n & 1){
            for(int i=0; i<n; i++){
                ans.push_back(val++);
            }
        }
        else{
            for(int i=0; i<=n; i++){
                if(val == 0) val++;
                else ans.push_back(val++);
            }
        }
        return ans;
    }
};