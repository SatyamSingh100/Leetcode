class Solution {
public:
    int calculate(string s) {
        long long ans=0,num=0,sign=1,n=s.size();
        stack<long long> st;
        for(int i=0; i<n; i++){
            if(s[i] == '+' || s[i] == '-'){
                ans += (num * sign); sign = ( s[i] == '+' ? 1 : -1);
                num = 0;
            }
            else if(s[i] == '('){
                st.push(ans); 
                st.push(sign);
                ans = 0; num =0; sign = 1;
            }
            else if(s[i] == ')'){
                ans += (num * sign);
                    ans = ans * st.top();
                    st.pop();
                    ans += st.top();
                    st.pop();
                num =0;
            }
            else if(s[i] == ' ') continue;
            else{
                num = (num*10) + s[i] - '0';
            }
        }
        ans += num * sign;
        return ans;
    }
};