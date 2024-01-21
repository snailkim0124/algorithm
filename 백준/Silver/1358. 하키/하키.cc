#include <bits/stdc++.h>

using namespace std;

int dist(int x, int y, int a, int b) {
    return ((x - a) * (x - a)) + ((b - y) * (b - y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int W, H, X, Y, P, cnt = 0;
    cin >> W >> H >> X >> Y >> P;

    for (int t = 0; t < P; ++t) {
        int x, y, r = (H / 2) * (H / 2);
        cin >> x >> y;

        if (X <= x && x <= X + W && Y <= y && y <= Y + H)
            cnt++;
        // 왼쪽 반원에 있는지 판별
        else if (dist(X, Y + (H / 2), x, y) <= r)
            cnt++;
        // 오른쪽 반원에 있는지 판별
        else if (dist(X + W, Y + (H / 2), x, y) <= r)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}