////
//// Created by ThucHD on 6/17/17.
////
//
//#include "MiceAndMaze.h"
//#define MAX 105
//
//vector<vector<pair<int, int>>> graph;
//const int INF = 1e9;
//vector<int> dist(MAX, INF);
//int path[MAX] = {-1};
//int c = 0;
//
//void readInput() {
//    int n, e, t;
//    int m;
//    int a, b, w;
//    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
//    cin >> n >> e >> t >> m;
//    for(int i = 0; i < m; ++i) {
//        cin >> a >> b >> w;
//        graph[b].push_back(pair<int, int>(a, w));
//    }
//
//    runDijkstra(e, t);
//    for(int i = 1; i <= n; ++i) {
//        if(dist[i] <= t) ++c;
//    }
//    cout << c;
//}
//
//void runDijkstra(int src, int t) {
//    priority_queue<pair<int, int>> pq;
//
//    pq.push(pair<int, int>(0, src));
//    dist[src] = 0;
//
//    while(!pq.empty()) {
//        pair<int, int> pairTemp = pq.top();
//        pq.pop();
//
//        int node = pairTemp.second;
//        int d = pairTemp.first;
//
//        for(int i = 0; i < graph[node].size(); ++i) {
//            pair<int, int> neighbor = graph[node][i];
//            if(d + neighbor.second < dist[neighbor.first]) {
//                dist[neighbor.first] = d + neighbor.second;
//                path[neighbor.first] = node;
//                pq.push(pair<int, int>(dist[neighbor.first], neighbor.first));
//            }
//        }
//    }
//}
