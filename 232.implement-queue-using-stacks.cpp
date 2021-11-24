/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    stack<int> head;
    stack<int> tail;
    MyQueue() {

    }
    
    void push(int x) {
        head.push(x);
    }
    
    int pop() {
        while (!head.empty())
        {
            int t=head.top();
            head.pop();
            tail.push(t);
        }
        int ans = tail.top();
        tail.pop();
        while (!tail.empty())
        {
            int t=tail.top();
            tail.pop();
            head.push(t);
        }
        return ans;
    }
    
    int peek() {
        while (!head.empty())
        {
            int t=head.top();
            head.pop();
            tail.push(t);
        }
        int ans = tail.top();
        while (!tail.empty())
        {
            int t=tail.top();
            tail.pop();
            head.push(t);
        }
        return ans;
    }
    
    bool empty() {
        return head.empty();
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
// @lc code=end

