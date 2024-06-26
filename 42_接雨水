class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;     // 创建一个栈来存储柱子的索引
        int res = 0;        // 初始化接雨水的总量为 0

        // 遍历每个柱子
        for (int i = 0; i < height.size(); i++) {
            int last = 0;   // 初始化当前柱子和栈顶柱子之间的雨水高度为 0

            // 当栈非空且当前柱子高度大于栈顶柱子高度时
            while (stk.size() && height[stk.top()] <= height[i]) {
                // 计算接雨水的量，更新总量
                res += (height[stk.top()] - last) * (i - stk.top() - 1);
                last = height[stk.top()];   // 更新雨水高度
                stk.pop();                  // 弹出栈顶柱子
            }

            // 说明当前柱子小于栈顶元素
            if (stk.size()) {
                // 计算接雨水的量，更新总量
                res += (i - stk.top() - 1) * (height[i] - last);
            }
            stk.push(i);    // 将当前柱子索引入栈
        }
        return res;
    }
};
