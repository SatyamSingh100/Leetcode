class Solution {
public:
    int AtMostK(vector<int>& a, int k){
        int n= a.size();
        unordered_map<int,int> m;
        int i=0,j=0,cnt=0;
        while(j < n){
            m[a[j]]++;
            while(m.size() > k && i < n){
                m[a[i]]--;
                if(m[a[i]] == 0) m.erase(a[i]);   i++;
            }
            if(m.size() <= k) cnt += (j-i+1);
            
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n = a.size();
        int ans = AtMostK(a,k);
        int ans2 = AtMostK(a,k-1);
        return ans-ans2;
    }
};