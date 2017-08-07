////
//// Created by ThucHD on 7/23/17.
////
//
//#include "DarkRoads.h"
//
//#define MAX 200010
//#define INF 1e10
//vector<vector<pair<int, int> > > graph(MAX);
//vector<long> dist(MAX);
//vector<bool> visited(MAX);
//int m, n;
//
//void DarkRoads() {
//    int x, y, z;
//    long totalLen;
//
//    while(true) {
//        cin >> m >> n;
//        if(m == 0 && n == 0)
//            break;
//
//        fill(graph.begin(), graph.begin() + n, vector<pair<int, int> >());
//        fill(dist.begin(), dist.begin() + n, INF);
//        fill(visited.begin(), visited.begin() + n, false);
//        totalLen = 0;
//
//        for(int i = 0; i < n; ++i) {
//            cin >> x >> y >> z;
//            graph[x].push_back(make_pair(y, z));
//            graph[y].push_back(make_pair(x, z));
//            totalLen += z;
//        }
//
//        runPrim(0);
//        cout << totalLen - getAllLength() << endl;
//    }
//}
//
//void runPrim(int src) {
//    int u, v, w;
//    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
//    dist[src] = 0;
//    pq.push(make_pair(0, src));
//
//    while(!pq.empty()) {
//        u = pq.top().second;
//        pq.pop();
//        visited[u] = true;
//        for(int i = 0; i < graph[u].size(); ++i) {
//            v = graph[u][i].first;
//            w = graph[u][i].second;
//
//            if(!visited[v] && dist[v] > w) {
//                dist[v] = w;
//                pq.push(make_pair(w, v));
//            }
//        }
//    }
//}
//
//long getAllLength() {
//    long res = 0;
//
//    for(int i = 0; i < m; ++i)
//        if(dist[i] != INF) res += dist[i];
//    return res;
//}