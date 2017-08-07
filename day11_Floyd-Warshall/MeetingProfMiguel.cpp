//
// Created by ThucHD on 7/1/17.
//

#include "MeetingProfMiguel.h"
#define INF 1e5

vector<vector<int> > graph1;
vector<vector<int> > graph2;
vector<vector<int> > dist1;
vector<vector<int> > dist2;
int n;

void MeetingProfMiguel() {

    string res;

    char ch1, ch2, ch3, ch4;
    char from, to;
    int val;
    while (true) {
        cin >> n;
        if (n == 0)
            break;

        graph1 = std::vector<vector<int> > (26, vector<int>(26, INF));
        graph2 = std::vector<vector<int> > (26, vector<int>(26, INF));
        dist1 = std::vector<vector<int> > (26, vector<int>(26));
        dist2 = std::vector<vector<int> > (26, vector<int>(26));

        for (int i = 0; i < n; ++i) {
            cin >> ch1 >> ch2 >> ch3 >> ch4 >> val;

            if (ch1 == 'Y') {
                graph1[ch3 - 'A'][ch4 - 'A'] = val;

                if(ch2 == 'B')
                    graph1[ch4 - 'A'][ch3 - 'A'] = val;

            }
            else {
                graph2[ch3 - 'A'][ch4 - 'A'] = val;

                if (ch2 == 'B')
                    graph2[ch4 - 'A'][ch3 - 'A'] = val;

            }
        }
        cin >> from >> to;
        runFloydWarshall();

        res = getMinEnergy(from - 'A', to - 'A');

        cout << res << endl;
    }
}

void runFloydWarshall() {
    int i, j, k;

    for (i = 0; i < 26; ++i) {
        for (j = 0; j < 26; ++j) {
            if(i == j) {
                graph1[i][j] = 0;
                graph2[i][j] = 0;
            }

            dist1[i][j] = graph1[i][j];
            dist2[i][j] = graph2[i][j];
        }
    }

    for (k = 0; k < 26; ++k) {
        for (i = 0; i < 26; ++i) {
            for (j = 0; j < 26; ++j) {
                dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
                dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
            }
        }
    }
}

string getMinEnergy(int me, int prof) {
    int min = INF, dis;
    string res = "";
    set<char> nameCity;
    for (int i = 0; i < 26; ++i) {
        dis = dist1[me][i] + dist2[prof][i];
        if(min > dis) {
            min = dis;
            nameCity.clear();
            nameCity.insert(char('A' + i));
        } else if(min == dis && min < INF) {
            nameCity.insert(char('A' + i));
        }
    }

    if (min >= INF)
        res = "You will never meet.";
    else {
        res = to_string(min);

        for(set<char>::iterator i = nameCity.begin(); i != nameCity.end(); ++i) {
            res += string() + ' ' + *i;
        }
    }

    return res;
}
