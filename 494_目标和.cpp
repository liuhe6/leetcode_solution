// 全体数字的和sum-target = 2neg，问题退化为01背包问题，即从数字中寻找和为neg的组合
// 下列为01背包问题进行状态压缩之后的解法
// 为什么要倒序？因为两层循环，每次更新状态实际上是使用的外层循环上一次的值，内层循环倒序，可以避免使用外层循环本次过程中的值
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums) sum += n;
        int diff = sum - target;
        if(diff < 0 || diff % 2 != 0) return 0;
        int neg = diff / 2;
        vector<int> f(neg + 1);
        f[0] = 1;
        for(auto& x : nums) {
            for(int j = neg; j >= x; j--) {
                f[j] = f[j] + f[j - x];
            }
        }
        return f[neg];
    }
};


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
