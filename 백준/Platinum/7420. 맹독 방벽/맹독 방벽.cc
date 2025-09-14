#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const double PI = 3.141592;

struct Point {
    ll x, y;
    bool operator<(const Point& tmp) const {
        if (x != tmp.x) return x < tmp.x;
        return y < tmp.y;
    }
};

ll ccw(Point& a, Point& b, Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dist(Point& a, Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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

    int n, l;
    cin >> n >> l;
    vector<Point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    vector<Point> hull = convexHull(v);

    double ans = 0;

    for (int i = 0; i < hull.size(); i++) {
        Point a = hull[i];
        Point b = hull[(i + 1) % hull.size()];

        ans += dist(a, b);
    }

    ans += 2 * PI * l;

    cout << round(ans) << "\n";

    return 0;
}