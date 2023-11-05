class MyStack {
public:
queue<int> q1, q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // q1에 1개의 원소가 남을 때까지 pop
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ret = q1.front();

        q1.pop();
        swap(q1, q2);
        return ret;
    }
    
    int top() {
        // q1에 1개의 원소가 남을 때까지 pop
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ret =  q1.front();

        // 복원하는 과정
        q2.push(ret);
        q1.pop();
        swap(q1, q2);
        return ret;
    }
    
    bool empty() {
        return q1.empty();
    }
};