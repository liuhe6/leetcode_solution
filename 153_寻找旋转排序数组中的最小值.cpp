/* 需要特判未发生旋转的时候
 */

/* 又是一个不同判断条件，最终复杂程度不一样的二分题目！
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r ) {
            int mid = l + r >> 1;
            if(nums[mid] <= nums.back()) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums.back()) return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l < r ) {
            int mid = l + r >> 1;
            if(nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};
