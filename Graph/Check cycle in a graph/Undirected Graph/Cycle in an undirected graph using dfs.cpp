// Time Complexity- O(V) for this adjacency list graph where  V is number of vertices

#include<bits/stdc++.h>
using namespace std;
#define INF (1e9)

bool dfs(int node, int parent, vector<bool>& visited, vector< int > adj[]){
	visited[node] = true;
	for(int i : adj[node]){
		if(i != parent ){
			if(!visited[i] && dfs(i, node, visited, adj)) return true;
			else return true;
		}
	}
	return false;
}

bool cycle(vector< int > adj[], int vertices){
	vector<bool> visited(vertices + 1, false);
	for(int i = 1; i <= vertices; i++){
		if(!visited[i] && dfs(i, 0, visited, adj) ) return true;
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
    	adj[a].push_back(b);
    	adj[b].push_back(a);
	}
	if(cycle(adj, vertices) ) cout << "Yes there is a cycle present in the graph\n";
	else cout << "No cycle present in the graph!!! All good!\n";
	return 0;
}