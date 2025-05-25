class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int tar) {
        int n = a.size();
        vector<vector<int>> ans;
        sort(begin(a),end(a));                                    //Sort the array as we r doin the optimal one
        
        for(int i=0; i<n; i++){
            if(i > 0 && a[i] == a[i-1]) continue;                 //Check for ith index
            for(int j=i+1; j<n; j++){
                if(j > i+1 && a[j] == a[j-1]) continue;           //For jth as well...
               //Initialise those 2 moving pointers
                int k=j+1, l = n-1;
                while(k<l){
                    long long sum = a[i];   sum += a[j];
                    sum += a[k];  sum += a[l];
                    if(sum < tar) k++;
                    else if(sum > tar) l--;
                    else{
                        vector<int> v = {a[i],a[j],a[k],a[l]};                 //Store in a vec 
                        ans.push_back(v);
                        k++;  l--;

                        while(k<l && a[k] == a[k-1]) k++;             //And checking dups for k and l 
                        while(k<l && a[l] == a[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};