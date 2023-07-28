#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int n, m, l, k;
vector<pair<int, int>> v(500004);
int res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> l >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = { x,y };
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int cnt = 0;
            for (int o = 0; o < k; o++) {
                if (v[i].first <= v[o].first && v[j].second <= v[o].second && v[i].first + l >= v[o].first && v[j].second + l >= v[o].second) cnt++;
            }
            res = max(res, cnt);
        }
    }

    cout << k - res;
    return 0;
}