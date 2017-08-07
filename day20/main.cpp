#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

//-------------------------------
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

//------------------------------
#define MAX 5000

struct Node {
    Node* children[MAX];
    int countLeaf;
};

int parent[MAX];
Node* newNode();
bool addWord(Node* root, string s);
void delNode(Node* root);
void unionSet(int u, int v);
int findSet(int u);
void runDijkstra(int src);
double calcDist(int src);
void runMST(int src);
double getDist();

struct Coordinate {
    long first;
    long second;

    Coordinate(long x, long y) {
        this->first = x;
        this->second = y;
    }
};

struct Info {
    int index;
    int val;
    Info(int a, int b) {
        index = a;
        val = b;
    }

};

int main() {
    Test1();
    return 0;
}

void Test1() {
    int n, h;

    vector<Info> v;
    vector<pair<int, int> > dup;
    vector<int> res;
    int prevVal = -1;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> h;
        v.push_back(Info(i + 1, h));
    }
    sort(v.begin(), v.end(), [](const Info &a, const Info &b) -> bool {
        return a.val < b.val;
    });

    for(int i = 0; i < n; ++i) {
        if(i != 0 && prevVal == v[i].val) {
            dup.push_back(make_pair(i - 1, i));
        }
        res.push_back(v[i].index);
        prevVal = v[i].val;
    }

    if(dup.size() < 2)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }

        cout << endl;
        for(int j = 0; j < 2; ++j) {
            pair<int, int> temp = *dup.begin();
            dup.erase(dup.begin());

            for (int i = 0; i < n; ++i) {
                if(temp.first == i) {
                    cout << res[i + 1] << " " << res[i] << " ";
                    ++i;
                    continue;
                }

                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
}


void Test2() {
    int t;
    long input;
    long level;
    long row, col, e;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cin >> input;
        level = (long)ceil(sqrt(input));
        row = level;
        col = level;
        e = level * (level - 1) + 1;

        if(level % 2 == 1) {
            if(input > e)
                col -= input - e;
            else
                row -= e - input;
        } else {
            if(input > e)
                row -= input - e;
            else
                col -= e - input;
        }
        cout << "Case " << i << ": " << col << " " << row << endl;
    }
}



vector<vector<pair<int, double> > > graph(MAX);
vector<double> dist;
vector<bool> visited;
vector<int> path;
const int INF = 1e9;
int n;
void Test3() {
    int t;
    double x, y, w;
    vector<pair<double, double> > vPair;
    pair<double, double> p1, p2;
    cin >> t;

    while(t > 0) {
        cin >> n;
//        graph = std::vector<vector<pair<int, double> > >(MAX, vector<pair<int, double> >());
        fill(graph.begin(), graph.end(), vector<pair<int, double> >());
        dist = vector<double>(MAX, INF);
        visited = vector<bool>(MAX, false);
        path = vector<int>(MAX, -1);
        vPair.clear();

        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            vPair.push_back(make_pair(x, y));
        }

        for(int i = 0; i < n; ++i) {
            p1 = vPair[i];
            for(int j = i + 1; j < n; ++j) {
                p2 = vPair[j];
                w = pow( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2), 0.5);
                graph[i].push_back(pair<int, double>(j, w));
                graph[j].push_back(pair<int, double>(i, w));
            }
        }

        runMST(0);
        double res = getDist();
        cout << fixed;
        cout << setprecision(2) << res << endl;
        --t;
        if(t != 0)
            cout << endl;
    }
}

void runMST(int src) {
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;
            double w = graph[u][i].second;
            if(!visited[v] && dist[v] > w) {
                dist[v] = w;
                path[v] = u;
                pq.push(make_pair(w, v));
            }
        }
    }
}

double getDist() {
    double res = 0;
    for(int i = 1; i <= n; ++i) {
        if(dist[i] != INF) {
            res += dist[i];
        }
    }

    return res;
}

void runDijkstra(int src) {
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
    pair<double, int> pTemp;
    pair<int, double> neighbor;
    int node;
    double d;

    pq.push(make_pair(0, src));
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
                path[graph[node][i].first] = node;
                pq.push(make_pair(dist[neighbor.first], neighbor.first));
            }
        }
    }
}

double calcDist(int src) {
    double res = 0;
    int p = src;

    while(p != -1) {
        res += dist[p];
        p = path[src];
    }

    return res;
}

void Test4() {
    int t, n;
    string phoneNum;
    set<string> s;
    bool flag;
    Node* root;
    cin >> t;
     while(t > 0) {
         cin >> n;

         root = newNode();
         s.clear();
         flag = true;
         for(int i = 0; i < n; ++i) {
             cin >> phoneNum;
             s.insert(phoneNum);
         }

         for(set<string>::iterator it = s.begin(); it != s.end(); ++it) {
             if(!addWord(root, *it)) {
                 cout << "NO" << endl;
                 flag = false;
                 break;
             }
         }

         if(flag)
             cout << "YES" << endl;

         delNode(root);
         --t;
     }
}

Node* newNode() {
    Node* n = new Node;

    for(int i = 0; i < MAX; ++i) {
        n->children[i] = NULL;
    }

    n->countLeaf = 0;
    return n;
}

bool addWord(Node* root, string s) {
    Node* temp = root;
    int ch;

    for(int i = 0; i < s.size(); ++i) {
        ch = s[i] - '0';

        if (temp->children[ch] == NULL) {
            temp->children[ch] = newNode();
        } else if(temp->children[ch]->countLeaf > 0)
            return false;

        temp = temp->children[ch];
    }
    temp->countLeaf++;
    return true;
}

void delNode(Node* root) {
    for(int i = 0; i < MAX; ++i) {
        if(root->children[i] != NULL)
            delNode(root->children[i]);
    }
    delete(root);
}


void Test5() {
    int n, m;
    int u, v;
    set<int> res;
    int t = 1;
    while (true) {
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        for(int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        res.clear();
        for(int i = 0; i < m; ++i) {
            cin >> u >> v;

            unionSet(u, v);
        }

        for(int i = 1; i <= n; ++i) {
            int par = findSet(i);
            res.insert(par);
        }

        cout << "Case " << t << ": " << res.size() << endl;
        ++t;
    }
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