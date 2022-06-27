class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r) {
            int mid = l + (long long)r + 1 >> 1;
            if(mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
