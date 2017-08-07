////
//// Created by ThucHD on 7/1/17.
////
//
//#include "ThunderMountain.h"
//#define MAX 1034
//#define INF 1e9
//
//vector<vector<double> > graph;
//vector<vector<double> > dist;
//vector<vector<int> > path;
//int n = 0;
//
//void ThunderMountain() {
//    int nTestCase, iTC = 1;
//    int x_asis[1024], y_asis[1024];
//    double tDist, res;
//    cin >> nTestCase;
//
//    while(iTC <= nTestCase) {
//        cin >> n;
//        graph = std::vector<vector<double> >(n, vector<double>(n, INF));
//        dist = std::vector<vector<double> >(n, vector<double>(n));
//        path = std::vector<vector<int> >(n, vector<int>(n));
//
//        for(int i = 0; i < n; ++i) {
//            cin >> x_asis[i] >> y_asis[i];
//        }
//
//        for(int i = 0; i < n; ++i) {
//            for(int j = 0; j < n; ++j) {
//                if(i == j)
//                    continue;
//
//                tDist = sqrt(pow(x_asis[i] - x_asis[j], 2) + pow(y_asis[i] - y_asis[j], 2));
//
//                if(tDist <= 10.0) {
//                    graph[i][j] = tDist;
//                }
//            }
//        }
//        runFloydWarshall();
//        res = getCost();
//        cout << "Case #" << iTC << ":" << endl;
//        cout << fixed;
//        if(res == -1)
//            cout << "Send Kurdy" << endl;
//        else
//            cout << setprecision(4) << floor(res * 10000 + 0.5) / 10000 << endl;
//
//        cout << endl;
//        ++iTC;
//    }
//}
//
//void runFloydWarshall() {
//    int i, j, k;
//
//    for (i = 0; i < n; ++i) {
//        for (j = 0; j < n; ++j) {
//            dist[i][j] = graph[i][j];
//
//            if (graph[i][j] != INF && i != j) {
//                path[i][j] = i;
//            } else {
//                path[i][j] = -1;
//            }
//        }
//    }
//    for(k = 0; k < n; ++k) {
//        for (i = 0; i < n; ++i) {
//            for (j = 0; j < n; ++j) {
//                if(dist[i][j] > dist[i][k] + dist[k][j]) {
//                    dist[i][j] = dist[i][k] + dist[k][j];
//                    path[i][j] = path[k][j];
//                }
//            }
//        }
//    }
//}
//
//double getCost() {
//    double res = -1;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if(dist[i][j] == INF) {
//                res = -1;
//                break;
//            }
//
//            res = res < dist[i][j] ? dist[i][j] : res;
//        }
//    }
//
//    return res;
//}