//
// Created by ThucHD on 6/24/17.
//

#include "Dijkstra.h"
#define MAX 16010

const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist;
int n, m;

void QuesE() {
    int t, T, ti = 1;
    int u, v, w;

    cin >> T;
    while(ti <= T) {
        graph = std::vector<vector<pair<int, int> > >(MAX, vector<pair<int, int> >());
        dist = vector<int>(MAX, INF);
        cin >> n >> m;
        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            graph[u].push_back(pair<int, int>(v, w));
            graph[v].push_back(pair<int, int>(u, w));
        }
        cin >> t;
        cout << "Case " << ti << ":" << endl;
        runDijkstra(t);
        for(int i = 0; i < n; ++i) {
            if(dist[i] != INF)
                cout << dist[i] << endl;
            else
                cout << "Impossible" << endl;
        }
        ++ti;
    }
}

void runDijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pair<int, int> pTemp, neighbor;
    int node, d, dMax;

    pq.push(pair<int, int>(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        pTemp = pq.top();
        pq.pop();

        node = pTemp.second;
        d = pTemp.first;

        for(int i = 0; i < graph[node].size(); ++i) {
            neighbor = graph[node][i];
            dMax = max(d, neighbor.second);
            if(dMax < dist[neighbor.first]) {
                dist[neighbor.first] = dMax;
                pq.push(pair<int, int>(dist[neighbor.first], neighbor.first));
            }
        }
    }
}

