class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : valueS() , minS() {

    }
    
    void push(int x) {
        valueS.push(x);
        //第一个条件容易漏
        if(minS.empty() || x < minS.top())  minS.push(x);
        else    minS.push(minS.top());
    }
    
    void pop() {
        valueS.pop();
        minS.pop();
    }
    
    int top() {
        return valueS.top();
    }
    
    int getMin() {
        return minS.top();
    }
private:
    stack<int> valueS;
    stack<int> minS;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */