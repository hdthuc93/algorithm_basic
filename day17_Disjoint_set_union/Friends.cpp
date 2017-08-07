////
//// Created by ThucHD on 7/19/17.
////
//
//#include "Friends.h"
//
//int parent[30010];
//
//void Friends() {
//    int t, n, m;
//    int maximum;
//    map<int, int> m_parent;
//    int a, b;
//    cin >> t;
//
//    while(t > 0) {
//        maximum = 0;
//        m_parent.clear();
//        cin >> n >> m;
//
//        for(int i = 1; i <= n; ++i) {
//            parent[i] = i;
//        }
//
//        for(int i = 0; i < m; ++i) {
//            cin >> a >> b;
//            unionSet(a, b);
//        }
//
//        for(int i = 1; i <= n; ++i) {
//            parent[i] = findSet(parent[i]);
//            m_parent[parent[i]]++;
//        }
//
//        for(map<int, int>::iterator it = m_parent.begin(); it != m_parent.end(); ++it) {
//            maximum = max(maximum, it->second);
//        }
//
//        cout << maximum << endl;
//        --t;
//    }
//}
//
//void unionSet(int u, int v) {
//    int up = findSet(u);
//    int vp = findSet(v);
//    parent[vp] = up;
//}
//
//int findSet(int u) {
//    if(u != parent[u])
//        parent[u] = findSet(parent[u]);
//
//    return parent[u];
//}