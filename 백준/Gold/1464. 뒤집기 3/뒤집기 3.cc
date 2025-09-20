#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
deque<char> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    
    for (auto c : s) {
        if (dq.empty() || dq.front() < c) {
            dq.push_back(c);
        }
        else if (dq.front() >= c) {
            dq.push_front(c);
        }
    }
    
    while (!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }

    return 0;
}