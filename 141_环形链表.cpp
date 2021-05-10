class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        auto fast = head->next, slow = head;
        while(fast) {
            fast = fast->next, slow = slow->next;
            if(!fast) return false;
            fast = fast->next;
            if(fast == slow) return true;
        }
        return false;
    }
};