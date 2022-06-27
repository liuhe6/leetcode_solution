/*
 * 以下两种分界方式有不同的复杂程度，由于题目要求target不一定在nums中，所以大于等于target是本题的需求
 * 如果按照小于等于target的位置然后+1的搜索方式来计算，需要考虑更多的边界问题
 * */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || nums.back() < target) return nums.size();
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || nums.back() < target) return nums.size();
        if(nums.front() > target) return 0;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if(nums[l] == target ) return l;
        else return l + 1;
    }
};
