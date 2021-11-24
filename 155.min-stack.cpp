/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    stack<int> s;
    stack<int> os;
    MinStack() {

    }
    
    void push(int val) {
        if (os.empty())
        {
            os.push(val);
        }
        else
        {
            os.push(min(os.top(), val));
        }        
        s.push(val);
    }
    
    void pop() {
        s.pop();
        os.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return os.top();
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
// @lc code=end

