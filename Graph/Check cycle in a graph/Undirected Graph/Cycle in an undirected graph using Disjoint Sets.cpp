// Time Complexity- O(V) for this adjacency list graph where  V is number of vertices

#include<bits/stdc++.h>
using namespace std;
#define INF (1e9)

int find(vector<int>& parent, int node){
	if(parent[node] == -1) return node;
	return find(parent, parent[node]);
}

void Union(vector<int>& parent, int v1, int v2){
	int a = find(parent, v1);
	int b = find(parent, v2);
	if(a != b){
		parent[a] = b;
	}
}

bool cycle(vector< int > adj[], int vertices){
	vector<int> parent(vertices + 1, -1);
	for(int i = 1; i <= vertices; i++){
		for(auto v1 : adj[i]){
			int a = find(parent, v1);
			int b = find(parent, i);
			if(a == b) return true;
			Union(parent, a, b);
		}
	}
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