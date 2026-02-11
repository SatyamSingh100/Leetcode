class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int n = a.size();
        int i =0,ans=0;
        while(i < n-1){
            unordered_map<int,int> odd,even;
            if(a[i] & 1) odd[a[i]]++;
            else even[a[i]]++;
            int j = i+1;
            while(j < n){
                if(a[j] & 1) odd[a[j]]++;
                else even[a[j]]++;
                if(odd.size() == even.size()) ans = max(ans,j-i+1);
                j++;
            }
            i++;
        }
        return ans;
    }
};