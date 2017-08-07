////
//// Created by ThucHD on 6/28/17.
////
//#include "Risk.h"
//
//#define MAX 105
//#define INF 1e9
//
//vector<vector<int> > graph;
//vector<vector<int> > dist;
//vector<vector<int> > path;
//int n = 21;
//
//void Risk() {
//    int testCase = 1;
//    int temp, ti;
//    int numQues, src, end;
//    while(cin >> temp) {
//        graph = std::vector<vector<int> >(n, vector<int>(n, INF));
//        dist = std::vector<vector<int> >(n, vector<int>(n));
//        path = std::vector<vector<int> >(n, vector<int>(n));
//
//        for (int j = 0; j < temp; ++j) {
//            cin >> ti;
//            graph[1][ti] = 1;
//            graph[ti][1] = 1;
//        }
//
//        for (int i = 2; i <= 19; ++i) {
//            cin >> temp;
//            for (int j = 0; j < temp; ++j) {
//                cin >> ti;
//                graph[i][ti] = 1;
//                graph[ti][i] = 1;
//            }
//        }
//
//        runFloydWarshall();
//        cout << "Test Set #" << testCase << ":" << endl;
//        cin >> numQues;
//        for (int i = 0; i < numQues; ++i) {
//            cin >> src >> end;
//            int res = coutPath(src, end);
//            string s = src > 9 ? to_string(src) : " " + to_string(src);
//            string e = end > 9 ? to_string(end) : " " + to_string(end);
//            cout << s << " to " << e << ": " << res << endl;
//        }
//        cout << endl;
//        ++testCase;
//    }
//}
//
//void runFloydWarshall() {
//    int i, j, k;
//
//    for (i = 1; i < n; ++i) {
//        for (j = 1; j < n; ++j) {
//            dist[i][j] = graph[i][j];
//
//            if (graph[i][j] != INF && i != j) {
//                path[i][j] = i;
//            } else {
//                path[i][j] = -1;
//            }
//        }
//    }
//    for(k = 1; k < n; ++k) {
//        for (i = 1; i < n; ++i) {
//            for (j = 1; j < n; ++j) {
//                if(dist[i][j] > dist[i][k] + dist[k][j]) {
//                    dist[i][j] = dist[i][k] + dist[k][j];
//                    path[i][j] = path[k][j];
//                }
//            }
//        }
//    }
//}
//
//int coutPath(int src, int end) {
//    int c = -1;
//    int curP = end;
//    while (true) {
//        ++c;
//        if(curP == src)
//            break;
//
//        curP = path[src][curP];
//    }
//    return c;
//}