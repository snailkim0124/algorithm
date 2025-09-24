#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

set<string> st;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

void bfs(string ss) {
    queue<pair<string, int>> q;
    st.insert(ss);
    q.push({ ss, 0 });

    while (!q.empty()) {
        auto [s, cnt] = q.front();
        q.pop();

        if (s == "123456780") {
            cout << cnt << "\n";
            return;
        }

        int zero = s.find('0');
        int y = zero / 3;
        int x = zero % 3;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
            int nzero = ny * 3 + nx;

            swap(s[zero], s[nzero]);

            if (!st.count(s)) {
                st.insert(s);
                q.push({ s, cnt + 1 });
            }

            swap(s[zero], s[nzero]);
        }
    }

    cout << -1 << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            s += c;
        }
    }

    bfs(s);

    return 0;
}