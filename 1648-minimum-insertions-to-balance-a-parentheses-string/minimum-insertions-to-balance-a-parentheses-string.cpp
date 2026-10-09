class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(),cost=0;
        string st = "";
        for(int i=0; i<n; i++){
            if(s[i] == '(') st += s[i];
            else{
                st += ')';
                if(i == n-1) cost++;
                else if(s[i+1] == '(') cost++;
                else i++;
            }
        }
        stack<char> s1;
        n = st.size();
        for(int i=st.size()-1; i>=0; i--){
            if(st[i] == ')') s1.push(st[i]);
            else{
                if(s1.empty()) cost+=2;
                else s1.pop();
            }
        }
        cost += s1.size();
        return cost;
    }
};