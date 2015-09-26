#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    void push(int x) {
        if (mins.empty() || x <= mins.top())
            mins.push(x);
        s.push(x);
    }
    
    void pop() {
        if (s.top() == mins.top())
            mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};