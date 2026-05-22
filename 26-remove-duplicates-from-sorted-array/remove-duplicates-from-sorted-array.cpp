class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 1;
        int i = 1, j =1;
        while(i < n && a[i] != a[i-1]){ i++; j++;};
        while(i < n){
            while(i < n && a[i] == a[i-1]) i++;
            if(i < n){
                a[j] = a[i];
                j++; i++;
            }
        }
        return j;
    }
};