#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct QUERY {
    int x, a;
}QUERY;

int n, q;
int parent[100005], dsuparent[100005];
set<int> color[100005];
stack<QUERY> st;
vector<int> ans;

int findParent(int a) {
    if (a == dsuparent[a]) return a;
    else return dsuparent[a] = findParent(dsuparent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a == b) return;

    if (color[a].size() < color[b].size()) swap(a, b);
    dsuparent[b] = a;
    for (auto it : color[b]) {
        color[a].insert(it);
    }
    color[b].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    q += n - 1;

    parent[1] = 1;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        parent[i] = p;
    }

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        color[i].insert(c);
    }

    while (q--) {
        int x, a;
        cin >> x >> a;
        st.push({ x, a });
    }

    for (int i = 1; i <= n; i++) {
        dsuparent[i] = i;
    }

    while (!st.empty()) {
        QUERY now = st.top();
        st.pop();

        if (now.x == 1) {
            unionParent(now.a, parent[now.a]);
        }
        else if (now.x == 2) {
            ans.push_back(color[findParent(now.a)].size());
            // cout << color[findParent(now.a)].size() << "\n";
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it << "\n";
    }

    return 0;
}