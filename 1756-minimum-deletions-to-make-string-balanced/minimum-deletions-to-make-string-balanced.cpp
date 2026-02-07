class Solution {
public:
    int minimumDeletions(string a) {
        int n = a.size(),idxa=0,ansa=1e9,idxb=0,ansb=1e9;
        vector<int> pa,pb,qa,qb;
        for(int i=0; i<n; i++){
            if(a[i] == 'a') pa.push_back(i);
        }
        for(int i=0; i<pa.size(); i++){
            int num = pa[i] - idxa;
            qa.push_back(num);
            idxa++;
        }
        for(int i=qa.size()-1; i>=0; i--){
            int num = qa[i] + (qa.size()-1) - i;
            ansa = min(ansa,num);
        }
        if(ansa == 1e9) ansa = 0;

        reverse(a.begin(),a.end());
        for(int i=0; i<n; i++){
            if(a[i] == 'b') pb.push_back(i);
        }
        for(int i=0; i<pb.size(); i++){
            int num = pb[i] - idxb;
            qb.push_back(num);
            idxb++;
        }
        for(int i=qb.size()-1; i>=0; i--){
            int num = qb[i] + (qb.size()-1) - i;
            ansb = min(ansb,num);
        }
        if(ansb == 1e9) ansb = 0;
        
        int ans = min(ansa,ansb);
        return ans;
    }
};