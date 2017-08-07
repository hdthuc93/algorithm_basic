////
//// Created by ThucHD on 6/14/17.
////
//
//#include "PrayatnaPR.h"
//
//bool visited[100000];
//int path[100000];
//list<int> graph[100000];
//int n, e;
//
//void input() {
//    int t;
//    int c = 0;
//    int u, v;
//    cin >> t;
//
//    for(int k = 0; k < t; ++k) {
//        cin >> n;
//        cin >> e;
//
//        for(int i = 0; i < e; ++i) {
//            cin >> u >> v;
//            graph[u].push_back(v);
//            graph[v].push_back(u);
//        }
//
//        for(int i = 0; i < n; ++i) {
//            visited[i] = false;
//            path[i] = -1;
//        }
//
//        for(int i = 0; i < n; ++i) {
//            if(!visited[i]) {
//                runDFS(i);
//                ++c;
//            }
//        }
//
//        cout << c << endl;
//
//        // reset
//        c = 0;
//        for(int i = 0; i < n; ++i) {
//            graph[i].clear();
//            visited[i] = false;
//            path[i] = -1;
//        }
//    }
//}
//
//void runDFS(int src) {
//    stack<int> s;
//    s.push(src);
//    visited[src] = true;
//    list<int>::iterator i;
//    while(!s.empty()) {
//        src = s.top();
//        s.pop();
//
//        for(i = graph[src].begin(); i != graph[src].end(); ++i) {
//            if(!visited[*i]) {
//                s.push(*i);
//                visited[*i] = true;
//                path[*i] = src;
//            }
//        }
//    }
//}