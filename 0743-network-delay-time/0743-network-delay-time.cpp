class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n + 1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int w = it.first;
            int s = it.second;
            if(w> dist[s]) continue;
            for(auto &[adjNode,wt]: adj[s]){
                if(w + wt < dist[adjNode]){
                    dist[adjNode] = w +wt;
                    q.push({w + wt,adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans==INT_MAX ? -1: ans;
    }
};