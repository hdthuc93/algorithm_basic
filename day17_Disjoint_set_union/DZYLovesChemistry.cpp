//
// Created by ThucHD on 7/24/17.
//

#include "DZYLovesChemistry.h"

#define MAX 55

int parent[MAX];

void DZYLovesChemistry() {
    int n, m, c = 0;
    int u, v;
    long long res;
    set<int> s_distinct;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        unionSet(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        u = findSet(i);

        if(s_distinct.find(u) == s_distinct.end())
            s_distinct.insert(u);
        else
            ++c;
    }

    res = (long long)pow(2, c);
    cout << res << endl;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    parent[vp] = up;
}

int findSet(int u) {
    if(u != parent[u])
        parent[u] = findSet(parent[u]);
    return parent[u];
}