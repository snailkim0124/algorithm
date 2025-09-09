#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int bit;
vector<pii> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    while (m--) {
        int i, j;
        cin >> i >> j;
        v.push_back({ i, j });
    }

    for (int i = 0; i < (1 << n); i++) {
        bool flag = true;

        for (auto [a, b] : v) {
            auto get_val = [&](int x) {
                if (x > 0) return (i >> (x - 1)) & 1;
                else return (int)!((i >> (-x - 1)) & 1);
            };

            int check1 = get_val(a);
            int check2 = get_val(b);

            if (!check1 && !check2) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << 1 << "\n";
            vector<int> ans;
            for (int j = 1; j <= n; j++) {
                if ((i >> (j - 1)) & 1) ans.push_back(1);
                else ans.push_back(0);
            }

            for (auto it : ans) {
                cout << it << " ";
            }

            exit(0);
        }
    }

    cout << 0 << "\n";

    return 0;
}