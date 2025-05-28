class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        // for(int i=1; i<=n; i++){
        //     string temp = "",curr = s;
        //     for(int j=0; j<i; j++) temp += curr[j];
        //     for(int j=0; j<(n-i); j++) curr[j] = curr[j+i];
        //     int idx=0;
        //     for(int j = n-i; j<n; j++) curr[j] = temp[idx++];
        //     if(curr == goal) return true;
        // }
        // return false;

         s = s+s;
        for(int i=0; i<=n; i++){
            string g = s.substr(i,n);
            if(g == goal) return true;
        }
        return false;
    }
};