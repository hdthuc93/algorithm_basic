#include "Dijkstra.h"
//
//#define MAX 1010
//
//struct MyJob{
//    int val;
//    bool myJob;
//};
//
//struct Point {
//    int x, y;
//};
//
//void QuesA();
//void QuesB();
//void QuesC();
//void QuesD();
//void runBFS();
//bool isInMatrix(Point pTemp);
//bool isNew(Point pTemp);
//void count();

int main() {
    QuesE();
    return 0;
}
//
//const int INF = 1e9;
//
//int Row, Col;
//
//short matrix[MAX][MAX];
//Point path[MAX][MAX];
//Point startP;
//Point endP;
//int cStep;
//void QuesD() {
//    int numOfR, numOfC, cEle;
//    int rBomb;
//    int xEle, yEle;
//
//    while(true) {
//        cin >> Row >> Col;
//        if(Row == 0 && Col == 0)
//            break;
//
//        cin >> rBomb;
//        memset(matrix, 0, sizeof(matrix[0][0]) * MAX * MAX);
//        memset(path, -1, sizeof(path[0][0]) * MAX * MAX);
//        cStep = 0;
//
//        for (int i = 0; i < rBomb; ++i) {
//            cin >> numOfR >> numOfC;
//
//            for (int i = 0; i < numOfC; ++i) {
//                cin >> cEle;
//                matrix[numOfR][cEle] = -1;
//            }
//        }
//        cin >> xEle >> yEle;
//        startP.x = xEle;
//        startP.y = yEle;
//
//        cin >> xEle >> yEle;
//        endP.x = xEle;
//        endP.y = yEle;
//
//        runBFS();
//        count();
//        cout << cStep << endl;
//    }
//}
//
//void runBFS() {
//    queue<Point> q;
//    q.push(startP);
//    matrix[startP.x][startP.y] = 1;
//    Point direct[4];
//    direct[0] = {-1, 0};
//    direct[1] = {1, 0};
//    direct[2] = {0, 1};
//    direct[3] = {0, -1};
//
//
//    while(!q.empty()) {
//        Point pTemp;
//        Point pCurrent = q.front();
//        q.pop();
//        for(int i = 0; i < 4; ++i) {
//            pTemp.x = pCurrent.x + direct[i].x;
//            pTemp.y = pCurrent.y + direct[i].y;
//
//            if(isInMatrix(pTemp) && isNew(pTemp)) {
//                matrix[pTemp.x][pTemp.y] = 1;
//                q.push(pTemp);
//                path[pTemp.x][pTemp.y] = pCurrent;
//            }
//        }
//    }
//}
//
//bool isInMatrix(Point pTemp) {
//    return (pTemp.x >= 0 && pTemp.x < Row && pTemp.y >= 0 && pTemp.y < Col);
//}
//
//bool isNew(Point pTemp) {
//    return (matrix[pTemp.x][pTemp.y] == 0);
//}
//
//void count() {
//    Point e = path[endP.x][endP.y];
//
//    while(true) {
//        ++cStep;
//        if(e.x == startP.x && e.y == startP.y) {
//            return;
//        }
//        e = path[e.x][e.y];
//    }
//}
//
//void QuesC() {
//    int k, n, w;
//    int borrow;
//    int m = 0;
//
//    cin >> k >> n >> w;
//
//    for(int i = 1; i <= w; ++i) {
//        m += i * k;
//    }
//
//    borrow = m - n;
//
//    if(borrow > 0)
//        cout << borrow << endl;
//    else
//        cout << 0 << endl;
//}
//
//void QuesB() {
//    int n;
//    int ch[26] = {0};
//    string str;
//    cin >> n;
//    cin >> str;
//    bool isFull = true;
//
//    for(int i = 0; i < n; ++i) {
//        if(str[i] >= 'A' && str[i] <= 'Z')
//            str[i] += 32;
//
//        ++ch[str[i] - 'a'];
//    }
//
//    for(int i = 0; i < 26; ++i) {
//        if(ch[i] == 0) {
//            isFull = false;
//            break;
//        }
//    }
//
//    if(isFull)
//        cout << "YES";
//    else
//        cout << "NO";
//}
//
//void QuesA() {
//    int tc;
//    int n, m;
//    int myVal, temp;
//    int c;
//    MyJob mjT;
//    vector<MyJob> v;
//    vector<MyJob> vT;
//    cin >> tc;
//
//    while(tc > 0) {
//        cin >> n >> m;
//        v.clear();
//        vT.clear();
//        c = 0;
//        for(int i = 0; i < n; ++i) {
//            cin >> temp;
//            mjT.val = temp;
//            mjT.myJob = false;
//
//            if(i == m)
//                mjT.myJob = true;
//
//            v.push_back(mjT);
//            vT.push_back(mjT);
//        }
//
//        sort(vT.begin(), vT.end(), [](const MyJob &mj1, const MyJob &mj2) -> bool {
//            return mj1.val > mj2.val;
//        });
//
//        while(true) {
//            if(v[0].val == vT[0].val && v[0].myJob) {
//                ++c;
//                break;
//            }
//
//            if(v[0].val == vT[0].val) {
//                ++c;
//                v.erase(v.begin());
//                vT.erase(vT.begin());
//            } else {
//                mjT = v[0];
//                v.erase(v.begin());
//                v.push_back(mjT);
//            }
//        }
//
//        cout << c << endl;
//        --tc;
//    }
//}