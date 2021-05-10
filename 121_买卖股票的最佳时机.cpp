class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, res = 0;
        for(auto n : prices) {
            res = max(res, n - min);
            if(n < min) min = n;
        }
        return res;
    }
};