class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int n = 0;
        ListNode* tail = head;
        while(tail->next) {
            n ++;
            tail = tail->next;
        }
        n++;
        k %= n;
        if(!k) return head;
        auto p = head;
        for(int i = 0; i < n - k - 1; i++)  p = p->next;
        tail->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};