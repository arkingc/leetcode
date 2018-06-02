## 题目

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

* push(x) -- 将元素 x 推入栈中。
* pop() -- 删除栈顶的元素。
* top() -- 获取栈顶元素。
* getMin() -- 检索栈中的最小元素。

示例:

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

## 解答

使用一个辅助栈保证最小值，该栈的栈顶保存了当前栈中元素的最小值。因此，对于一个新元素，如果小于栈顶元素，那么最小值栈中压入新的元素，否则，继续压入最小值栈的栈顶元素

```c++
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
```