class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        while(a != b) {
            if(a) a = a->next;
            else a = headB;
            if(b) b = b ->next;
            else b = headA;
        }
        return a;
    }
};