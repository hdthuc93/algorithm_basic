#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include "MishaAndChangingHandles.h"

using namespace std;
void MonkAndMultiplication();
void ApproximatingAConstantRange();

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    MishaAndChangingHandles();
    return 0;
}

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int len = (int)A.size();
    int a, b, c;
    bool flag = false;
    int sumV = 0;
    int sum = 0;

    vector<int> res;

    for(int i = 0; i < len; ++i) {
        sumV += A[i];
        sum += i + 1;
    }

    if(sum - sumV > 0) {
        a = 1;
        c = sum - sumV;
        b = a + c;
    } else {
        b = 1;
        c = sumV - sum;
        a = b + c;
    }

    while (true) {
        if(flag) {
            break;
        } else
            ++b;

        for(int i = 0; i < len; ++i) {
            if(b == A[i]) {
                flag = false;
                break;
            }
            flag = true;
        }
    }

    if(sum - sumV > 0) {
        a = b - c;
    } else {
        a = b + c;
    }

    res.push_back(a);
    res.push_back(b);
    return res;
}



// Approximating a Constant Range
void ApproximatingAConstantRange() {
    int n, num;
    int l, r;
    int minIndex, maxIndex;
    int maxLen;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        v.push_back(num);
    }

    l = 0;
    r = 0;
    minIndex = 0;
    maxIndex = 0;
    maxLen = 0;
    while(l < n) {
        while(r < n) {
            if(v[maxIndex] <= v[r])
                maxIndex = r;

            if(v[minIndex] >= v[r])
                minIndex = r;

            if(v[maxIndex] - v[minIndex] > 1)
                break;
            ++r;
        }

        maxLen = max(maxLen, r - l);
        ++l;
        while(abs(v[r] - v[l]) > 1)
            ++l;

        if(l > minIndex) {
            for(int i = l; i <= r; ++i) {
                if(v[i] == v[minIndex] + 1) {
                    minIndex = i;
                    break;
                }
            }
            minIndex = l > minIndex ? l : minIndex;
        } else if(l > maxIndex) {
            for(int i = l; i <= r; ++i) {
                if(v[i] == v[maxIndex] - 1) {
                    maxIndex = i;
                    break;
                }
            }
            maxIndex = l > maxIndex ? l : maxIndex;
        }
    }

    cout << maxLen << endl;
}


// Monl and multiplication: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/
void MonkAndMultiplication() {
    unsigned long long int n, num;
    unsigned long long int prevNum1, prevNum2, prevNum3;
    unsigned long long int res;
    cin >> n;
    priority_queue<unsigned long long int> pq;

    for(unsigned long long int i = 0; i < n; ++i) {
        cin >> num;
        pq.push(num);

        if(pq.size() < 3) {
            cout << -1 << endl;
            continue;
        }

        prevNum1 = pq.top();
        pq.pop();
        prevNum2 = pq.top();
        pq.pop();
        prevNum3 = pq.top();
        pq.pop();

        res = prevNum1 * prevNum2 * prevNum3;

        pq.push(prevNum1);
        pq.push(prevNum2);
        pq.push(prevNum3);

        cout << res << endl;
    }
}