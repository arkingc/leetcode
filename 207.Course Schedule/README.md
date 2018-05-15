问题等价于在先决条件构造的有向图中，判断是否存在环。**如果存在环，那么没有拓扑序列**，所以使用[拓扑排序](https://github.com/arkingc/note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95/%E5%9B%BE.md#%E6%8B%93%E6%89%91%E6%8E%92%E5%BA%8F)来处理，可以通过BFS或DFS

## BFS

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> indegrees(numCourses,0);    //顶点的入度，即有多少边指向该顶点
        
        for(auto p : prerequisites){
            indegrees[p.first]++;
            graph[p.second].push_back(p.first);
        }
        
        deque<int> q;
        for(int v = 0;v < numCourses;v++)
            if(indegrees[v] == 0)
                q.push_back(v);
        while(!q.empty()){
            int v = q.front();
            q.pop_front();
            for(int v2 : graph[v])
                if(--indegrees[v2] == 0)
                    q.push_back(v2);
        }
        
        for(int indegree : indegrees)
            if(indegree)
                return false;
        return true;
    }
};
```

## DFS

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        //0：该顶点还未被访问
        //1：当前DFS路径中，该顶点已被访问
        //2：以该顶点开始的DFS路径中不包含环
        vector<int> state(numCourses,0);
        
        for(auto p : prerequisites)
            graph[p.second].push_back(p.first);
        
        for(int v = 0;v < numCourses;v++)
            if(state[v] == 0 && !dfs(graph,state,v))
                return false;
        
        return true;
    }
private:
    bool dfs(vector<vector<int>> &graph,vector<int> &state,int v){
        if(state[v] == 1)  return false;
        else if(state[v] == 2) return true;
        
        state[v] = 1;//当前顶点标记为已访问
        for(int v2 : graph[v])
            if(!dfs(graph,state,v2))
                return false;
        
        state[v] = 2;//以当前顶点开始的DFS路径中不包含环
        return true;
    }
};
```