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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head)
        {
            return head;
        }
        int n = 1;
        ListNode* temp = head;
        while(temp -> next)
        {
            temp = temp -> next;
            n++;
        }
        k = k%n;
        if(k==0 || n<2)
        {
            return head;
        }
        k = n-k;
        ListNode* x = head, *y = head;
        while(k--)
        {
            y = x;
            x = x -> next;
        }
        y->next = NULL;
        temp -> next = head;
        return x;
    }
};