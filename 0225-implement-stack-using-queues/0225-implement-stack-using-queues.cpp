class MyStack {
public:
queue<int> q1;
queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
  while(!q1.empty()){
    q2.push(q1.front());
    q1.pop();
  }
   q1.push(x);
   while(!q2.empty()){
    q1.push(q2.front());
    q2.pop();
   }
        
    }
    
    int pop() {
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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