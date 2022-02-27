class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL)
            return list1;
        if(list1 != NULL && list2 == NULL)
            return list1;
        if(list1 == NULL && list2 != NULL)
            return list2;
        ListNode* head = NULL ;
        ListNode* p1 = list1, *p2 = list2;
        ListNode* ptr;
        
        while(p1 != NULL && p2 != NULL)
        {
            if(p1->val <= p2->val)
            {
                if(head == NULL)
                {
                    head = p1;
                    ptr = head;
                    p1 = p1->next;
                }
                else
                {
                    ptr->next = p1;
                    ptr = p1;
                    p1 = p1->next;
                }
            }
            else if(p1->val > p2->val)
            {
                if(head == NULL)
                {
                    head = p2;
                    ptr = head;
                    p2 = p2->next;
                }
                else
                {
                    ptr->next = p2;
                    ptr = p2;
                    p2 = p2->next;
                }
            }
        }
        if(p1 == NULL)
            ptr->next = p2;
        if(p2 == NULL)
            ptr->next = p1;
        return head;
    }
};