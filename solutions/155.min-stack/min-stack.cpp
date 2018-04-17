class MinStack {
private:
    stack<int> st, minSt;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        st = stack<int> ();
        minSt = stack<int> ();
    }
    
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top())
            minSt.push(x);
    }
    
    void pop() {
        if (st.empty())
            return;
        if (st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }
    
    int top() {
        if (st.empty())
            return -1;
        return st.top();
    }
    
    int getMin() {
        if (st.empty())
            return -1;
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */