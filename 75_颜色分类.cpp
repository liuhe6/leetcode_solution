class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 用三个指针维护状态,0->j-1之前的为0, k之后的为2, j到i为1
        for(int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            if(nums[i] == 0) swap(nums[i++], nums[j++]);
            else if(nums[i] == 2) swap(nums[k--], nums[i]);
            else i++;
        }
    }
};
