////
//// Created by ThucHD on 7/24/17.
////
//
//#include "VirtualFriends.h"
//#define MAX 200010
//
//int parent[MAX];
//int group[MAX];
//
//void VirtualFriends() {
//    int t, f;
//    int u, v;
//    string str1, str2;
//    map<string, int> m_Index;
//    int index;
//    cin >> t;
//
//    while(t > 0) {
//        cin >> f;
//
//        m_Index.clear();
//        index = 0;
//        for(int i = 0; i < f; ++i) {
//            cin >> str1 >> str2;
//
//            if(m_Index.find(str1) == m_Index.end()) {
//                m_Index[str1] = index;
//                parent[index] = index;
//                group[index] = 1;
//                ++index;
//            }
//
//            if(m_Index.find(str2) == m_Index.end()) {
//                m_Index[str2] = index;
//                parent[index] = index;
//                group[index] = 1;
//                ++index;
//            }
//            u = m_Index[str1];
//            v = m_Index[str2];
//            unionSet(u, v);
//            cout << max(group[parent[u]], group[parent[v]] ) << endl;
//        }
//
//        --t;
//    }
//}
//
//void unionSet(int u, int v) {
//    int up = findSet(u);
//    int vp = findSet(v);
//
//    if(parent[vp] != up)
//        group[up] += group[vp];
//    parent[vp] = up;
//}
//
//int findSet(int u) {
//    if(u != parent[u])
//        parent[u] = findSet(parent[u]);
//    return parent[u];
//}