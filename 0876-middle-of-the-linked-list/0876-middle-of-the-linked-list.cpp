class Solution {
public:
    ListNode * middleNode(ListNode * head) {
        int n = 0;
        ListNode * temp = head;
        while (temp != nullptr) {
        ++n;
        temp = temp -> next;
        }

        n /= 2;
        temp = head;

        while (n) {
        temp = temp -> next;
        --n;
        }

        return temp;
    }
};