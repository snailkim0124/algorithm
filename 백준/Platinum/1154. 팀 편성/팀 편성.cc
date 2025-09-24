#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<int> adj[1005];
int parent[1005];
int team[1005];
int visited[1005][1005];
vector<int> team1, team2;

int findParent(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a == 1) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
        visited[a][b] = 1;
        visited[b][a] = 1;
    }

    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        tmp.clear();
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!visited[i][j]) tmp.push_back(j);
        }

        for (int j = 1; j < tmp.size(); j++) {
            unionParent(tmp[j - 1], tmp[j]);
        }
    }

    // 팀 개수 세기
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        team[findParent(i)]++;
    }

    vector<int> tmp2;
    for (int i = 1; i <= n; i++) {
        if (team[i] > 1) cnt++;
    }

    if (cnt > 2) {
        cout << -1 << "\n";
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (findParent(i) == 1) team1.push_back(i);
        else team2.push_back(i);
    }

    // 2차 검증
    for (int i = 0; i < team1.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (!visited[team1[i]][team1[j]]) {
                cout << -1 << "\n";
                exit(0);
            }
        }
    }

    for (int i = 0; i < team2.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (!visited[team2[i]][team2[j]]) {
                cout << -1 << "\n";
                exit(0);
            }
        }
    }

    cout << 1 << "\n";
    for (auto it : team1) {
        cout << it << " ";
    }
    cout << "-1\n";

    for (auto it : team2) {
        cout << it << " ";
    }
    cout << "-1\n";

    return 0;
}