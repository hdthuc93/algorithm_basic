////
//// Created by ThucHD on 7/12/17.
////
//
////
//// Created by ThucHD on 7/12/17.
////
//
//
//#include "RoadConstruction.h"
//
//#define MAX 300010
//#define INF 1000010
//
//
//struct Info {
//    string city1;
//    string city2;
//
//    bool operator<(const Info &o)  const {
//        return this->city1 + this->city2 < o.city1 + o.city2;
//    }
//
//};
//
//vector<pair<int, int> >graph[MAX];
//vector<int> dist;
//vector<int> path;
//vector<bool> visited;
//
//int n, m;
//
//void RoadConstruction() {
//    int t;
//    string str1, str2;
//    int c;
//    int nodeIndex;
//    long res;
//    map<string, int> m_street;
//    map<Info, int> m_bistreet;
//    Info info;
//    cin >> t;
//
//    for(int iT = 1; iT <= t; ++iT) {
//        cin >> m;
//
//        m_street.clear();
//        m_bistreet.clear();
//
//        nodeIndex = 0;
//
//        for(int i = 0; i < m; ++i) {
//            cin >> str1 >> str2 >> c;
//
//            if(m_street.find(str1) == m_street.end()) {
//                m_street[str1] = nodeIndex;
//                nodeIndex++;
//            }
//
//            if(m_street.find(str2) == m_street.end()) {
//                m_street[str2] = nodeIndex;
//                nodeIndex++;
//            }
//
//            info.city1 = str1.compare(str2) < 0 ? str1 : str2;
//            info.city2 = str1.compare(str2) < 0 ? str2 : str1;
//
//            if(m_bistreet.find(info) == m_bistreet.end()) {
//                m_bistreet[info] = c;
//            } else if (m_bistreet[info] > c) {
//                m_bistreet[info] = c;
//            }
//        }
//
//        for(map<Info, int>::iterator it = m_bistreet.begin(); it != m_bistreet.end(); ++it) {
//            info = it->first;
//            graph[m_street[info.city1]].push_back(make_pair(m_street[info.city2], it->second));
//            graph[m_street[info.city2]].push_back(make_pair(m_street[info.city1], it->second));
//        }
//
//        n = (int)m_street.size();
//        dist = vector<int>((unsigned long)n, INF);
//        path = vector<int>((unsigned long)n, -1);
//        visited = vector<bool>((unsigned long)n, false);
//
//        runMST(0);
//        res = getDist();
//        if(res == -1)
//            cout << "Case " << iT << ": " << "Impossible" << endl;
//        else
//            cout << "Case " << iT << ": " << res << endl;
//
//        // clear graph
//        for(int i = 0; i < n; ++i) {
//            graph[i].clear();
//        }
//    }
//}
//
//void runMST(int src) {
//    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
//    pq.push(make_pair(0, src));
//    dist[src] = 0;
//
//    while(!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//        visited[u] = true;
//
//        for(int i = 0; i < graph[u].size(); ++i) {
//            int v = graph[u][i].first;
//            int w = graph[u][i].second;
//            if(!visited[v] && dist[v] > w) {
//                dist[v] = w;
//                path[v] = u;
//                pq.push(make_pair(w, v));
//            }
//        }
//    }
//}
//
//long getDist() {
//    long res = 0;
//    for(int i = 0; i < n; ++i) {
//        if(dist[i] == INF) {
//            return -1;
//        }
//        res += dist[i];
//    }
//
//    return res;
//}