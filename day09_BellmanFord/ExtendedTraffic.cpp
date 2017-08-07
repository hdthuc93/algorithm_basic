////
//// Created by ThucHD on 6/21/17.
////
//
//#include "ExtendedTraffic.h"
//
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
//vector<int> busyness;
//int n, m;
//
//void ExtendedTraffic() {
//    int c, numOfTestCase = 1;
//    int ni;
//    int x, y;
//    int t;
//    int q, qi;
//    int res;
//    Triad triadTemp;
//
//    cin >> c;
//
//    while(numOfTestCase <= c) {
//        dist = vector<int>(MAX, INF);
//        graph.clear();
//        busyness.clear();
//        cin >> n;
//        busyness.push_back(0);
//
//        for(int i = 0; i < n; ++i) {
//            cin >> ni;
//            busyness.push_back(ni);
//        }
//
//        cin >> m;
//        for(int i = 0; i < m; ++i) {
//            cin >> x >> y;
//            t = (int)pow(busyness[y] - busyness[x], 3);
//
//            triadTemp.source = x;
//            triadTemp.target = y;
//            triadTemp.weight = t;
//            graph.push_back(triadTemp);
//        }
//
//        runBellmanFord(1);
//        cin >> q;
//        cout << "Case " << numOfTestCase << ":" << endl;
//
//            for(int i = 0; i < q; ++i) {
//                cin >> qi;
//                res = dist[qi];
//
//                if(res < 3 || res == INF)
//                    cout << "?" << endl;
//                else
//                    cout << res << endl;
//        }
//
//        ++numOfTestCase;
//    }
//}
//
//void runBellmanFord(int src) {
//    int u, v, w;
//    dist[src] = 0;
//
//    for(int i = 0; i < n - 1; ++i) {
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
