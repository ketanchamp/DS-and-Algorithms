// Time Complexity- O(E + V) for this adjacency list graph where E is number of edges and V is number of vertices
#include<bits/stdc++.h>
using namespace std;
stack<int> s;					// Stack storing the finish times
vector<int> adj[500]; 				// Adjacency list for a graph
vector<int> rev[500];				// Graph after reversing
vector<bool> vis(500, false);			// Visited array

void dfs(int node){  				// DFS Pass 1 for storing values in Stack in decreasing finish time of a node
	vis[node] = true;
	for(int i : adj[node]){
		if(!vis[i]) dfs(i);
	}
	s.push(node);
}

void dfs1(int node){				// DFS Pass 2 for determining the strongly connected components
	vis[node]=true;
	for(int i : rev[node]){
		if(!vis[i]) dfs1(i);
	}
	cout<<node<<" ";			// printing vertices in a strongly connected components
}
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    for(int i = 0; i < edges; i++) {
    	int a, b;
    	cin >> a >> b ;
    	adj[a].push_back(b);
	}
	for(int i=0;i<vertices;i++) if(!vis[i]) dfs(i);

	for(int i=0;i<vertices;i++) vis[i]=false;

	for(int i=0;i<vertices;i++){				// Reversing the graph edges
		for(int j : adj[i]) rev[j].push_back(i);
	}

	while(!s.empty()){					// DFS on nodes from stack
		int node = s.top();
		s.pop();
		if(!vis[node]) {dfs1(node);cout<<endl;}
	}


	return 0;
}
