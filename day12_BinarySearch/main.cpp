#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1000010
void Marble();

void Pizzamania();
void Pizzamania2();
int binarySearchForPizzamania(int listNum[], int l, int n, int num);

void HackTheRandomNumberGenerator();
void HackTheRandomNumberGenerator2();
bool binarySearch(int listNum[], int n, int num);

void EKO();
int binarySearchForEKO(int n, int num);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Pizzamania2();
    return 0;
}

// Pizzamania: http://www.spoj.com/problems/OPCPIZZA/
void Pizzamania() {
    int t, n, m;
    int c;
    int listNum[100010];

    cin >> t;
    while(t > 0) {
        cin >> n >> m;
        c = 0;

        for(int i = 0; i < n; ++i) {
            cin >> listNum[i];
        }
        sort(listNum, listNum + n);

        for(int i = 0; i < n; ++i) {
            if(binarySearchForPizzamania(listNum, i + 1, n, m - listNum[i])) {
                ++c;
            }
        }

        cout << c << endl;

        --t;
    }
}

int binarySearchForPizzamania(int listNum[], int l, int n, int num) {
    int left, right, mid;
    left = l;
    right = n - 1;

    while(left <= right) {
        mid = (left + right) / 2;
        if(listNum[mid] == num)
            return true;
        else if(listNum[mid] > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

void Pizzamania2() {
    int t, n, m;
    int c;
    int l, r;
    int listNum[100010];

    cin >> t;
    while(t > 0) {
        cin >> n >> m;
        c = 0;

        for(int i = 0; i < n; ++i) {
            cin >> listNum[i];
        }
        sort(listNum, listNum + n);
        l = 0;
        r = n - 1;
        while (l < r) {
            if(listNum[l] + listNum[r] == m) {
                ++c;
                --r;
                ++l;
            } else if(listNum[l] + listNum[r] > m)
                --r;
            else
                ++l;
        }

        cout << c << endl;

        --t;
    }
}

// EKO: http://www.spoj.com/problems/EKO/
unsigned long long int milestone[MAX];
void EKO() {
    int n, m;
    unsigned long long int heights[MAX];
    unsigned long long int sumOfHeight = 0;
    unsigned long long int increase = 0;
    int index;
    unsigned long long int jump;
    unsigned long long int res;

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> heights[i];
        sumOfHeight += heights[i];
    }

    sort(heights, heights + n);

    for(int i = 0; i < n; ++i) {
        if(i > 0) {
            increase += heights[i - 1];
        }
        milestone[i] = sumOfHeight - (heights[i] * (n - i) + increase);
    }

    if(milestone[0] < m)
        res = 0;
    else {
        index = binarySearchForEKO(n, m);

        if(milestone[index] == m)
            res = heights[index] * 1ULL;
        else {
            jump = (milestone[index] - milestone[index + 1]) / (heights[index + 1] - heights[index]);
            res = ((milestone[index] - m) / jump) + heights[index];
        }
    }

    cout << res << endl;
}

int binarySearchForEKO(int n, int num) {
    int left, right, mid;
    bool find = false;
    left = 0;
    right = n - 1;

    while(left <= right) {
        mid = (left + right) / 2;
        if (milestone[mid] == num) {
            find = true;
            break;
        } else if(milestone[mid] < num)
            right = mid - 1;
        else
            left = mid + 1;
    }

    if(find)
        return (left + right) / 2;

    return left > 0 ? left - 1 : left;
}

// Hack the random number generator: http://www.spoj.com/problems/HACKRNDM/
void HackTheRandomNumberGenerator() {
    int n, k;

    int c = 0;
    int listNum[100010];
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> listNum[i];
    }

    sort(listNum, listNum + n);

    for(int i = 0; i < n; ++i) {
        if(listNum[i] + k > listNum[n - 1])
            break;

        if(binarySearch(listNum, n, listNum[i] + k)) {
            ++c;
        }
    }
    cout << c;
}

bool binarySearch(int listNum[], int n, int num) {
    int left, right, mid;
    left = 0;
    right = n - 1;

    while(left <= right) {
        mid = (left + right) / 2;
        if(listNum[mid] == num)
            return true;
        else if(listNum[mid] > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

void HackTheRandomNumberGenerator2() {
    int n, k, temp;
    int l, r;
    int c = 0;
    vector<int> listNum;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        listNum.push_back(temp);
    }

    sort(listNum.begin(), listNum.end());
    l = 0;
    r = 0;
    while(l < n && r < n) {
        while(r < n) {
            if(listNum[r] - listNum[l] >= k) {
                if(listNum[r] - listNum[l] == k)
                    ++c;

                break;
            }
            ++r;
        }
        ++l;
    }
    cout << c << endl;
}

// Where is the marble: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1415
void Marble() {
    int iTC = 1;
    int n, q, temp;
    long index;
    vector<int> nNum, nQ;
    vector<int>::iterator low_value;

    while(true) {
        cin >> n >> q;

        if(n == 0 && q == 0)
            break;

        nNum.clear();
        nQ.clear();
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            nNum.push_back(temp);
        }

        for(int i = 0; i < q; ++i) {
            cin >> temp;
            nQ.push_back(temp);
        }

        sort(nNum.begin(), nNum.end());

        cout << "CASE# " << iTC << ":" << endl;
        for(int i = 0; i < q; ++i) {
            low_value = lower_bound(nNum.begin(), nNum.end(), nQ[i]);
            index = low_value - nNum.begin();
            if(index < nNum.size() && nNum[index] == nQ[i]) {
                    cout << nQ[i] << " found at " << index + 1 << endl;
            } else {
                cout << nQ[i] << " not found" << endl;
            }
        }

        ++iTC;
    }
}