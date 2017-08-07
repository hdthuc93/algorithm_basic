//
// Created by ThucHD on 6/17/17.
//
#include "MakingJumps.h"

int maps[10][10];
int area, maxPath;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};


void readInput() {
    int n;
    int skip, begin;
    int numCases = 1;
    int x_in, y_in;
    while(true) {
        cin >> n;
        if(n == 0)
            break;

        memset(maps, -1, sizeof(maps[0][0]) * 10 * 10);
        area = 0;
        maxPath = 0;
        x_in = -1;
        y_in = -1;

        for (int i = 0; i < n; ++i) {
            cin >> skip >> begin;

            for (int j = skip; j < skip + begin; ++j) {
                if(x_in == -1) {
                    x_in = i;
                    y_in = j;
                }

                maps[i][j] = 0;
                ++area;
            }
        }

        runDFS(x_in, y_in, 0);
        cout << "Case " << numCases << ", " << area - maxPath;
        if(area - maxPath == 1)
            cout << " square can not be reached." << endl;
        else
            cout << " squares can not be reached." << endl;

        ++numCases;
    }
}

void runDFS(int x_in, int y_in, int c) {
    int x_temp, y_temp;
    maps[x_in][y_in] = 1;
    ++c;
    bool isNext = false;

    for(int i = 0; i < 8; ++i) {
        x_temp = x_in + dx[i];
        y_temp = y_in + dy[i];
        if(x_temp >= 0 && y_temp >= 0 && x_temp < 10 && y_temp < 10 && maps[x_temp][y_temp] == 0) {
            isNext = true;
            runDFS(x_temp, y_temp, c);
        }
    }

    if(!isNext && c > maxPath)
        maxPath = c;

    maps[x_in][y_in] = 0;
}