////
//// Created by ThucHD on 7/19/17.
////
//
//#include "NetworkConnections.h"
//
//
//vector<int> parent;
//void NetworkConnections() {
//    int t, n;
//    string str;
//    char ch;
//    int con1, con2;
//    int success, unsuccess;
//    cin >> t;
//
//    while(t > 0) {
//        cin >> n;
//        success = 0;
//        unsuccess = 0;
//        parent = vector<int>(n + 1);
//
//        for(int i = 1; i <= n; ++i) {
//            parent[i] = i;
//        }
//
//        getchar();
//        while(getline(cin, str)) {
//            if(str.size() == 0)
//                break;
//            stringstream os(str);
//            os >> ch >> con1 >> con2;
//
//            if(ch == 'c')
//                unionSet(con1, con2);
//            else {
//                int up = findSet(con1);
//                int vp = findSet(con2);
//
//                if(up == vp)
//                    ++success;
//                else
//                    ++unsuccess;
//            }
//        }
//        cout << success << "," << unsuccess << endl;
//        --t;
//        if(t > 0)
//            cout << endl;
//    }
//}
//
//void unionSet(int u, int v) {
//    int up = findSet(u);
//    int vp = findSet(v);
//    parent[vp] = up;
//
//}
//
//int findSet(int u) {
//    while(u != parent[u]) {
//        u = parent[u];
//    }
//    return u;
//}