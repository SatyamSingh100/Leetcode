class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(),n2 = b.size();
        int i=0,j=0,cnt=0;
        int idx1 = ((n1+n2)/2) - 1, idx2 = (n1+n2)/2;
        double el1 = 0, el2 = 0;
        while(i < n1 && j < n2){
            if(a[i] > b[j]){
                if(cnt == idx1) el1 = b[j];
                if(cnt == idx2) el2 = b[j];
                j++; cnt++;
            }
            else{
                if(cnt == idx1) el1 = a[i];
                if(cnt == idx2) el2 = a[i];
                i++; cnt++;
            }
        }
        while(i < n1){
            if(cnt == idx1) el1 = a[i];
            if(cnt == idx2) el2 = a[i];
            i++; cnt++;
        }
        while(j < n2){
            if(cnt == idx1) el1 = b[j];
            if(cnt == idx2) el2 = b[j];
            j++; cnt++;
        }
        if((n1+n2) & 1) return el2;
        return (el1+el2)/2;
    }
};