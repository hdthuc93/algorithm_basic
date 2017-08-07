//
// Created by ThucHD on 6/23/17.
//

#include "XYZZY.h"
#define MAX 2010

struct Triad {
    int source;
    int target;

    Triad(int s, int t) {
        this -> source = s;
        this -> target = t;
    }
};

const int INF = -1e9;
vector<Triad> graph;
vector<int> dist;
vector<int> energy;
int n;
void XYZZY() {

    int ene, nConnect, iRoom;
    while(true) {
        dist = vector<int>(MAX, INF);
        graph.clear();
        energy.clear();
        energy.push_back(0);

        cin >> n;

        if(n == -1)
            return;

        for(int i = 1; i <= n; ++i) {
            cin >> ene >> nConnect;
            energy.push_back(ene);

            for(int j = 0; j < nConnect; ++j) {
                cin >> iRoom;
                graph.push_back(Triad(i, iRoom));
            }
        }

        runBellmanFord(1);
        if(dist[n] == INF)
            cout << "hopeless" << endl;
        else if (!checkCycle())
            cout << "winnable" << endl;
        else if (isExistNegative())
            cout << "hopeless" << endl;
        else
            cout << "winnable" << endl;
    }
}

void runBellmanFord(int src) {
    int u, v, w;
    dist[src] = 100;

    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < graph.size(); ++j) {
            u = graph[j].source;
            v = graph[j].target;
            w = energy[graph[j].target];

            if(dist[u] > 0 && dist[u] + w > 0) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
}

bool isExistNegative() {
    for(int i = 1; i <= n; ++i) {
        if(dist[i] != INF && dist[i] <= 0)
            return true;
    }

    return false;
}

bool checkCycle() {
    int u, v, w;
    for(int j = 0; j < graph.size(); ++j) {
        u = graph[j].source;
        v = graph[j].target;
        w = energy[graph[j].target];

        if(dist[u] > 0 && dist[u] + w > dist[v]) {
            return false;
        }
    }

    return true;
}