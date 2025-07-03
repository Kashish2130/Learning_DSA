//? reverse a stack using recursion
//tc : o(n^2)
//sc : o(1);
// Helper function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(top);
}

// TC : O(N^2)
// SC : O(N)
// Function to reverse the stack using recursion
void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}