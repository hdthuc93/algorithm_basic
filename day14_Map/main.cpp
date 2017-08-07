#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <string.h>
#include <queue>

using namespace std;

void HistoryExam();

void IsenbaevsNumber();
void runDijkstra(int src, vector<vector<pair<int, int> > > &graph, vector<int> &dist);

void Megacity();
void TestTask();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    TestTask();
    return 0;
}

void TestTask() {
    int n;
    string str1, str2, str3;
    map<string, string> usersTable;
    map<string, bool> usersStatus;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> str1;
        if(str1 == "logout")
            cin >> str2;
        else
            cin >> str2 >> str3;

        if(str1 == "register") {
            if(usersTable.find(str2) == usersTable.end()) {
                usersTable[str2] = str3;
                usersStatus[str2] = false;
                cout << "success: new user added" << endl;
            } else {
                cout << "fail: user already exists" << endl;
            }
        } else if(str1 == "login") {
            if(usersTable.find(str2) == usersTable.end()) {
                cout << "fail: no such user" << endl;
            } else if(usersTable[str2] != str3){
                cout << "fail: incorrect password" << endl;
            } else if(usersStatus[str2]) {
                cout << "fail: already logged in" << endl;
            } else {
                usersStatus[str2] = true;
                cout << "success: user logged in" << endl;
            }
        } else {
            if(usersTable.find(str2) == usersTable.end()) {
                cout << "fail: no such user" << endl;
            } else if(!usersStatus[str2]) {
                cout << "fail: already logged out" << endl;
            } else {
                usersStatus[str2] = false;
                cout << "success: user logged out" << endl;
            }
        }
    }
}

// Megacity: http://codeforces.com/problemset/problem/424/B
void Megacity() {
    int n, s;
    int x, y, p;
    double dist;
    multimap<double, int> m;
    multimap<double, int>::iterator m_it;

    cin >> n >> s;

    for(int i = 0; i < n; ++i) {
        cin >> x >> y >> p;
        dist = pow(x*x + y*y, 0.5);
        m.insert(pair<double, int>(dist, p));
    }

    cout << fixed;
    for(m_it = m.begin(); m_it != m.end(); ++m_it) {
        s += m_it->second;
        if(s >= 1000000) {
            cout << setprecision(7) << m_it->first;
            return;
        }
    }

    cout << -1;
}

//History exam: http://acm.timus.ru/problem.aspx?space=1&num=1196
void HistoryExam() {
    int n, m;
    int i = 0;
    int temp, res = 0;
    map<int, int> mYear;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        mYear[temp] = 0;
    }

    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> temp;

        if(mYear.find(temp) != mYear.end()) {
            ++res;
        }
    }

    cout << res;
}

// Isenbaev's Number: http://acm.timus.ru/problem.aspx?space=1&num=1837
void IsenbaevsNumber() {
    int n, nGraph;
    string iDist;
    int rootIndex = -1;
    int c = 1;
    vector<string> vStr;
    vector<int> dist(310, 1e9);
    vector<vector<pair<int, int>>> graph(310, vector<pair<int, int>>());

    string str1, str2 = "", str3;
    map<string, int> m;

    cin >> n;
    for(int i = 0; i < 3 * n; ++i) {
        cin >> str1;

        vStr.push_back(str1);

        if(m.find(str1) == m.end())
            m[str1] = i;

        if(str1 == "Isenbaev" && rootIndex == -1)
            rootIndex = i;
    }

    nGraph = (int)vStr.size();
//    memset(graph, -1, sizeof(graph));
    for(int i = 2; i < 3 * n; i += 3) {
        str1 = vStr[i-2];
        str2 = vStr[i-1];
        str3 = vStr[i];

        graph[m[str1]].push_back(pair<int, int>(m[str2], 1));
        graph[m[str2]].push_back(pair<int, int>(m[str1], 1));

        graph[m[str1]].push_back(pair<int, int>(m[str3], 1));
        graph[m[str3]].push_back(pair<int, int>(m[str1], 1));

        graph[m[str2]].push_back(pair<int, int>(m[str3], 1));
        graph[m[str3]].push_back(pair<int, int>(m[str2], 1));
    }

    if(rootIndex != -1)
        runDijkstra(rootIndex, graph, dist);

    for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        if(dist[it->second] == 1e9)
            iDist = "undefined";
        else
            iDist = to_string(dist[it->second]);

        cout << it->first << " " << iDist << endl;
    }
}

void runDijkstra(int src, vector<vector<pair<int, int> > > &graph, vector<int> &dist) {
    priority_queue<pair<int, int>> pq;

    pq.push(pair<int, int>(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        pair<int, int> pairTemp = pq.top();
        pq.pop();

        int node = pairTemp.second;
        int d = pairTemp.first;

        for(int i = 0; i < graph[node].size(); ++i) {
            pair<int, int> neighbor = graph[node][i];
            if(d + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = d + neighbor.second;
                pq.push(pair<int, int>(dist[neighbor.first], neighbor.first));
            }
        }
    }
}
