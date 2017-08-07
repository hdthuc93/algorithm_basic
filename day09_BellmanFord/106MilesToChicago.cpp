////
//// Created by ThucHD on 6/27/17.
////
//
//#include "106MilesToChicago.h"
//
//#define MAX 110
//
//struct Triad {
//    int source;
//    int target;
//    int weight;
//
//    Triad(int s, int t, int w) {
//        this -> source = s;
//        this -> target = t;
//        this -> weight = w;
//    }
//};
//
//const int INF = 1e9;
//vector<Triad> graph;
////vector<vector<pair<int, int> > > graph2;
//vector<int> dist;
//vector<int> path;
//vector<int> originWeight;
//int n, m;
//
//void MileToChicago() {
//    int a, b, p;
//    double res;
//
//    dist = vector<int>(MAX, INF);
//    path = vector<int>(MAX, -1);
//    graph.clear();
//    cin >> n >> m;
//
//
//    originWeight = vector<int>(MAX, -1);
//    for (int i = 0; i < m; ++i) {
//        cin >> a >> b >> p;
//
//        p = 100 - p;
//        graph.push_back(Triad(a, b, p));
//        graph.push_back(Triad(b, a, p));
//    }
//
//    runBellmanFord(1);
//    res = calcProbability() * 100;
//    cout << fixed;
//    cout << setprecision(6) << res << " percent" << endl;
//}
//
//void runBellmanFord(int src) {
//    int u, v, w;
//    dist[src] = 100;
//
//    for(int i = 0; i < n - 1; ++i) {
//        for(int j = 0; j < graph.size(); ++j) {
//            u = graph[j].source;
//            v = graph[j].target;
//            w = graph[j].weight;
//
//            if(dist[u] != INF && dist[u] + w < dist[v]) {
//                dist[v] = dist[u] + w;
//                path[v] = u;
//            }
//        }
//    }
//}
//
//double calcProbability() {
//    double res = 1;
//    double w;
//    int curPoint = n;
//    int prevPoint = n;
//
//    while(true) {
//        w = getWeight(curPoint, prevPoint);
//        if(w != -1)
//            res *= (100 - w) / 100;
//
//        if(curPoint == 1) {
//            break;
//        }
//        prevPoint = curPoint;
//        curPoint = path[curPoint];
//    }
//
//    return res;
//}
//
//double getWeight(int s, int t) {
//    int u, v;
//    double w = -1;
//
//    if(s == t)
//        return w;
//
//    for(int i = 0; i < graph.size(); ++i) {
//        u = graph[i].source;
//        v = graph[i].target;
//        if((u == s && v == t) || (u == t && v == s)) {
//            w = graph[i].weight;
//            break;
//        }
//    }
//
//    return w;
//}