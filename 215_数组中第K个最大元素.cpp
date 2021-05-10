class Solution {
public:
    int quick_sort(vector<int>& nums, int l, int r, int k) {
        if(l == r) return nums[k];
        // int i = l, j = r, x = nums[l];
        // while(i < j) {
        //     while( i < j && nums[i] > x) i++;
        //     while( i < j && nums[j] < x) j--;
        //     if(i < j) swap(nums[i], nums[j]);
        // }
        int i = l - 1, j = r + 1, x = nums[l];
        while(i < j) {
            do i++ ;while(nums[i] > x);
            do j-- ;while(nums[j] < x);
            if(i < j) swap(nums[i], nums[j]);
        }
        if(k <= j) return quick_sort(nums, l, j, k);
        else return quick_sort(nums, j + 1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k - 1);
    }
};