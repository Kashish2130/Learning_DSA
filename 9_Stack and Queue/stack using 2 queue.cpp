class MyStack {
    public:
        queue<int> q1,q2;
        MyStack() {
            
        }
        
        void push(int x) {
            while(!q1.empty())
            {
                q2.push(q1.pop());
            }
    
            q1.push(data);
    
            wile(!q2.empty()){
                q1.push(q2.pop());
            }
        }
        
        int pop() {
            return q1.pop();
        }
        
        int top() {
            return q1.top();
        }
        
        bool empty() {
            id(q1.empty() && q2.empty())
            {
                return true;
            }
    
            return false;
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