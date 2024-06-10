class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            // q中记录的是nums中的索引值, 这样才方便计算是否需要将队列中的元素弹出;
            if(q.size() && i - k + 1 > q.front()) q.pop_front();
            // 维护一个双端队列, 使得队列的front永远都是窗口中的最大值, 且递减; 
            // 如果新加入的值nums[i]比队列中已有的值大, 则将队列中比nums[i]小的值从队尾弹出;
            while(q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            // 这里注意需要判断是否已经有完整的窗口
            if(i >= k - 1)res.push_back(nums[q.front()]);
        }
        return res;
    }
};
