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
int k;
int mx;
int visited[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >> k;
    // k번 연산을 못하는 경우
    if (stoi(s) <= 10 || (stoi(s) < 100 && stoi(s) % 10 == 0)) {
        cout << -1 << "\n";
        exit(0);
    }

    string sort_s = s;
    sort(all(sort_s), greater<>());

    queue<pair<string, int>> q;
    q.push({ s, k });

    while (!q.empty()) {
        auto [now, cnt] = q.front();
        q.pop();

        if (now == sort_s) {
            if (cnt % 2 == 0) {
                mx = stoi(now);
                break;
            }
            else {
                memset(visited, 0, sizeof(visited));
                bool check = false;

                // 같은 숫자 있는지 확인
                for (int i = 0; i < now.size(); i++) {
                    if (visited[now[i] - '0']) {
                        check = true;
                        break;
                    }
                    visited[now[i] - '0']++;
                }

                // 없으면 맨뒤 2개 교환
                if (!check) {
                    swap(now.back(), now[now.size() - 2]);
                }

                mx = stoi(now);
                break;
            }
        }

        if (cnt == 0) {
            mx = max(mx, stoi(now));
            continue;
        }

        // 전부 교환해보기
        for (int i = 0; i < now.size(); i++) {
            for (int j = i + 1; j < now.size(); j++) {
                string tmp = now;
                if (i == 0 && now[j] == '0') continue;

                swap(tmp[i], tmp[j]);
                q.push({ tmp, cnt - 1 });
            }
        }
    }

    cout << mx << "\n";

    return 0;
}