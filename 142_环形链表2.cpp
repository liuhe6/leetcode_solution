class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        auto fast = head->next, slow = head;
        while(fast) {
            fast = fast->next, slow = slow->next;
            if(!fast) return NULL;
            fast = fast->next;
            if(fast == slow) {
                fast = head;
                slow = slow->next;
                while(fast!=slow){
                    fast = fast->next, slow = slow->next;
                }
                return fast;
            } 
        }
        return NULL; 
    }
};