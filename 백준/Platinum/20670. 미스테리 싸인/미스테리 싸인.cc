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

bool isinline(Point a, Point b, Point p) {
    return((ccw(a, b, p) == 0) && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y));
}

bool isinside(vector<Point>& v, Point p) {
    // 이분 탐색
    Point tmp = v[0];

    if (ccw(tmp, v[1], p) < 0) return false;
    if (ccw(tmp, v[v.size() - 1], p) > 0) return false;

    ll left = 0;
    ll right = v.size() - 1;
    while (left + 1 < right) {
        ll mid = (left + right) / 2;
        if (ccw(tmp, v[mid], p) > 0) left = mid;
        else right = mid;
    }

    return ccw(v[left], v[left + 1], p) > 0;
}

vector<Point> convexHull(vector<Point>& v) {
    if (v.size() <= 1) return v;

    sort(all(v));

    vector<Point> hull;

    // 하단
    for (auto p : v) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // 상단
    int sz = hull.size();
    for (int i = v.size() - 2; i >= 0; i--) {
        Point p = v[i];
        while (hull.size() > sz && ccw(hull[hull.size() - 2], hull.back(), p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    hull.pop_back(); // 마지막 중복 제거

    return hull;
}

bool check(vector<Point>& hulla, vector<Point>& hullb, Point p) {
    // 싸인 점이 A에 내부?
    if (!isinside(hulla, p)) return false;
    // 싸인 점이 B에 외부?
    if (isinside(hullb, p)) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<Point> va(n), vb(m), vk(k);

    for (int i = 0; i < n; i++) {
        cin >> va[i].x >> va[i].y;
    }

    for (int i = 0; i < m; i++) {
        cin >> vb[i].x >> vb[i].y;
    }

    for (int i = 0; i < k; i++) {
        cin >> vk[i].x >> vk[i].y;
    }

    vector<Point> hulla = va;
    vector<Point> hullb = vb;

    ll cnt = 0;
    for (auto p : vk) {
        if (!check(hulla, hullb, p)) cnt++;
    }

    if (!cnt) cout << "YES\n";
    else cout << cnt << "\n";

    return 0;
}