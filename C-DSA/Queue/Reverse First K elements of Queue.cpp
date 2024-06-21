struct Queue *modifyQueue(struct Queue *queue, int n, int k) {
    // code here
    // Use a stack to reverse the first k elements
    stack<int> s;
    for(int i=0;i<k;i++)
    {
        int val = queue.front();
        queue.pop();
        s.push(val);
    }
    
    while(!s.empty())
    {
        int val = s.front();
        s.pop();
        queue.push(s);
    }
    
    int t = queue.size()-k;
    
    while(t--)
    {
        int val = queue.front();
        queue.pop();
        queue.push(val);
    }
    
    return queue;
}
