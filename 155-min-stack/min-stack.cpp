class MinStack {
public:
    MinStack() {
        
    }
    
    stack<int> s;
    stack<int> minStack;

    void push(int val) {
        s.push(val);
        if(minStack.empty()){
            minStack.push(val);    
        }else{
            minStack.push(min(val, minStack.top()));
        }
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */