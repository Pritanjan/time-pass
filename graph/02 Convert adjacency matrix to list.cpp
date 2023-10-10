// UNODIERETED GRAPH

// Graph creation by ADJANCY MATRIX

#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	// graph here
	int adj[n+1][m+1];
	for(int i=0; i<m; i++){
	    int u, v;
	    cin >> u >> v;
	    adj[u][v] = 1;
	    adj[v][u] = 1;
	}
	return 0;
}

// T.C. --> O(N)
// S.C. --> O(N*N)






// Graph creation by ADJANCY LIST


#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n+1];
	for(int i=0; i<m; i++){
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	return 0;
}

// T.C. --> O(N)
// S.C. --> O(2*E)



// DIERETED GRAPH ( FROM EDGE u ---> v )

#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	vector<int> adj[n+1];
	for(int i=0; i<m; i++){
	    int u, v;
	    cin >> u >> v;
	    // u --> v
	    adj[u].push_back(v);
	}
	return 0;
}

// S.C. --> O(E)

