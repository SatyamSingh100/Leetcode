class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(x == y && y == z) return 0;
        if((y > x && y < z) || (y > z && y < x)) return 2;
        else if((x > y && x < z) || (x > z && y > x)) return 1;
        else{
            int n1 = abs(z-x), n2 = abs(z-y);
            if(n1 == n2) return 0;
            return ((n1 > n2) ? 2 : 1 );
        }
        return 0;
    }
};