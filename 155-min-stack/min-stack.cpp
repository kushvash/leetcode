class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        int currMin=val;
        if(!minSt.empty()) {
            currMin=minSt.top();
        }

        minSt.push(min(currMin, val));
        st.push(val);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        if(st.empty()) {
            return 0;
        }

        return st.top();
    }
    
    int getMin() {
        if(st.empty()) {
            return 0;
        }

        return minSt.top();
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