class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums) sum += n;
        int diff = sum - target;
        if(diff < 0 || diff % 2 != 0) return 0;
        int neg = diff / 2;
		// 状态定义  其中dp[i][j] 表示在数组nums的前i个数中选取元素，使得这些元素之和等于j的方案数
        vector<vector<int>> dp(nums.size() + 1, vector<int>(neg + 1));
		// 状态初始化，只有在0个元素，和为0的时候，存在1种方案；和为其他值的时候，0个元素，只有0个方案;
        dp[0][0] = 1;
        for(int i = 1; i <= nums.size(); i++) {
            int n = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
				// 不选当前i
                dp[i][j] = dp[i - 1][j];
				// 当前元素小于和的值，且选中它
                if( n <= j) {
                    dp[i][j] += dp[i - 1][j - n];
                }
            }
        }
        return dp[nums.size()][neg];
    }
};
