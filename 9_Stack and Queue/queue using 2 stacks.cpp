class MyQueue {
    public:
        stack<int> st1,st2;
        MyQueue() {    
        }
        
        void push(int x) {
            st1.push_back(x);
        }
        
        int pop() {
            if(s2.empty()){
                while(!st1.empty())
                {
                    int temp = st1.top();
                    st1.pop();
                    st2.push(temp);
                }
            }
            int val = st2.top();
            st2.pop();
            return val;
        }
        
        int peek() {
            if(s2.empty()){
                while(!st1.empty())
                {
                    int temp = st1.top();
                    st1.pop();
                    st2.push(temp);
                }
            }
            return st2.top();
        }
        
        bool empty() {
            if(st1.empty() && st2.empty())
            {
                return true;
            }
            return false;
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */