#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <string.h>

using namespace std;

void DistinctCount();
void MonkAndHisFriends();
void MinimumLoss();
void AndysFirstDictionary();
void HardwoordSpecies();

int main() {
    HardwoordSpecies();
    return 0;
}

void HardwoordSpecies() {
    int t;
    int countDup[10010];
    int i, numOfTrees;
    string strTemp;
    double res;
    multiset<string> ms;
    set<string> s;
    multiset<string>::iterator ms_it;
    set<string>::iterator s_it;
    cin >> t;
    getline(cin, strTemp);
    while(t >= 0) {
        i = 0;
        numOfTrees = 0;
        ms.clear();
        s.clear();
        while(getline(cin, strTemp)) {
            if(strTemp.size() <= 0)
                break;

            ms.insert(strTemp);
            s.insert(strTemp);
            ++numOfTrees;
        }

        strTemp = "";
        for(ms_it = ms.begin(); ms_it != ms.end(); ++ms_it) {
            if(strTemp == "") {
                strTemp = *ms_it;
                countDup[i] = 1;
                continue;
            }

            if(strTemp != *ms_it) {
                ++i;
                countDup[i] = 1;
            } else {
                ++countDup[i];
            }
            strTemp = *ms_it;
        }

        i = 0;
        for(s_it = s.begin(); s_it != s.end(); ++s_it) {
            res = floor( ( ( (countDup[i]) * 1.0e6) / numOfTrees) + 0.5 ) / 1.0e4;
            cout << fixed;
            cout << setprecision(4) << *s_it << " " << res << endl;
            ++i;
        }

        cout << endl;
        --t;
    }
}

void HardwoordSpecies3() {
    int t;
    int countDup[10010];
    int i, numOfTrees;
    string strTemp;
    double res;

    set<pair<string, int> > s;

    set<string>::iterator s_it;

    cin >> t;
    getline(cin, strTemp);

    while(t >= 0) {
        i = 0;
        numOfTrees = 0;

        s.clear();
        while(getline(cin, strTemp)) {
            if(strTemp.size() <= 0)
                break;


            s.insert(pair<string, int>(strTemp, 1));
            ++numOfTrees;
        }

        i = 0;
        for(s_it = s.begin(); s_it != s.end(); ++s_it) {
            res = floor( ( ( (countDup[i]) * 1.0e6) / numOfTrees) + 0.5 ) / 1.0e4;
            cout << fixed;
            cout << setprecision(4) << *s_it << " " << res << endl;
            ++i;
        }

        cout << endl;
        --t;
    }
}

void HardwoordSpecies2() {
    int t, iTC = 0;
    int numOfTrees;
    string strTemp;
    double res;

    map<string, int> m;
    map<string, int>::iterator m_it;
    cin >> t;

    getline(cin, strTemp);
    while(iTC <= t) {
        numOfTrees = 0;
        m.clear();
        while(getline(cin, strTemp)) {
            if(strTemp.size() <= 0)
                break;

            if(m.find(strTemp) == m.end())
                m[strTemp] = 1;
            else
                ++m[strTemp];

            ++numOfTrees;
        }

        for(m_it = m.begin(); m_it != m.end(); ++m_it) {
            res = floor( ( ( (m_it->second) * 1.0e6) / numOfTrees) + 0.5 ) / 1.0e4;
            cout << fixed;
            cout << setprecision(4) << m_it->first << " " << res << endl;
        }

        if(iTC != 0)
            cout << endl;

        ++iTC;
    }
}

//Andy's first dictionary: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1756
void AndysFirstDictionary() {
    set<string> s;
    string temp, word;

    while(cin >> temp) {
        word.clear();
        for(int i = 0; i < temp.size(); ++i) {
            if(temp[i] >= 'A' && temp[i] <= 'Z') {
                word.push_back((char)(temp[i] + 32));
            } else if(temp[i] >= 'a' && temp[i] <= 'z') {
                word.push_back(temp[i]);
            } else {
                if(word.size() > 0) {
                    s.insert(word);
                    cout << word << endl;
                    word.clear();
                }
            }
        }

        if(word.size() > 0) {
            s.insert(word);
        }
    }

    for(set<string>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }
}

// https://www.hackerrank.com/contests/womens-codesprint-2/challenges/minimum-loss
struct Price {
    long long val;
    int index;
};

bool operator<(const Price &a, const Price &b)
{
    return a.val < b.val;
}

void MinimumLoss() {
    int n;

    long long temp, min = 1e16 + 5;
    Price tPrice;
    set<Price> p;
    set<Price>::iterator it;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        tPrice.val = temp;
        tPrice.index = i;
        p.insert(tPrice);
    }

    for(it = next(p.begin()); it != p.end(); ++it) {
        if(min > (it->val - (prev(it))->val) && it->index < (prev(it))->index)
            min = it->val - (prev(it))->val;
    }
    cout << min;
}

void MonkAndHisFriends() {
    int t, n, m;
    long temp, s;
    set<long> a;
    long v[10010];
    cin >> t;
    while(t > 0) {
        cin >> n >> m;
        a.clear();

        for(int i = 0; i < n; ++i) {
            cin >> temp;
            a.insert(temp);
        }

        for(int i = 0; i < m; ++i) {
            cin >> v[i];
        }

        for(int i = 0; i < m; ++i) {
            s = a.size();
            a.insert(v[i]);

            if(a.size() == s) {
                cout << "YES" << endl;
            } else
                cout << "NO" << endl;
        }

        --t;
    }
}

void DistinctCount() {
    int t, n, x;
    int temp, len;
    set<int> a;

    cin >> t;
    while(t > 0) {
        cin >> n >> x;
        a.clear();
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            a.insert(temp);
        }
        len = (int)a.size();

        if(len == x)
            cout << "Good" << endl;
        else if(len > x)
            cout << "Average" << endl;
        else
            cout << "Bad" << endl;
        --t;
    }
}
