//
// Created by ThucHD on 6/19/17.
//
//
//#include "TheShortestPath.h"
//
//#define MAX 10010
//const int INF = 1e9;
//map<string, int> listCityName;
//vector<vector<pair<int, int>>> graph;
//vector<int> dist;
//
//void TheShortestPath() {
//    int s, n, p, nr, cost, r;
//    string name, name1, name2;
//    cin >> s;
//    while(s > 0) {
//        // init
//        graph = std::vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
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
//
//        for(int i = 0; i < r; ++i) {
//            cin >> name1 >> name2;
//            dist = vector<int>(MAX, INF);
//            runDijkstra(listCityName[name1]);
//            cout << dist[listCityName[name2]] << endl;
//        }
//
//        --s;
//    }
//}
//
//void runDijkstra(int src) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.push(pair<int, int>(0, src));
//    dist[src] = 0;
//    while (!pq.empty()) {
//        pair<int, int> pairTemp = pq.top();
//        pq.pop();
//        int node = pairTemp.second;
//        int d = pairTemp.first;
//
//        for (int i = 0; i < graph[node].size(); ++i) {
//            if (d + graph[node][i].second < dist[graph[node][i].first]) {
//                dist[graph[node][i].first] = d + graph[node][i].second;
//                pq.push(pair<int, int>(dist[graph[node][i].first], graph[node][i].first));
//            }
//        }
//    }
//}
