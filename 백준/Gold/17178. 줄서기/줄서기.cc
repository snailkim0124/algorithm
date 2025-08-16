#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<pair<string, int>> sorted;
stack<pair<string, int>> st;
queue<pair<string, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n * 5; i++) {
        string s;
        cin >> s;
        string c = s.substr(0, 1);
        int num = stoi(s.substr(2));
        q.push({ c, num });
        sorted.push_back({ c, num });
    }

    sort(sorted.begin(), sorted.end());
    int idx = 0;

    while (!q.empty()) {
        bool check = false;
        if (q.front() == sorted[idx]) {
            q.pop();
            idx++;
            check = true;
        }
        while (!st.empty()) {
            if (st.top() == sorted[idx]) {
                st.pop();
                idx++;
                check = true;
            }
            else break;
        }

        if (!check) {
            st.push(q.front());
            q.pop();
        }
    }

    cout << (st.empty() ? "GOOD" : "BAD");

    return 0;
}