#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<vector<int>> arr;

int go(int x, int y, int num) {
    vector<int> v;
    if (num <= 2) {
        v.push_back(arr[x][y]);
        v.push_back(arr[x][y + 1]);
        v.push_back(arr[x + 1][y]);
        v.push_back(arr[x + 1][y + 1]);
        sort(v.begin(), v.end());

        return v[2];
    }

    v.push_back(go(x, y, num / 2));
    v.push_back(go(x, y + num / 2, num / 2));
    v.push_back(go(x + num / 2, y, num / 2));
    v.push_back(go(x + num / 2, y + num / 2, num / 2));
    sort(v.begin(), v.end());

    return v[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << go(0, 0, n);

    return 0;
}