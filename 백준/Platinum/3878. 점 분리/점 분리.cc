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

    Point operator-(const Point& tmp) const {
        return { x - tmp.x, y - tmp.y };
    }
};

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool iscross(Point a, Point b, Point c, Point d) {
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        return max(min(a.x, b.x), min(c.x, d.x)) <= min(max(a.x, b.x), max(c.x, d.x)) &&
            max(min(a.y, b.y), min(c.y, d.y)) <= min(max(a.y, b.y), max(c.y, d.y));
    }

    return ab <= 0 && cd <= 0;
}

bool isinline(Point a, Point b, Point p) {
    return((ccw(a, b, p) == 0) && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y));
}

bool isinside(vector<Point>& v, Point p) {
    int sz = v.size();
    ll cnt = 0;

    for (int i = 0, j = sz - 1; i < sz; j = i++) {
        Point a = v[i], b = v[j];

        if (isinline(a, b, p)) return true;

        if ((a.y > p.y) != (b.y > p.y)) {
            // 교차점 x 찾기
            double x = a.x + (b.x - a.x) * (p.y - a.y) / (double)(b.y - a.y);
            if (x > p.x) cnt++;
        }
    }

    return (cnt % 2);
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

bool check(vector<Point>& hull1, vector<Point>& hull2) {
    // 흰색 컨벡스에서 검은점 체크
    for (auto p : hull1) {
        if (isinside(hull2, p)) return false;
    }

    // 검은색 컨벡스에서 흰점 체크
    for (auto p : hull2) {
        if (isinside(hull1, p)) return false;
    }

    // hull 변이 교차?
    for (int i = 0; i < hull1.size(); i++) {
        Point a = hull1[i], b = hull1[(i + 1) % hull1.size()];
        for (int j = 0; j < hull2.size(); j++) {
            Point c = hull2[j], d = hull2[(j + 1) % hull2.size()];

            if (iscross(a, b, c, d)) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<Point> vb(n), vw(m);

        for (int i = 0; i < n; i++) {
            cin >> vb[i].x >> vb[i].y;
        }

        for (int i = 0; i < m; i++) {
            cin >> vw[i].x >> vw[i].y;
        }

        vector<Point> hullb = convexHull(vb);
        vector<Point> hullw = convexHull(vw);

        cout << (check(hullb, hullw) ? "YES\n" : "NO\n");
    }

    return 0;
}