// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// https://leetcode.com/discuss/interview-question/1408211/3-dfs-for-graphs

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &v){
        vis[node] = 1;
        v.push_back(node);
        
        // traverse all its neighbours
        for(auto it : adj[node]){
            if(!vis[it]) {
                dfs(it, adj, vis, v);
            }
        }
    }
      
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};  // bracket 0 becs of 0 indexing;
        int start = 0;
        vector<int> v;
        dfs(start, adj, vis, v);
        
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



// S.C. --> O(N)
// T.C. --> O(N + 2E)


