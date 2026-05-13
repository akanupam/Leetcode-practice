class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int> q;
        vector<vector<int>> reverseGraph(graph.size());
        vector<int> outdegree(graph.size());
        for(int i=0;i<graph.size();i++){
            outdegree[i] = graph[i].size();
            for(int x: graph[i]){
                reverseGraph[x].push_back(i);
            }
        }
        for(int i=0;i<outdegree.size();i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(int i:reverseGraph[x]){
                outdegree[i]--;
                if(outdegree[i]==0){
                q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};