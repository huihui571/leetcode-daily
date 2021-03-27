## BFS模板
```
起点入Q
置访问标记
while Q不空:
    for i in Q_size:
        cur = 队首出Q
        访问之，做操作
        for 邻接点 in 邻接表:
            if !访问标记:
                邻接点入Q
                置访问标记
    遍历完一层的操作
```
c++代码
```
queue<string> q;
unordered_map<string, bool> visited;

q.push(start);
visited[start] = 1;
while (!q.empty())
{
    int q_size = q.size();
    for (int i = 0; i < q_size; ++i)
    {
        string cur = q.front();             //出队，访问之
        q.pop();
        
        for (neigbor : cur->neignbors)      //邻居节点入队
        {
            if (!visited[neigbor])
            {
                q.push(neigbor);      
                visited[neigbor] = true;   //置访问标记     
            }      
        }     
    }
  
}
```

## DFS模板
```
起点入S
置访问标记
while S不空:
    cur = 栈顶出栈
    访问之，做操作
    for 邻接点 in 邻接表:
        if !访问标记:
            邻接点入S
            置访问标记
```
c++遍历多叉树代码
```
vector<int> res;
stack<Node*> st;

st.push(root);                      //根入栈
while (!st.empty())
{
    Node* cur = st.top();           //出栈，访问之
    st.pop(); 
    res.push_back(cur->val);              
    for (Node* ch : cur->children)  //子节点依次入栈
    {
        if (ch != NULL)
            st.push(ch);
    }
}
```