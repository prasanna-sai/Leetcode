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

//The above solution is from @alex_tsitsura is a brilliant way of using call stack, although it is doing twice of required operations.
//But the idea is too brilliant of using a global variable and call stack to compare the elements.

class Solution
{
    public:
        bool isPalindrome(ListNode* head)
        {
            ListNode* slow= head; 
    
            // Declare a stack  
            stack <int> s; 
    
    
            // Push all elements of the list  
            // to the stack  
            while(slow != nullptr){ 
                    s.push(slow->val); 
    
                    // Move ahead  
                    slow = slow->next; 
            } 
    
            // Iterate in the list again and  
            // check by popping from the stack 
            while(head != nullptr ){ 
                
                // Get the top most element  
                int i=s.top(); 
    
                // Pop the element  
                s.pop(); 
    
                // Check if data is not 
                // same as popped element  
                if(head -> val != i){ 
                    return false; 
                } 
    
                // Move ahead  
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