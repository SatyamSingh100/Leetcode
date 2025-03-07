class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = 1e6;
        vector<bool> v(n+1,true);
        vector<int> ans,lamine,a;
        int ans1=-1,ans2=-1,last=1e9;
        lamine.push_back(ans1);
        lamine.push_back(ans1);

        v[0] =false, v[1] = false;
        for(int i=2; i<=n; i++){
            if(v[i] == true){
                for(int j=(2*i); j<= n; j+= i){
                    v[j] = false;
                }
            }
        }

        for(int i=0; i<v.size(); i++){
            if(v[i] == 1) ans.push_back(i);
        }
        for(int i=0; i<ans.size(); i++){
            if(ans[i] >= left && ans[i] <=right) a.push_back(ans[i]);
        }

        if(a.size() < 2) return lamine;

    lamine.pop_back();
    lamine.pop_back();

        for(int i=0; i<a.size()-1; i++){
            int num1 = a[i],num2 = a[i+1];
            int curr = num2 - num1;  
            if(curr < last) {
                ans1 = num1; ans2 = num2;
            }
            last = min(last,curr);
        }
        
        lamine.push_back(ans1);
        lamine.push_back(ans2);
        return lamine;
    }
};