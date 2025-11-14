class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> g;
        for (const auto& e: edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        unordered_set<int> vs;
        return dfs(source, destination, g, vs);
    }
    
    bool dfs(int n, int destination, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        if (n == destination) {
            return true;
        }
        visited.insert(n);
        for (int neighbor : graph[n]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, destination, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
