class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        int i=n1-1, j = n2-1,car=0;
        string s ="";
        while(i >=0  && j >= 0){
            int num = (a[i] - '0') + (b[j] - '0') + car;
            if(num <= 1){
                s.push_back(num+48); car =0;
            }
            else{
                s.push_back((num%2) + 48);   car = 1;
            }
            i--; j--;
        }
        while(i >= 0){
            int num = (a[i] - '0') + car;
            if(num <= 1){
                s.push_back(num+48); car =0;
            }
            else{
                s.push_back((num%2) + 48);   car = 1;
            }
            i--;
        }
        while(j >= 0){
            int num = (b[j] - '0') + car;
            if(num <= 1){
                s.push_back(num+48); car =0;
            }
            else{
                s.push_back((num%2) + 48);   car = 1;
            }
            j--;
        }
        if(car > 0) s.push_back(car+48);
        reverse(s.begin(),s.end());
        return s;
    }
};