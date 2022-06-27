/*
 * 二分的是[1, n]的区间，不是nums！！！！！！*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;
        while(l < r) {
            int mid = l + r >> 1;
            int cnt = 0;
            for(int x : nums) {
                if(x <= mid && x >= l) {
                    cnt ++;
                }
            }
            if(cnt > mid - l + 1) {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
