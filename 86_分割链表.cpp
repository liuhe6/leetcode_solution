class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      // 创建两个链表, 一个小于x, 一个大于x
        auto lh = new ListNode(-1), rh = new ListNode(-1);
        auto lt = lh, rt = rh;
        for(auto p = head; p; p = p->next) {
            if(p->val < x) lt = lt->next = p;
            else rt = rt->next = p;
        }
        rt->next = nullptr;
        lt->next = rh->next;
        return lh->next;
    }
};
