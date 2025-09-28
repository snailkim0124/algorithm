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
int arr[55], isprime[2005];
int visited[55], matched[55];
vector<int> adj[55];
vector<int> even, odd;
vector<int> ans;

bool dfs(int now) {
    for (auto next : adj[now]) {
        if (visited[next]) continue;
        visited[next] = 1;

        if (matched[next] == -1 || dfs(matched[next])) {
            matched[next] = now;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= 2005; i++) {
        if (isprime[i]) {
            for (int j = i + i; j <= 2005; j += i) {
                isprime[j] = 0;
            }
        }
    }

    // 홀짝 나누기
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }

    // 홀짝 개수 다르면 안됨
    if (odd.size() != even.size()) {
        cout << -1 << "\n";
        exit(0);
    }

    // 홀-홀, 짝-짝 불가능
    // 홀-짝만 가능
    vector<int> v1 = odd;
    vector<int> v2 = even;

    if (arr[0] % 2 == 0) swap(v1, v2);

    for (auto it : v2) {

        if (!isprime[arr[0] + arr[it]]) continue;

        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }

        for (auto x : v1) {
            for (auto y : v2) {
                if (isprime[arr[x] + arr[y]]) adj[x].push_back(y);
            }
        }

        memset(matched, -1, sizeof(matched));
        // 1번과 강제 매칭
        matched[it] = 0;

        int cnt = 1;
        for (int i = 1; i < v1.size(); i++) {
            memset(visited, 0, sizeof(visited));
            visited[0] = 1;
            visited[it] = 1;

            if (dfs(v1[i])) cnt++;
        }

        // 전부 매칭된 경우
        if (cnt == v1.size()) ans.push_back(arr[it]);

    }

    if (ans.empty()) cout << -1 << "\n";
    else {
        sort(all(ans));
        for (auto it : ans) {
            cout << it << " ";
        }
    }

    return 0;
}