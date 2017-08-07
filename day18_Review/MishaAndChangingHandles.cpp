//
// Created by ThucHD on 7/22/17.
//

#include "MishaAndChangingHandles.h"

#define MAX 2010

int parent[MAX];
bool original[MAX];
bool newName[MAX];

void MishaAndChangingHandles() {
    int n, index = 0;
    string str1, str2;
    map<string, int> m_Index;
    string strArr[MAX];
    vector<string> v_res;
    cin >> n;

    while(n > 0) {
        cin >> str1 >> str2;

        if(m_Index.find(str1) == m_Index.end()) {
            m_Index[str1] = index;
            strArr[index] = str1;
            parent[index] = index;
            ++index;
        }

        if(m_Index.find(str2) == m_Index.end()) {
            m_Index[str2] = index;
            strArr[index] = str2;
            parent[index] = index;
            ++index;
        }

        unionSet(m_Index[str1], m_Index[str2]);
        --n;
    }

    for(int i = 0; i < index; ++i) {
        int u;
        if(newName[i]) {
            u = findSet(i);
            str1 = strArr[parent[i]] + " " + strArr[i];
            v_res.push_back(str1);
        }
    }
    n = (int)v_res.size();
    cout << n << endl;
    for(int i = 0; i < n; ++i) {
        cout << v_res[i] << endl;
    }
}

void unionSet(int u, int v) {
    if(u == parent[u])
        original[u] = true;
    original[v] = false;

    newName[u] = false;
    newName[v] = true;

    int up = findSet(u);
    int vp = findSet(v);
    parent[vp] = up;
}

int findSet(int u) {
    if(u != parent[u])
        parent[u] = findSet(parent[u]);
    return parent[u];
}