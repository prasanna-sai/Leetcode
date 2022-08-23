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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        int cntA = 0, cntB = 0;

        while(tmpA)
        {
            tmpA = tmpA->next;
            cntA++;
        }

        while(tmpB)
        {
            tmpB = tmpB->next;
            cntB++;
        }

        int cnt = cntA - cntB;
        if (cnt > 0) {
            tmpA = headA;
            tmpB = headB;
        } else{
            tmpA = headB;
            tmpB = headA;
        }

        cnt = abs(cnt);
        for (int i = 0; i < cnt; ++i) {
            tmpA = tmpA->next;
        }

        while(tmpA && tmpA != tmpB)
        {
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }

        return tmpA;
    }
};

//Another solution of same approach but in a concise way by @satyakam
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
        
    return p1;
}