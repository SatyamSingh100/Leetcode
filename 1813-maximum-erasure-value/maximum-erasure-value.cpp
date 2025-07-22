class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size(),sum=0,ans=0,st=0;
        // unordered_map<int,int> m;
        // vector<int> pre(n+1,0);
        // pre[0] = 0;
        // for(int i=0; i<n; i++){
        //     pre[i+1] = pre[i] + a[i]; 
        // }
        // for(int i=0; i<n; i++){
        //     if(m.find(a[i]) == m.end()){
        //         sum += a[i]; m[a[i]] = i+1;
        //     }
        //     else{
        //         if(st > m[a[i]]){
        //             sum += a[i]; m[a[i]] = i+1;
        //         }
        //         else{
        //             sum += a[i];
        //             sum -= (pre[m[a[i]]] - pre[last]); 
        //             st = m[a[i]];  m[a[i]] = i+1;
        //         }
        //     }
        //     ans = max(ans,sum);
        // }
        // return ans;

        unordered_set<int> s;
        for(int i=0; i<n; i++){
            if(s.find(a[i]) == s.end()){
                sum += a[i]; s.insert(a[i]);
            }
            else{
                while(a[st] != a[i]){
                    s.erase(a[st]); sum -= a[st];
                    st++;
                }
                s.erase(a[st]); sum -= a[st]; st++;
                sum += a[i]; s.insert(a[i]);
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};