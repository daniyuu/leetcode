#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> in;
    stack<int> out;
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);
    }
    void move(){
        while (!in.empty()) {
            int t = in.top();
            out.push(t);
            in.pop();
        }
    }
    // Removes the element from in front of queue.
    void pop(void) {
        if (out.empty()) {
            move();
        }
        
        if (!out.empty()) {
            out.pop();
        }
    }
    
    // Get the front element.
    int peek(void) {
        if (out.empty()) {
            move();
        }
        if (!out.empty()) {
            return out.top();
        }
        return 0;
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return in.empty() && out.empty();
    }
};

//
//int main(){
//    Queue q;
//    q.push(1);
//    cout << q.peek();
//    cout << q.empty();
//}