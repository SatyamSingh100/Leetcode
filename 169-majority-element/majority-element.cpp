class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[a[i]]++;
        }
        for(auto it: m){
            int num1 = it.first,num2 = it.second;
            if(num2> n/2) return num1;
        }
        return -1;
    }
};