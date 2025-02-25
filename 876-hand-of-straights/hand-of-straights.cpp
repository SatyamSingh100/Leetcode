class Solution {
public:
    bool isNStraightHand(vector<int>& a, int k) {
        int n=  a.size();
        map<int,int> m;
        if(n % k != 0) return false;
        for(int i=0; i<n; i++){
            if(m.find(a[i])== m.end()) m[a[i]] =1;
            else m[a[i]]++;
        }
        // int cnt=0;
        while(!m.empty()){
            int curr = m.begin()->first;
            for(int i=0; i<k; i++){
                if(m[curr+i] == 0) return false;
                m[curr+i]--;
                if(m[curr+i] == 0) m.erase(curr+i);
            }
        }
        return true;
    }
};