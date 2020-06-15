// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Time Complexity- O(n^2 log(n^2))  where n is the size of the square matrix
class Solution {
public:
    int inf = 1e9;
    int dijkstra(vector<vector<int>>& mat, int n) { // Dijkstra using min priority queue
        priority_queue < pair < int, pair< int, int > > , vector< pair < int, pair< int, int > > >, greater< pair < int, pair< int, int > > > > pq;
        int dist[n][n];
        if(mat[0][0]) return -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) dist[i][j] = inf;  //Initializing the dist array
        int a[] = {0, 0, 1, -1, 1, -1, -1, 1};
        int b[] = {1, -1, 0, 0, 1, -1, 1, -1};
        dist[0][0] = 1;
        pq.push({1, {0, 0}});
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int w = pq.top().first;
            pq.pop();
            for(int i = 0; i < 8; i++){         // checking in all 8 directions
                int xx = x + a[i];
                int yy = y + b[i];
                if(xx >= n || xx < 0 || yy >= n || yy < 0) continue;
                if(dist[xx][yy] > w + 1 && mat[xx][yy] == 0){
                    dist[xx][yy] = w + 1;
                    pq.push({dist[xx][yy], {xx, yy}});
                }
            }
        }
        return dist[n-1][n-1] == inf ? -1 : dist[n-1][n-1];

    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        return dijkstra(grid, n);
    }
};