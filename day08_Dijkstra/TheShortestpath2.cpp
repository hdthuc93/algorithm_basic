////
//// Created by ThucHD on 6/20/17.
////
//
//
//#include "TheShortestPath2.h"
//
//#define MAX 10010
//const int INF = 1e9;
//map<string, int> listCityName;
//vector<vector<pair<int, int>>> graph;
//vector<vector<int>> gDist;
//vector<vector<int>> gPath;
//
//void TheShortestPath() {
//    int s, n, p, nr, cost, r;
//    string name, name1, name2;
//    cin >> s;
//    while(s > 0) {
//        // init
//        graph = std::vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
//        gPath = std::vector<vector<int>>(1, vector<int>(MAX, -1));
//        gDist = std::vector<vector<int>>(1, vector<int>(MAX, INF));
//        listCityName.clear();
//
//        cin >> n;
//
//        for(int i = 1; i <= n; ++i) {
//            cin >> name >> p;
//            listCityName[name] = i;
//            for(int j = 0; j < p; ++j) {
//                cin >> nr >> cost;
//                graph[i].push_back(pair<int, int>(nr, cost));
//            }
//        }
//
//        cin >> r;
//
//        for(int i = 0; i < r; ++i) {
//            cin >> name1 >> name2;
//            int d;
//            for(int j = 0; j < gPath.size(); ++j) {
//                d = findDist(listCityName[name1], listCityName[name2], gPath[j], gDist[j]);
//                if(d != -1)
//                    break;
//            }
//
//            if(d == -1) {
//                gPath.push_back(vector<int>(MAX, -1));
//                gDist.push_back(vector<int>(MAX, INF));
//
//                runDijkstra(listCityName[name1], gPath.back(), gDist.back());
//                d = gDist.back()[listCityName[name2]];
//            }
//
//            cout << d << endl;
//        }
//
//        --s;
//    }
//}
//
//void runDijkstra(int src, vector<int> &path, vector<int> &dist) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.push(pair<int, int>(0, src));
//    dist[src] = 0;
//    while(!pq.empty()) {
//        pair<int, int> pairTemp = pq.top();
//        pq.pop();
//        int node = pairTemp.second;
//        int d = pairTemp.first;
//
//
//        for(int i = 0; i < graph[node].size(); ++i) {
//            if(d + graph[node][i].second < dist[graph[node][i].first]) {
//                dist[graph[node][i].first] = d + graph[node][i].second;
//                path[graph[node][i].first] = node;
//                pq.push(pair<int, int>(dist[graph[node][i].first], graph[node][i].first));
//            }
//        }
//    }
//}
//
//int findDist(int src, int end, vector<int> path, vector<int> dist) {
//    int d = dist[end];
//    int p;
//    for(int i = 0; i < path.size(); ++i) {
//        p = path[end];
//        while(p != -1) {
//            if(p == src) {
//                return d - dist[p];
//            }
//
//            p = path[p];
//        }
//    }
//
//    return -1;
//}