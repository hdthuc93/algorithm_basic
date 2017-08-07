////
//// Created by ThucHD on 7/12/17.
////
//
//#include "MinimumSpanningTree.h"
//
//#define MAX 100010
//#define INF 1000010
//
//vector<pair<int, int> >graph[MAX];
//vector<int> dist;
//vector<int> path;
//vector<bool> visitted;
//int n, m;
//
//void MinimumSpanningTree() {
//    int i, j, k;
//    long res;
//    cin >> n >> m;
////    graph = vector<pair<int, int> >(MAX);
//    dist = vector<int>((unsigned long)n + 1, INF);
//    path = vector<int>((unsigned long)n + 1, -1);
//    visitted = vector<bool>((unsigned long)n + 1, false);
//
//    for(int c = 0; c < m; ++c) {
//        cin >> i >> j >> k;
//
//        graph[i].push_back(make_pair(j, k));
//        graph[j].push_back(make_pair(i, k));
//    }
//
//    runMST(n);
//    res = getDist();
//    cout << res << endl;
//}
//
//void runMST(int src) {
//    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
//    pq.push(make_pair(0, src));
//    dist[src] = 0;
//
//    while(!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//        visitted[u] = true;
//
//        for(int i = 0; i < graph[u].size(); ++i) {
//            int v = graph[u][i].first;
//            int w = graph[u][i].second;
//            if(!visitted[v] && dist[v] > w) {
//                dist[v] = w;
//                path[v] = u;
//                pq.push(make_pair(w, v));
//            }
//        }
//    }
//}
//
//long getDist() {
//    long res = 0;
//    for(int i = 1; i <= n; ++i) {
//        if(dist[i] != INF) {
//            res += dist[i];
//        }
//    }
//
//    return res;
//}