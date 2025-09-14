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

ll ccw(Point& a, Point& b, Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

ll dist(Point& a, Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

pair<Point, Point> rotate_cali(vector<Point>& hull) {
    ll sz = hull.size();
    if (sz == 1) return { hull[0], hull[0] };

    Point origin = { 0,0 };
    Point a = hull[0], b = hull[1];
    ll mxdist = dist(a, b);

    int j = 1;
    for (int i = 0; i < sz; i++) {
        Point pi, pj;
        pi.x = hull[(i + 1) % sz].x - hull[i].x;
        pi.y = hull[(i + 1) % sz].y - hull[i].y;

        pj.x = hull[(j + 1) % sz].x - hull[j].x;
        pj.y = hull[(j + 1) % sz].y - hull[j].y;

        while (ccw(origin, pi, pj) > 0) {
            j = (j + 1) % sz;
            pj.x = hull[(j + 1) % sz].x - hull[j].x;
            pj.y = hull[(j + 1) % sz].y - hull[j].y;
        }

        if (mxdist < dist(hull[i], hull[j])) {
            mxdist = dist(hull[i], hull[j]);
            a = hull[i];
            b = hull[j];
        }
    }

    return { a,b };
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<Point> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y;
        }

        vector<Point> hull = convexHull(v);

        auto res = rotate_cali(hull);

        cout << res.first.x << " " << res.first.y << " " << res.second.x << " " << res.second.y << "\n";
    }

    return 0;
}