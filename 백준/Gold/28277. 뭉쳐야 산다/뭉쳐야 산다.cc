#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, q;
set<int> st[500005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int sn;
        cin >> sn;
        while (sn--) {
            int num;
            cin >> num;
            st[i].insert(num);
        }
    }

    while (q--) {
        int cmd, a, b;
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> b;
            if (st[a].size() < st[b].size()) {
                swap(st[a], st[b]);
            }

            for (auto it : st[b]) {
                st[a].insert(it);
            }
            st[b].clear();
        }
        else if (cmd == 2) {
            cin >> a;
            //cout << "ans : " << st[a].size() << "\n";
            cout << st[a].size() << "\n";
        }
    }
    
    
    return 0;
}