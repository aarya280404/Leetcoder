class MinStack {
public:
    stack<int>s;
   int mini=INT_MAX;
    MinStack() {
        while(s.empty()==false) s.pop();
        
    }
    
    void push(int x) {
        if(s.empty()) {
            s.push(x);
            mini=x;
        }
        else if(mini < x){
            s.push(x);
        }
        else{
            int tmp=2*x-mini;
            mini=x;
            s.push(tmp);
        }

    }
    
    void pop() {
        if(s.empty()) return;

        int t=s.top();
        s.pop();
        if(mini > t) mini=2*mini-t;
    }
    
    int top() {
        if(s.empty()) return -1;

        if(mini <s.top()) return s.top();
        else return mini;
    }
    
    int getMin() {
        return mini;
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