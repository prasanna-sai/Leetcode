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
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
           ListNode* dummy = new ListNode(7);
           dummy->next = head;
           int i=0;
           ListNode* slow = dummy, *fast = dummy;
           while(i<=n)
           {
                fast = fast -> next;
                i++;
           }
           while(fast)
           {
                fast = fast -> next;
                slow = slow -> next;
           }
           slow -> next = slow->next->next;
           return dummy->next;
        }
    };