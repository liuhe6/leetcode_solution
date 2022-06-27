class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        vector<int> f(max, max);
        //当总额为0的时候，就是一个都不拿
        f[0] = 0;
        for(int n : coins) {
            for(int v = n; v <= amount; v ++) {
                // 这里状态是最小值
                f[v] = min(f[v], f[v - n] + 1);
            }
        }
        if(f[amount] == max) return -1;
        return f[amount];
    }
};
