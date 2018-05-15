和[前一题](https://leetcode.com/problems/course-schedule/description/)不同的是，前一题只要求判断是否存在拓扑序列，这一题还要求输出拓扑序列

## BFS

```c++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> indegrees(numCourses,0);    //顶点的入度，即有多少边指向该顶点
        vector<int> res;
        
        for(auto p : prerequisites){
            indegrees[p.first]++;
            graph[p.second].push_back(p.first);
        }
        
        deque<int> q;
        for(int v = 0;v < numCourses;v++)
            if(indegrees[v] == 0){
                q.push_back(v);
                res.push_back(v);
            }
        while(!q.empty()){
            int v = q.front();
            q.pop_front();
            for(int v2 : graph[v])
                if(--indegrees[v2] == 0){
                    q.push_back(v2);
                    res.push_back(v2);
                }
        }
        
        for(int indegree : indegrees)
            if(indegree)
                return vector<int>();
        return res;
    }
};
```

## DFS

```c++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        //0：该顶点还未被访问
        //1：当前DFS路径中，该顶点已被访问
        //2：以该顶点开始的DFS路径中不包含环
        vector<int> state(numCourses,0);
        vector<int> res;
        
        for(auto p : prerequisites)
            graph[p.second].push_back(p.first);
        
        for(int v = 0;v < numCourses;v++)
            if(state[v] == 0 && !dfs(graph,state,v,res))
                break;
        
        return vector<int>(res.rbegin(),res.rend());
    }
private:
    bool dfs(vector<vector<int>> &graph,vector<int> &state,int v,vector<int> &res){
        if(state[v] == 1){
            res.clear();//if成立表示出现了环，只需在这里clear
            return false;
        }
        else if(state[v] == 2)  return true;
        
        state[v] = 1;//当前顶点标记为已访问
        for(int v2 : graph[v])
            if(!dfs(graph,state,v2,res))
                return false;
        
        state[v] = 2;//以当前顶点开始的DFS路径中不包含环
        res.push_back(v);//遍历完所有子顶点后才添加当前顶点
        return true;
    }
};
```