#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Point {
    ll x, y;
    bool operator<(const Point& tmp) const {
        if (x != tmp.x) return x < tmp.x;
        return y < tmp.y;
    }
};

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convexHull(vector<Point>& v) {
    if (v.size() <= 1) return v;

    sort(all(v));

    //cout << "sort-1 : \n";
    //for (auto it : v) {
    //    cout << it.x << " : " << it.y << "\n";
    //}
    //cout << "\n";

    Point tmp = v[0]; // 기준점

    // 기준점 기준으로 반시계 정렬
    sort(v.begin() + 1, v.end(), [&](Point& a, Point& b) {
        ll cc = ccw(tmp, a, b);
        if (cc != 0) return cc > 0;
        ll da = (a.x - tmp.x) * (a.x - tmp.x) + (a.y - tmp.y) * (a.y - tmp.y);
        ll db = (b.x - tmp.x) * (b.x - tmp.x) + (b.y - tmp.y) * (b.y - tmp.y);
        return da < db;
        });

    //cout << "sort : \n";
    //for (auto it : v) {
    //    cout << it.x << " : " << it.y << "\n";
    //}
    //cout << "\n";

    // 마지막 일직선 처리
    int idx = v.size() - 1;
    while (!ccw(tmp, v[idx - 1], v[idx])) idx--;
    reverse(v.begin() + idx, v.end());

   /* cout << "reverse : \n";
    for (auto it : v) {
        cout << it.x << " : " << it.y << "\n";
    }
    cout << "\n";*/

    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    vector<Point> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'Y') v.push_back({ x, y });
    }

    vector<Point> hull = convexHull(v);

    cout << hull.size() << "\n";
    for (auto it : hull) {
        cout << it.x << " " << it.y << "\n";
    }

    return 0;
}