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
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* ans = new ListNode(7);
        ListNode* merge = ans;
        while(l1 && l2)
        {
            if(l1 -> val <= l2 -> val)
            {
                merge -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                merge -> next = l2;
                l2 = l2 -> next;
            }
            merge = merge -> next;
        }
        if(l1)
        {
            merge -> next = l1;
        }
        else
        {
            merge -> next = l2;
        }
        return ans->next;
    }
};