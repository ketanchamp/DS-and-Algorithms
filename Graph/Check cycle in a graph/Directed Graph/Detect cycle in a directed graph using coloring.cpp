// Time Complexity- O(V) for this adjacency list graph where  V is number of vertices

#include<bits/stdc++.h>
using namespace std;
#define INF (1e9)

bool dfs(int node, vector<int>& color, vector< int > adj[]){
	color[node] = 1;
	for(int v : adj[node]){
		if(color[v] == 1) return true;
		if (color[v] == 0) if(dfs(v, color, adj)) return true;
	}
	color[node] = 2;
	return false;
}

bool cycle(vector< int > adj[], int vertices){
	vector<int> color(vertices + 1, 0);				// color[v] = 0 denotes color of vertex v is white, color[v] = 1 grey and color[v] = 2 is black
  	for(int i = 1; i <= vertices; i++){
		if(color[i] == 0 && dfs(i, color, adj) ) return true;
	}
	return false;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector< int > adj[vertices + 1]; // the index is first vertex and val is the second vertex in this adjacency list
    for(int i = 0; i < edges; i++) {
    	int a, b;
    	cin >> a >> b;
    	adj[a].push_back(b); 		 // Directed Edge
	}
	if(cycle(adj, vertices) ) cout << "Yes there is a cycle present in the graph\n";
	else cout << "No cycle present in the graph!!! All good!\n";
	return 0;
}