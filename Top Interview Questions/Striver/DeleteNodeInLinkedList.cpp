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
    void deleteNode(ListNode* node)
    {
        //change the node's current value to the next node's value
        node->val = node->next->val;
        //Make the current node's next as the next node of the current next node
        node->next = node->next->next;
    }
};