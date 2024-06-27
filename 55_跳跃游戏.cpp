class Solution {
public:
    bool canJump(vector<int>& nums) {
        // i是当前位置，j是前i-1个位置能跳到最远的位置
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(j < i) return false;
            j = max(j, nums[i] + i);
        }
        return true;
    }
};
