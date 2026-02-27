class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edge) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(auto it: edge){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};