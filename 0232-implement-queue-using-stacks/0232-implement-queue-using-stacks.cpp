class MyQueue {
public:
    
    stack<int>input;
    stack<int>output;
    int peekele=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        
       if(input.empty())
       {
           peekele=x;
           input.push(x);
       }
        else
        {
             input.push(x);
        }
    }
    
    //amortized O(1)-meas kbhi O(1)leta h kbhii O(n)
    int pop() {
        if(output.empty())
        {
            //input->output o(n)
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
       int val=output.top();//O(1) jb sirf I/P s nikalna ho
       output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty())
            return peekele;
     return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty())
        return true;
        
        return false;
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