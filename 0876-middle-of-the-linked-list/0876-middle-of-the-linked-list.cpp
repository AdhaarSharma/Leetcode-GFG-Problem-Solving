class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* trtl = head;
        ListNode* lb = head;
        while (lb && lb->next){
            
            lb = lb->next->next;
            trtl = trtl->next;
        }
        return trtl;        
    }
};