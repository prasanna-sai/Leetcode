/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head)
        {
            return head;
        }
        int n = 0;
        ListNode* temp = head, *last = head;
        while(temp)
        {
            n++;
            last = temp;
            temp = temp->next;
        }
        k = k%n;
        if(n<2 || k==0)
        {
            return head;
        }
        k = n-k;
        temp = head;
        ListNode* currend = head;
        while(k--)
        {
            currend = temp;
            temp = temp->next;
        }
        last->next = head;
        currend->next = NULL;
        return temp;
    }
};