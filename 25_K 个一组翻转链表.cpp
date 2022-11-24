class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for(auto p = dummy;;) {
            auto q = p;
            for(int i = 0; i < k && q; i++) q = q->next;
            if(!q) break;
            auto a = p->next, b = a->next;
            for(int i = 0; i < k - 1; i++) {
                auto c = b->next;
                b->next = a ;
                a = b;
                b = c;
            }
            auto c = p->next;
            p->next = a;
            c->next = b;
            p = c;
        }
        return dummy->next;
    }
};
