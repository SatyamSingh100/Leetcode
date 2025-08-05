class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        int n = a.size(),i=0,j=0,cnt=0;
        unordered_map<int,int> m;
        while(j < n){
            while((j-i) > k){
                m[a[i]]--;
                if(m[a[i]] == 0) m.erase(a[i]);
                i++;
            }
            if(m.find(a[j]) != m.end() && j != i) return true;
            m[a[j]]++;
            j++;
        }
        return false;
    }
};