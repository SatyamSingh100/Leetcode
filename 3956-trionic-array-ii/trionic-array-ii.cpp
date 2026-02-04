class Solution {
public:
    long long maxSumTrionic(vector<int>& a) {
        long long n = a.size(),ans=-1e18;
        vector<vector<long long>> v;
        long long l =0;
        for(int i=1; i<n; i++){
            if(a[i] == a[i-1]){
                v.push_back({0,l,i}); l =i;
            }
            else if(a[i] > a[i-1]){
                if(i == n-1){
                    v.push_back({1,l,n-1}); l = n-1;
                }
                else if(a[i] == a[i+1]){
                  v.push_back({1,l,i}); l = i;
                }
                else if(a[i] > a[i+1]){
                    v.push_back({1,l,i});  l = i;
                }
            }
            else if(a[i] < a[i-1]){
                if(i == n-1){
                v.push_back({-1,l,i});  l = i;
                }
                else if(a[i] == a[i+1]){
                  v.push_back({-1,l,i}); l = i;
                }
                else if(a[i] < a[i+1]){
                    v.push_back({-1,l,i});  l = i;
                }
            }
        }

        unordered_map<long long,long long> pref,suff;
        for(int i=0; i<v.size(); i++){
            if(v[i][0] == 1){
                int l1 = v[i][1], r1 = v[i][2];
                long long sum=a[r1]+ a[r1-1],sum2=a[l1] + a[l1+1];
                int j = r1-2;
                while(j >= max(l1,0) && a[j] > 0){
                    sum += a[j]; j--;
                }
                long long num = sum2;
                for(int k = l1+2; k<=r1; k++){
                    num += a[k];  sum2 = max(sum2,num);
                }
                suff.insert({l1,sum2});
                pref.insert({r1,sum});
            }
        }
        for(int i=1; i<=v.size()-2; i++){
            if(v[i-1][0] == 1 && v[i][0] == -1 && v[i+1][0] ==  1){
                long long num =0,l1=v[i][1],r1=v[i][2];
                for(int j=l1; j<=r1; j++) num += a[j];
                num -= a[l1]; num -= a[r1];
                num += pref[l1]; num += suff[r1];
                ans = max(ans,num);
            }
        }
        return ans;
    }
};