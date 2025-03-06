class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        int n = a.size();
        vector<bool> v((n*n)+1,false);
        v[0] = true;
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int num = a[i][j];
                v[num] = true;
                m[num]++;
            }
        }
        for(auto it: m){
            int num1 = it.first, num2 = it.second;
            if(num2 == 2) ans.push_back(num1);
        }
        for(int i=0; i<v.size(); i++){
            if(v[i] == false) ans.push_back(i);
        }
        return ans;
    }
};