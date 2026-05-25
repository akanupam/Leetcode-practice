class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX), ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        int minDist = INT_MAX;
        pq.push({0,0});
        int mod = (int)(1e9+7);
        while(!pq.empty()){
            auto &node = pq.top();
            long long w = node.first;
            int s = node.second;
            pq.pop();
            if(w > dist[s]) continue;
            for(auto &[adjNode, wt]: adj[s]){
                if(wt + w < dist[adjNode]){
                    dist[adjNode] = wt+w;
                    pq.push({wt + w,adjNode});
                    ways[adjNode] = ways[s];
                }else if(wt + w == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[s])% mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};