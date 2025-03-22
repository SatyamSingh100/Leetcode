class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int n=a.size();
        vector<int> v(n+1);
        a[n-1] += 1;
        bool found = false;
        if(a[n-1] == 10){
            int i= n-1;
            while(a[i] == 10 && i>0){
                a[i] = 0;
                a[i-1] += 1;
                i--;
                if(i == 0) found = true;
            }
        }
       for(int i=0; i<n; i++){
        if(a[i] == 10){
            a[i] = 1;
            a.insert(a.begin() + i+1, 0);
        }
       }
        return a;
    }
};