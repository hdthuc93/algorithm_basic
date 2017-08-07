////
//// Created by ThucHD on 6/13/17.
////
//
//#include "guilty_prince_lightoj.h"
//
//#define MAX 20
//
//int Row, Col;
//bool visited[MAX][MAX];
//short matrix[MAX][MAX];
//int cStep = 0;
//Point in = {-1, -1};
//
//void GuiltyPrince() {
//    int t;
//    string temp;
//    cin >> t;
//
//    for(int i = 0; i < t; ++i) {
//        cin >> Col >> Row;
//
//        for(int j = 0; j < Row; ++j) {
//            cin >> temp;
//            for(int k = 0; k < Col; ++k) {
//                if(temp[k] == '#')
//                    matrix[j][k] = 0;
//                else {
//                    matrix[j][k] = 1;
//
//                    if(in.r == -1 && temp[k] == '@') {
//                        in.r = j;
//                        in.c = k;
//                    }
//                }
//            }
//        }
//
//        runBFS();
//
//        // print result
//        cout << "Case " << i + 1 << ": " << cStep << endl;
//
//        // reset
//        in.r = -1;
//        in.c = -1;
//        for(int j = 0; j < Row; ++j) {
//            for(int k = 0; k < Col; ++k) {
//                cStep = 0;
//                matrix[j][k] = 0;
//                visited[j][k] = false;
//            }
//        }
//    }
//}
//
//
//void runBFS() {
//    queue<Point> q;
//    q.push(in);
//    Point direct[4];
//    direct[0] = {-1, 0};
//    direct[1] = {1, 0};
//    direct[2] = {0, 1};
//    direct[3] = {0, -1};
//
//
//    for(int j = 0; j < Row; ++j) {
//        for(int k = 0; k < Col; ++k) {
//            visited[j][k] = false;
//        }
//    }
//
//    visited[in.r][in.c] = true;
//
//    while(!q.empty()) {
//        Point pTemp;
//        Point pCurrent = q.front();
//        q.pop();
//        ++cStep;
//
//        for(int i = 0; i < 4; ++i) {
//            pTemp.r = pCurrent.r + direct[i].r;
//            pTemp.c = pCurrent.c + direct[i].c;
//
//            if(isInMatrix(pTemp) && isNew(pTemp)) {
//                visited[pTemp.r][pTemp.c] = true;
//                q.push(pTemp);
//            }
//        }
//    }
//}
//
//bool isInMatrix(Point pTemp) {
//    return (pTemp.r >= 0 && pTemp.r < Row && pTemp.c >= 0 && pTemp.c < Col);
//}
//
//bool isNew(Point pTemp) {
//    return (matrix[pTemp.r][pTemp.c] == 1 && !visited[pTemp.r][pTemp.c]);
//}