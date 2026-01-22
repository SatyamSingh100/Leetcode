class Solution {
public:
    bool isInc(vector<int>& a){
        int n=  a.size();
        for(int i=0; i<n-1; i++){
            if(a[i+1] < a[i]) return false; 
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        while(isInc(a) == false){
            int sum = a[0] + a[1], idx =0;
            for(int i=1; i<a.size()-1; i++){
            if(a[i] + a[i+1] < sum){
                sum = a[i] + a[i+1];
                idx =i;
            }
            }
            a.erase(a.begin()+idx,a.begin()+idx+1);
            a[idx] = sum;
            cnt++;
        }
        return cnt;
        

    }
};