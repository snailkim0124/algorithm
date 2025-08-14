#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct QUERY {
    int x, c, d;
};

int n, q;
int parent[200005], dsuparent[200005];
int sz[200005];
stack<QUERY> st;
vector<string> ans;

int findParent(int a) {
    if (a == dsuparent[a]) return a;
    else return dsuparent[a] = findParent(dsuparent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    dsuparent[b] = a;
    sz[a] += sz[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    q += n - 1;

    for (int i = 1; i <= n; i++) {
        dsuparent[i] = i;
        sz[i] = 1;
    }

    parent[1] = 1;
    for (int i = 2; i <= n; i++) {
        int a; // 부모 정점
        cin >> a;
        parent[i] = a;
    }

    // 오프라인 쿼리(역순)
    while (q--) {
        int x, b, c, d;
        cin >> x;
        // 삭제
        if (x == 0) {
            cin >> b;
            st.push({ x, b, parent[b] });
        }
        // 쿼리
        else if (x == 1) {
            cin >> c >> d;
            st.push({ x, c, d });
        }
    }

    while (!st.empty()) {
        QUERY now = st.top();
        st.pop();

        if(now.x == 0) {
            unionParent(now.c, now.d);
        }
        else if (now.x == 1) {
            if (findParent(now.c) == findParent(now.d)) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }

    // 역순으로 했으니 답도 역순으로
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it << "\n";
    }

    
    return 0;
}