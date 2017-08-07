//
// Created by ThucHD on 6/20/17.
//

#include "SendingEmail.h"
#define MAX 20010
const int INF = 1e9;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void SendingEmail() {
    int N, n, m, S, T;
    int s1, s2, w;
    int iTestCase = 1;
    int d;
    cin >> N;

    while(iTestCase <= N) {
        cin >> n >> m >> S >> T;
        graph = std::vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
        dist = vector<int>(MAX, INF);

        for(int i = 0; i < m; ++i) {
            cin >> s1 >> s2 >> w;
            graph[s1].push_back(pair<int, int>(s2, w));
            graph[s2].push_back(pair<int, int>(s1, w));
        }

        runDijkstra(S);
        d = dist[T];

        cout << "Case #" << iTestCase << ": ";
        if(d == INF)
            cout << "unreachable" << endl;
        else
            cout << d << endl;

        ++iTestCase;
    }
}

void runDijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pair<int, int> pTemp, neighbor;
    int node, d;

    pq.push(pair<int, int>(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        pTemp = pq.top();
        pq.pop();

        node = pTemp.second;
        d = pTemp.first;

        for(int i = 0; i < graph[node].size(); ++i) {
            neighbor = graph[node][i];
            if(d + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = d + neighbor.second;
                pq.push(pair<int, int>(dist[neighbor.first], neighbor.first));
            }
        }
    }
}