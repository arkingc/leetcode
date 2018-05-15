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