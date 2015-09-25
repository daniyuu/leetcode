#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        int sz = q.size() - 1;
        int top = 0;
        while (sz--) {
            top = q.front();
            q.pop();
            q.push(top);
        }
        q.pop();
        
    }
    
    // Get the top element.
    int top() {
        int sz = q.size();
        int top = 0;
        while (sz--) {
            top = q.front();
            q.pop();
            q.push(top);
        }
        return top;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
//
//int main(){
//    Stack s;
//    s.push(1);
//    s.pop();
//}