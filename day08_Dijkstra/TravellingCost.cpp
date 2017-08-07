//
// Created by ThucHD on 6/17/17.
//

//#include "TravellingCost.h"
//#define MAX 505
//
//vector<vector<pair<int, int>>> graph;
//const int INF = 1e9;
//vector<int> dist(MAX, INF);
//int path[MAX] = {-1};
//
//void readInput() {
//    int n;
//    int a, b, w;
//    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
//    cin >> n;
//    for(int i = 0; i < n; ++i) {
//        cin >> a >> b >> w;
//        graph[a].push_back(pair<int, int>(b, w));
//    }
//    int src, q, end;
//    cin >> src;
//    cin >> q;
//    runDijkstra(src);
//    for(int i = 0; i < q; ++i) {
//        cin >> end;
//        if(dist[end] == INF)
//            cout << "NO PATH" << endl;
//        else
//            cout << dist[end] << endl;
//    }
//}
//
//void runDijkstra(int src) {
//    priority_queue<pair<int, int>> pq;
//
//    pq.push(pair<int, int>(0, src));
//    dist[src] = 0;
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