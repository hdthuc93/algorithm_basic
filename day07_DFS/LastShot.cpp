////
//// Created by ThucHD on 6/16/17.
////
//
//#include "LastShot.h"
//
//bool visited[10005];
//int path[10005];
//list<int> graph[10005];
//int n, e;
//int maxPath = 0;
//
//void readInput() {
//    int u, v;
//
//    cin >> n;
//    cin >> e;
//
//    for(int i = 0; i < e; ++i) {
//        cin >> u >> v;
//        graph[u].push_back(v);
//    }
//
//    for(int i = 1; i <= n; ++i) {
//        visited[i] = false;
//        path[i] = -1;
//    }
//
//    for(int i = 1; i <= n; ++i) {
//        runDFS(i);
//    }
//
//    cout << maxPath << endl;
//}
//
//void runDFS(int src) {
//    int numOfPath = 0;
//    stack<int> s;
//    s.push(src);
//    visited[src] = true;
//    list<int>::iterator i;
//    while(!s.empty()) {
//        src = s.top();
//        s.pop();
//        ++numOfPath;
//        for(i = graph[src].begin(); i != graph[src].end(); ++i) {
//            if(!visited[*i]) {
//                s.push(*i);
//                visited[*i] = true;
//                path[*i] = src;
//            }
//        }
//    }
//
//    for(int i = 1; i <= n; ++i) {
//        visited[i] = false;
//    }
//
//    if(numOfPath > maxPath)
//        maxPath = numOfPath;
//}