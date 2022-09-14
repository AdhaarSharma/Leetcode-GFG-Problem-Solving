class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(!indegree[i])
                q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(auto v:graph[u]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        return (ans.size()==numCourses);
    }
};