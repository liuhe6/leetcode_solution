    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode() : val(0), next(nullptr) {}
    *     ListNode(int x) : val(x), next(nullptr) {}
    *     ListNode(int x, ListNode *next) : val(x), next(next) {}
    * };
    */
// 需要考虑删除头结点的情况，所以加一个dummy比较容易解决问题.
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(!head) return nullptr;
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            auto p = dummy, q = dummy;
            while(n--) {
                p = p -> next;
            }
            while(p->next) {
                p = p->next;
                q = q->next;
            }
            q->next = q->next->next;
            return dummy->next;
        }
    };