class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<string> s1,s2;
        int k=0;
        while(k < v1.size()){
            string s = "";
            if(v1[k] == '.'){
                k++; continue;
            }
            else{
                while(v1[k] != '.' && k < v1.size()){
                    s += v1[k];
                    k++;
                }
                s1.push_back(s);
            }
        }
        k = 0;
        while(k < v2.size()){
            string s = "";
            if(v2[k] == '.'){
                k++; continue;
            }
            else{
                while(v2[k] != '.' && k < v2.size()){
                    s += v2[k];
                    k++;
                }
                s2.push_back(s);
            }
        }
        vector<int> a1,a2;
        for(int i=0; i<s1.size(); i++){
            int l =0;
            while(s1[i][l] == '0' && l < s1[i].size()-1) l++;
            string st = "";
            if(l < s1[i].size()){
            for(int j=l; j<s1[i].size(); j++) st += s1[i][j];
            int num = stoi(st);
            a1.push_back(num);
            }
        }
        for(int i=0; i<s2.size(); i++){
            int l =0;
            while(s2[i][l] == '0' && l < s2[i].size() -1) l++;
            string st = "";
            if(l < s2[i].size()){
            for(int j=l; j<s2[i].size(); j++) st += s2[i][j];
            int num = stoi(st);
            a2.push_back(num);
            }
        }
        if(a1.size() > a2.size()){
            for(int i=a2.size(); i<a1.size(); i++) a2.push_back(0);
        }
        else{
            for(int i=a1.size(); i<a2.size(); i++) a1.push_back(0);
        }
        for(int i=0; i<a1.size(); i++){
            if(a1[i] > a2[i]) return 1;
            else if(a1[i] < a2[i]) return -1;
        }
        return 0;
    }
};