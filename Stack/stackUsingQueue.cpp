// Using Two queues
// Algo:
//   for push(): -> Add element to q2.
 //             -> transfer elems (if present) from q1 to q2.
//             -> Swap(q1,q2).
// for pop(),top(): -> do operations on q1.
          
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {  }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int poped = q1.front();
        q1.pop();
        return poped;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// Using 1 queue:
// -> push elem to q.
// -> now push first q.size()-1 elems to q, and remove these first q.size()-1 pushed elems from queue at the front.

class MyStack {
    queue<int> q1;
public:
    MyStack() {  }
    
    void push(int x) {
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int poped = q1.front();
        q1.pop();
        return poped;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */