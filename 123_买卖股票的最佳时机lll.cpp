class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n + 1);
        // 状态为, 前i个元素, 收入最高的一次交易
        for(int i = 1, minp = INT_MAX; i <= n; i++) {
            f[i] = max(f[i - 1], prices[i - 1] - minp);
            minp = min(minp, prices[i - 1]);
        }
        // 从后向前遍历, 以i为第二次交易的买入, 维护一个i之后的最大值
        // 计算第一次交易的最大值 和第二次交易的值,取最大为结果
        int res = 0;
        for(int i = n, maxp = 0; i > 0; i-- ) {
            res = max(res, maxp - prices[i - 1] + f[i - 1]);
            maxp = max(maxp, prices[i - 1]);
        }
        return res;
    }
};
