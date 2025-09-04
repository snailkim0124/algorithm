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
int tarr[55];
int parent[55];
vector<int> party[55];
int t;
int cnt;


int findParent(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) swap(a, b);
    parent[a] = b;
    if (tarr[a]) tarr[b] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        tarr[num] = 1;
    }

    for (int i = 0; i < m; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int a;
            cin >> a;
            party[i].push_back(a);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < party[i].size(); j++) {
            for (int k = j + 1; k < party[i].size(); k++) {
                unionParent(party[i][j], party[i][k]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (auto it : party[i]) {
            if (tarr[findParent(it)]) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }

    //cout << "parent : \n";
    //for (int i = 1; i <= n; i++) {
    //    cout << i << " : " << findParent(i) << "\n";
    //}
    //

    cout << cnt << "\n";
    
    return 0;
}