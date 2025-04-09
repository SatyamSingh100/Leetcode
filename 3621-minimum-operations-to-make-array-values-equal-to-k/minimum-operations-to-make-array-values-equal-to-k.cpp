class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        if(k > a[0]) return -1;
        else{
            unordered_set<int> s;
            for(int i=0; i<n; i++){
                if(s.find(a[i]) == s.end()) s.insert(a[i]);
            }
            int cnt = s.size() - 1;
            if(k == a[0]) return cnt;
            else return (cnt+1);
        }
        return -1;
    }
};