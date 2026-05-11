class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V,false);
        vector<int> indegree(V);
        vector<vector<int>> adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                visited[i]=true;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    visited[it]=true;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;

    }
};