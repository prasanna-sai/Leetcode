class MyStack
{
    public:
        queue<int>q1,q2;
        /** Initialize your data structure here. */
        MyStack()
        {
        
        }
        /** Push element x onto stack. */
        void push(int x)
        {
            q2.push(x);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
        /** Removes the element on top of the stack and returns that element. */
        int pop()
        {
            int val = q1.front();
            q1.pop();
            return val;
        }
        /** Get the top element. */
        int top()
        {
            return q1.front();
        }
        /** Returns whether the stack is empty. */
        bool empty()
        {
            return q1.empty();
        }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 class MyStack {
public:
    queue<int>q1,q2;
    bool insertToQueue1 = true; //control to check into which queue to insert
    MyStack() {
        
    }
    
    void push(int x)
    {
        if(insertToQueue1)
        {
            q1.push(x);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            insertToQueue1 = false;
        }
        else
        {
            q2.push(x);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            insertToQueue1 = true;
        }
    }
    
    int pop()
    {
        if(insertToQueue1)
        {
            int val = q2.front();
            q2.pop();
            return val;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top()
    {
        if(insertToQueue1)
        {
            return q2.front();
        }
        return q1.front();
    }
    
    bool empty()
    {
        if(insertToQueue1)
        {
            return q2.empty();
        }
        return q1.empty();    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */