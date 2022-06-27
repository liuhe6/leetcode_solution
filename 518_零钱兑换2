class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1);
        f[0] = 1;
        for(int n : coins) {
            for(int i = n; i <= amount; i++) {
                f[i] += f[i - n];
            }
        }
        return f[amount];
    }
};
