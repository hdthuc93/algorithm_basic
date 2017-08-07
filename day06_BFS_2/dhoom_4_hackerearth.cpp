//
// Created by ThucHD on 6/12/17.
//

#include "dhoom_4_hackerearth.h";

struct Node {
    unsigned long long res;
    int c;
};

int n;
unsigned long long mainKey, locksKey;
unsigned long long otherKey[1000];
bool visited[100000] = {false};

void input() {
    cin >> mainKey >> locksKey;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> otherKey[i];
    }
}

void BFS() {
    queue<Node> q;
    Node cur;
    Node temp;
    temp.res = mainKey;
    temp.c = 0;
    q.push(temp);

    while(!q.empty()) {
        cur = q.front();
        q.pop();

        for(int i = 0; i < n; ++i) {
            Node t;
            t.res = (cur.res*otherKey[i]) % 100000;
            t.c = cur.c + 1;

            if(t.res == locksKey) {
                cout << t.c;
                return;
            }
            if(!visited[t.res]) {
                q.push(t);
                visited[t.res] = true;
            }
        }
    }
    cout << -1;
}