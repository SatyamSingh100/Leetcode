class Solution {
public:
    vector<int> rotateElements(vector<int>& a, int k) {
        int n = a.size();
        vector<int> p;
        for(int i=0; i<n; i++){
            if(a[i] >=0) p.push_back(a[i]);
        }
        if(p.size() == 0) return a;
        vector<int> copy = p;
        k = k % p.size();
        int l=0,num=k;
        for(int i=p.size()-k; i<p.size(); i++) p[i] = copy[l++];
        for(int i=0; i<p.size()-k; i++) p[i] = copy[num++];
        l = 0;
        for(int i=0; i<n; i++){
            if(a[i] >= 0) a[i] = p[l++];
        }
        return a;
    }
};