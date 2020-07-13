// Time Complexity- O(Elog(v)) for this adjacency list graph where E is number of edges and V is number of vertices

#include<bits/stdc++.h>
using namespace std;
#define INF (1e9)
void dijkstra(int source, vector< pair < int, int> > adj[], int vertices) {
	vector<int> distance(vertices + 1, INF);  // Distance of source from v is the distance[v], initialized as INF
	priority_queue< pair< int, int> , vector< pair< int, int> >, greater< pair< int, int> > > pq; //Min priority queue pair of weight and vertex

	distance[1] = 0;
	pq.push({0, 1});		// Source is 1 with distance 0 initially

	while( !pq.empty() ) {  // loop till pq becomes empty
		int cur = pq.top().second;
		pq.pop();
		for(auto i : adj[cur]) {
			int to = i.first;
			int weight = i.second;

			if(distance[to] > distance[cur] + weight) {
				distance[to] = distance[cur] + weight;
				pq.push({distance[to], to});
			}
		}
	}

	cout <<"All distances from source to nodes\n";
	for(int i = 1; i <= vertices; i++){
		cout << "Source to " << i <<" is " << distance[i] << "\n";
	}
	return;


}
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector< pair< int, int > > adj[vertices + 1]; // the index is first vertex first val in pair is the second vertex and second val is the weight
    for(int i = 0; i < edges; i++) {
    	int a, b, weight;
    	cin >> a >> b >> weight;
    	adj[a].push_back({b, weight});
    	adj[b].push_back({a, weight});  // If directed graph don't use this
	}
	dijkstra(1, adj, vertices);
	return 0;
}