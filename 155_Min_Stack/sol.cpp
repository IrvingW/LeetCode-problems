class MinStack {
private:
    stack<int> min;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int x) {
        if(x <= min.top())
            min.push(x);
        s.push(x);
    }
    
    void pop() {
        if(s.top() == min.top())
            min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
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
