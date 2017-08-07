
// Created by ThucHD on 7/13/17.
//

#include "ACMContestAndBlackout.h"

#define MAX 100010
#define INF 1000010

vector<pair<int, int> >graph[MAX];
vector<int> dist;
vector<int> path;
vector<bool> visited;
int n, m;

void ACMContestAndBlackout() {
    int t;
    int a, b, c;
    long res, minimum;

    cin >> t;
    while(t > 0) {
        cin >> n >> m;

        dist = vector<int>((unsigned long) n + 1, INF);
        path = vector<int>((unsigned long) n + 1, -1);
        visited = vector<bool>((unsigned long) n + 1, false);

        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> c;

            graph[a].push_back(make_pair(b, c));
            graph[b].push_back(make_pair(a, c));
        }

        runMST(1, -1, -1);
        res = getDist();
        cout << res << " ";

        minimum = INF;
        for(int i = 2; i <= n; ++i) {
            fill(dist.begin(), dist.end(), INF);
            fill(visited.begin(), visited.end(), false);
            runMST(1, i, path[i]);
            res = getDist();
            minimum = min(res, minimum);
        }
        cout << minimum << endl;

        for(int i = 0; i <= n; ++i) {
            graph[i].clear();
        }

        --t;
    }
}

void runMST(int src, int exNode1, int exNode2) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if((u == exNode1 && v == exNode2) || v == exNode1 && u == exNode2)
                continue;

            if(!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(w, v));
                if(exNode1 == -1 && exNode2 == -1)
                    path[v] = u;
            }
        }
    }
}

long getDist() {
    long res = 0;
    for(int i = 1; i <= n; ++i) {
        if(dist[i] == INF) {
            return INF;
        }
        res += dist[i];
    }

    return res;
}