class Solution {
public: 
    bool isFound(int num,vector<int>& a,int n){
        for(int i=0; i<a.size(); i++){
            if(a[i] > (n*n)) break;
            if(a[i] == num) return true;
        }
        return false;
    }
    int countTriples(int n) {
        vector<int> a;
        for(int i=1; i<=250; i++){
            int num = i * i;
            a.push_back(num);
        }
        int cnt=0;
        for(int i=0; i<a.size()-1; i++){
            for(int j= i+1; j<a.size(); j++){
                int n1 = a[i], n2 = a[j];
                int num = n1 + n2;
                if(isFound(num,a,n)) cnt++;
            }
        }
        return cnt*2;
    }
};