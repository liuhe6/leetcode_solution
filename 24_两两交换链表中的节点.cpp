class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto cur = dummy;
        while(cur && cur->next && cur->next->next) {
            auto a = cur->next, b = cur->next->next;
            cur->next = b;
            a->next = b->next;
            b->next = a;
            cur = a;
        }
        return dummy->next;

    }
};
