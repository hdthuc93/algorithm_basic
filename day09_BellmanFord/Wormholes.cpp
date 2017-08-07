////
//// Created by ThucHD on 6/21/17.
////
//
//#include "Wormholes.h"
//#define MAX 2010
//
//struct Triad {
//    int source;
//    int target;
//    int weight;
//};
//const int INF = 1e9;
//vector<Triad> graph;
//vector<int> dist;
//int n, m;
//
//void Wormholes() {
//    int c, numTestCase = 1;
//    int x, y, t;
//    Triad triadTemp;
//    cin >> c;
//
//    while(numTestCase <= c) {
//        graph.clear();
//        dist = vector<int>(MAX, INF);
//        cin >> n >> m;
//
//        for(int i = 0; i < m; ++i) {
//            cin >> x >> y >> t;
//            triadTemp.source = x;
//            triadTemp.target = y;
//            triadTemp.weight = t;
//            graph.push_back(triadTemp);
//        }
//
//        runBellmanFord(0);
//        if(checkCycle()) {
//            cout << "not possible" << endl;
//        } else
//            cout << "possible" << endl;
//
//        ++numTestCase;
//    }
//}
//
//void runBellmanFord(int src) {
//    int u, v, w;
//    dist[src] = 0;
//
//    for(int i = 0; i < n -1; ++i) {
//        for(int j = 0; j < m; ++j) {
//            u = graph[j].source;
//            v = graph[j].target;
//            w = graph[j].weight;
//
//            if(dist[u] != INF && dist[u] + w < dist[v]) {
//                dist[v] = dist[u] + w;
//            }
//        }
//    }
//}
//
//bool checkCycle() {
//    int u, v, w;
//    for(int i = 0; i < m; ++i) {
//        u = graph[i].source;
//        v = graph[i].target;
//        w = graph[i].weight;
//
//        if(dist[u] != INF && dist[u] + w < dist[v]) {
//            return false;
//        }
//    }
//
//    return true;
//}