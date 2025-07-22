class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size(),sum=0,ans=0,last=0;
        unordered_map<int,int> m;
        vector<int> pre(n+1,0);
        pre[0] = 0;
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + a[i]; 
        }
        for(int i=0; i<n; i++){
            if(m.find(a[i]) == m.end()){
                sum += a[i]; m[a[i]] = i+1;
            }
            else{
                if(last > m[a[i]]){
                    sum += a[i]; m[a[i]] = i+1;
                }
                else{
                    sum += a[i];
                    sum -= (pre[m[a[i]]] - pre[last]); 
                    last = m[a[i]];  m[a[i]] = i+1;
                }
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};