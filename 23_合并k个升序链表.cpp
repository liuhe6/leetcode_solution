class Solution {
public:
    struct Cmp {
        bool operator() (ListNode* a, ListNode* b) {
          // 小顶堆, 要用大于号
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        for(auto l : lists) if(l) heap.push(l);
        while(heap.size()) {
            auto t = heap.top();
            heap.pop();
            cur->next = t;
            cur = cur->next;
            if(t->next) heap.push(t->next);
        }
        return dummy->next;
    }
};
