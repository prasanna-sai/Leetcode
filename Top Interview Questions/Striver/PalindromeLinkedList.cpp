class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};


class Solution
{
    public:
        bool isPalindrome(ListNode* head)
        {
            ListNode* slow= head;
            stack <int> s; 
            while(slow != nullptr){ 
                    s.push(slow->val);
                    slow = slow->next; 
            } 
            while(head != nullptr ){ 
                int i=s.top(); 
                s.pop(); 
                if(head -> val != i){ 
                    return false; 
                } 
            head=head->next; 
            } 
    
        return true; 
        }
};


//O(1) space
class Solution
{
    public:
    //Find the centre of the linked list
        ListNode* findMid(ListNode* head)
        {
            ListNode* slow=head,*fast=head;
            while(fast!=NULL && fast->next!=NULL){

                slow=slow->next;
                fast=fast->next;
                if(fast) fast=fast->next;
            }
            return slow;
        }
        //reverse the list
        ListNode* reverseList(ListNode* head){
            ListNode* prev=NULL,*curr=head,*temp=NULL;
            while(curr != NULL){
                temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            return prev;
        }
        //compare if it is palindrome
        bool compareList(ListNode* head1, ListNode* head2){
            while(head1!=NULL && head2!=NULL){
                if(head1->val != head2->val) return false;
                head1=head1->next;
                head2=head2->next;
            }
            return true;
        }
        bool isPalindrome(ListNode* head) {
            if(head==NULL || head->next==NULL) return true;
            ListNode* h=head;
            ListNode* mid = findMid(h);
            ListNode* h2=reverseList(mid);
            return compareList(head,h2);
        }
};