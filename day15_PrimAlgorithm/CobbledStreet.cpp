////
//// Created by ThucHD on 7/12/17.
////
//
//
//#include "CobbledStreet.h"
//
//#define MAX 300010
//#define INF 1000010
//
//vector<pair<int, int> >graph[MAX];
//vector<int> dist;
//vector<int> path;
//vector<bool> visited;
//
//int n, m;
//
//void CobbledStreet() {
//    int t, p;
//    int a, b, c;
//    long res, max;
//    cin >> t;
//
//    while(t > 0) {
//        cin >> p >> n >> m;
//
//        dist = vector<int>((unsigned long)n + 1, INF);
//        path = vector<int>((unsigned long)n + 1, -1);
//        visited = vector<bool>((unsigned long)n + 1, false);
//        max = INF;
//
//        for(int i = 0; i < m; ++i) {
//            cin >> a >> b >> c;
//
//            graph[a].push_back(make_pair(b, c));
//            graph[b].push_back(make_pair(a, c));
//        }
//
//
//        runMST(1);
//        res = getDist();
//        cout << res * p << endl;
//        --t;
//    }
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
//        visited[u] = true;
//
//        for(int i = 0; i < graph[u].size(); ++i) {
//            int v = graph[u][i].first;
//            int w = graph[u][i].second;
//            if(!visited[v] && dist[v] > w) {
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