/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    ListNode* head;
    ListNode* current;
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL || l2 == NULL)
        {
            return (l1 == NULL ? l2 : l1);
        }
        ListNode* ans = new ListNode(0);
        ListNode* merge = ans;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                ans->next = l1;
                l1 = l1->next;
                ans = ans -> next;
            }
            else
            {
                ans -> next = l2;
                l2 = l2 -> next;
                ans = ans -> next;
            }
        }
        if(l1)
        {
            ans->next = l1;
        }
        else
        {
            ans -> next = l2;
        }
        return merge->next;
    }
};