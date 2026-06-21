class Solution {
public:
    int myAtoi(string a) {
        int n = a.size();
        long long num = 0,i=0;
        bool sign = true;
        while(i < n){
            while(i < n && a[i] == ' ') i++;
            if(a[i] == '-' || a[i] == '+'){
                sign = (a[i] == '-')? false : true;
                i++;
            }
            while(i < n && a[i] >= 48 && a[i] <= 57){
                num = (num*10) + (a[i] - '0');

                if(num >= INT_MAX){
                    if(num > INT_MAX && sign == false) num = INT_MIN;
                    else num = INT_MAX;
                    break;
                }
                i++;
            }
            if(num == INT_MAX || num == INT_MIN) break;
            if((a[i] >= 65 && a[i] <= 90) || (a[i] >=97 && a[i] <= 122) || (a[i] == '-') || (a[i] == '+')||(a[i] == ' ' || a[i] == '.')) break; 
        }
        if(sign == false && (num != INT_MAX || num != INT_MIN)) num = -num;
        // if(num < INT_MIN) num = INT_MIN;
        // else if(num > INT_MAX) num = INT_MAX;
        return num;
    }
};