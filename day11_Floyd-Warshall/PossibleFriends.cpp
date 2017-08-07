////
//// Created by ThucHD on 6/28/17.
////
//
//#include "PossibleFriends.h"
//
//#define INF 1e9
//
//vector<vector<int> > graph;
//vector<vector<int> > dist;
//int m;
//
//void PossibleFriends() {
//    int t;
//    string strTemp;
//    PosFriend max;
//    cin >> t;
//    while(t > 0) {
//        cin >> strTemp;
//        m = (int)strTemp.size();
//
//        graph = std::vector<vector<int> >(m, vector<int>(m, INF));
//        dist = std::vector<vector<int> >(m, vector<int>(m));
//
//        for(int i = 0; i < m; ++i) {
//            for(int j = 0; j < m; ++j) {
//                if(strTemp[j] == 'Y')
//                    graph[i][j] = 1;
//                else
//                    graph[i][j] = INF;
//            }
//
//            if(i == m - 1)
//                break;
//
//            cin >> strTemp;
//        }
//
//        runFloydWarshall();
//        max = findMaxPossibleFriend();
//        cout << max.index << " " << max.quantity << endl;
//
//        --t;
//    }
//}
//
//void runFloydWarshall() {
//    int i, j, k;
//
//    for (i = 0; i < m; ++i) {
//        for (j = 0; j < m; ++j) {
//            dist[i][j] = graph[i][j];
//        }
//    }
//    for(k = 0; k < m; ++k) {
//        for (i = 0; i < m; ++i) {
//            for (j = 0; j < m; ++j) {
//                if(i != j && dist[i][j] > dist[i][k] + dist[k][j]) {
//                    dist[i][j] = dist[i][k] + dist[k][j];
//                }
//            }
//        }
//    }
//}
//
//PosFriend findMaxPossibleFriend() {
//    PosFriend max;
//    max.index = 0;
//    max.quantity = 0;
//    int c;
//    for(int i = 0; i < m; ++i) {
//        c = 0;
//        for(int j = 0; j < m; ++j) {
//            if(dist[i][j] == 2)
//                ++c;
//        }
//
//        if(c > max.quantity) {
//            max.quantity = c;
//            max.index = i;
//        }
//    }
//
//    return max;
//}