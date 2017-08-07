////
//// Created by ThucHD on 7/13/17.
////
//
//#include "ConnectTheCampus.h"
//
//#define MAX 1010
//#define INF 1000010
//
//struct Coordinate {
//    int x;
//    int y;
//};
//
//vector<pair<int, double> >graph[MAX];
//vector<double> dist(760);
//vector<int> path(760);
//vector<bool> visited(760);
//int n;
//
//void ConnectTheCampus() {
//    int x, y;
//    int m;
//    double distance, res;
//    Coordinate input;
//    vector<Coordinate> vCoordinates;
//
//    while(cin >> n) {
//        vCoordinates.clear();
//        fill(dist.begin(), dist.end(), INF);
//        fill(path.begin(), path.end(), -1);
//        fill(visited.begin(), visited.end(), false);
//
//        vCoordinates.push_back(input);
//        for(int i = 1; i <= n; ++i) {
//            cin >> x >> y;
//            input.x = x;
//            input.y = y;
//            vCoordinates.push_back(input);
//        }
//
//        for(int i = 1; i <= n; ++i) {
//            for(int j = i + 1; j <= n; ++j) {
//                distance = sqrt(pow(vCoordinates[i].x - vCoordinates[j].x, 2) + pow(vCoordinates[i].y - vCoordinates[j].y, 2));
//                graph[i].push_back(make_pair(j, distance));
//                graph[j].push_back(make_pair(i, distance));
//            }
//        }
//
//        cin >> m;
//        for(int i = 0; i < m; ++i) {
//            cin >> x >> y;
//            graph[x].push_back(make_pair(y, 0));
//            graph[y].push_back(make_pair(x, 0));
//        }
//
//        runMST(1);
//        res = getDist();
//        cout << fixed << setprecision(2) << res << endl;
//        for(int i = 1; i <= n; ++i) {
//            graph[i].clear();
//        }
//    }
//}
//
//void runMST(int src) {
//    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
//    pq.push(make_pair(0, src));
//    dist[src] = 0;
//
//    while(!pq.empty()) {
//        int u = pq.top().second;
//        visited[u] = true;
//        pq.pop();
//
//        for(int i = 0; i < graph[u].size(); ++i) {
//            int v = graph[u][i].first;
//            double w = graph[u][i].second;
//
//            if(!visited[v] && dist[v] > w) {
//                dist[v] = w;
//                path[v] = u;
//                pq.push(make_pair(w, v));
//            }
//        }
//    }
//}
//
//double getDist() {
//    double res = 0;
//
//    for(int i = 1; i <= n; ++i) {
//        if(dist[i] == INF)
//            continue;
//
//        res += dist[i];
//    }
//    return res;
//}