////
//// Created by ThucHD on 6/14/17.
////
//
//#include "BishuAndGirlfriend.h";
//
//bool visited[1001];
//int path[1001];
//list<int> graph[1001];
//int location[1001] = {0};
//int n, q;
//
//void input() {
//
//    int u, v;
//    int temp;
//    cin >> n;
//
//    for(int i = 0; i < n-1; ++i) {
//        cin >> u >> v;
//        graph[u].push_back(v);
//        graph[v].push_back(u);
//    }
//
//    cin >> q;
//
//    for(int i = 0; i < q; ++i) {
//        cin >> temp;
//        ++location[temp];
//    }
//
//    runDFS(1);
//}
//
//void runDFS(int src) {
//    stack<int> s;
//    s.push(src);
//    for(int i = 1; i <= n; ++i) {
//        visited[i] = false;
//        path[i] = -1;
//    }
//
//    list<int>::iterator i;
//    while(!s.empty()) {
//        src = s.top();
//        s.pop();
//        if(location[src] != 0) {
//            cout << src << endl;
//            return;
//        }
//        for(i = graph[src].begin(); i != graph[src].end(); ++i) {
//            if(!visited[*i]) {
//                s.push(*i);
//                visited[*i] = true;
//                path[*i] = src;
//            }
//        }
//    }
//}
//
//void printPath(int s, int d, int back[]) {
//    vector<int> res;
//
//    int current = d;
//
//    while(true) {
//        res.push_back(current);
//        if(current == s) {
//            break;
//        }
//
//        current = back[current];
//
//    }
//
//    for(int i = (int)res.size() - 1; i >= 0; --i) {
//        cout << res[i] << " ";
//    }
//}