#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int n, m, a[54][54], result = 123456789;
vector<vector<int>> chicken_list;
vector<pair<int, int>> home, chicken;

void combi(int start, vector<int> v) {
    if (v.size() == m) {
        chicken_list.push_back(v);
        return;
    }
    for (int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) home.push_back({ i,j });
            if (a[i][j] == 2) chicken.push_back({ i,j });
        }
    }
    vector<int> v;
    combi(-1, v);
    for (vector<int> clist : chicken_list) {
        int res = 0;
        for (pair<int, int> home2 : home) {
            int mn = 123456789;
            for (int c : clist) {
                int num = abs(home2.first - chicken[c].first) + abs(home2.second - chicken[c].second);
                mn = min(mn, num);
            }
            res += mn;
        }
        result = min(res, result);
    }

    cout << result;
    return 0;
}