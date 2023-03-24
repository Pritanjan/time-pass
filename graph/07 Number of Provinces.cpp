// https://practice.geeksforgeeks.org/problems/number-of-provinces/1

class Solution {
private: 
    void dfs(int node, vector<int> adj_ls[], int vis[]) {
        vis[node] = 1;
        for(auto it : adj_ls[node]) {
            if(!vis[it]) {
                dfs(it, adj_ls, vis);
            }
        }
    }
    
public:
    int numProvinces(vector<vector<int>>& adj, int V) {
        // to convert adjacency matrix into adjacency list
        vector<int> adj_ls[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adj_ls[i].push_back(j);
                    adj_ls[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adj_ls, vis);
            }
        }
        return cnt;
    }
};


// S.C. --> O(N) + O(V + 2E)
