/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/
//Time:O(N)
//Space:O(N)
//Solution1

class MinStack {
private:
    stack<int>st;
    stack<int>minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!minStack.empty()){
            val = min(val,minStack.top());
            minStack.push(val);
        }
        else{
            minStack.push(val);
        }
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
       return st.top(); 
    }
    
    int getMin() {
        return minStack.top();
    }
};

//Solution2 has the same time and space complexities as above code.It runs little bit faster than previous solution
//Hint:Store the min element of stack by designing the minstack using a pair object.
class MinStack {
private:
    stack<int>st;
    stack<pair<int,int>>minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty() || val < minStack.top().first){
            minStack.push({val,1});
        }
        else{
            minStack.top().second++;
        }
    }
    
    void pop() {
        minStack.top().second--;
        if(minStack.top().second == 0){
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top().first;
    }
};
