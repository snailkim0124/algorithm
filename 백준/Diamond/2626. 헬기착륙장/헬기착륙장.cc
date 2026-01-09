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
    double x, y;
    bool operator<(const Point& tmp) const {
        if (x != tmp.x) return x < tmp.x;
        return y < tmp.y;
    }

    Point operator-(const Point& tmp) const {
        return { x - tmp.x, y - tmp.y };
    }
};

struct Circle {
    Point center;
    double r;
};

double dist(Point& a, Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool isInside(Circle c, Point p) {
    return dist(c.center, p) <= c.r * c.r + 1e-9;
}

// 두 점을 이용한 원
Circle circle2_func(Point a, Point b) {
    Point center = { (a.x + b.x) / 2.0, (a.y + b.y) / 2.0 };
    return { center, sqrt(dist(a, b)) / 2.0 };
}

// 세 점을 이용한 원
Circle circle3_func(Point a, Point b, Point c) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    auto [x3, y3] = c;

    // 크래머 공식
    double a1 = 2 * (x2 - x1);
    double b1 = 2 * (y2 - y1);
    double c1 = (x2 * x2 + y2 * y2) - (x1 * x1 + y1 * y1);

    double a2 = 2 * (x3 - x1);
    double b2 = 2 * (y3 - y1);
    double c2 = (x3 * x3 + y3 * y3) - (x1 * x1 + y1 * y1);

    // 행렬식
    double det = a1 * b2 - a2 * b1;
    Point center = { (c1 * b2 - c2 * b1) / det, (a1 * c2 - a2 * c1) / det };

    return { center, sqrt(dist(center, a)) };
}

// 최소 외접원 찾기
Circle welzl(vector<Point> v, vector<Point> r, int idx) {
    if (idx == 0 || r.size() == 3) {
        if (r.empty()) return { { 0, 0 }, 0 }; // 없으면 원점
        if (r.size() == 1) return { r[0], 0 };
        if (r.size() == 2) return circle2_func(r[0], r[1]);
        return circle3_func(r[0], r[1], r[2]);
    }

    Point p = v[idx - 1];

    Circle d = welzl(v, r, idx - 1); // p점 빼고 최소 원

    // p가 d 원 안에 있으면 됨
    if (isInside(d, p)) {
        return d;
    }

    // 없으면 p는 경계쪽 (원이 더 커져야 됨)
    r.push_back(p);
    return welzl(v, r, idx - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    vector<Point> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    Circle ans = welzl(v, {}, n);

    cout << fixed;
    cout.precision(3);
    double x = round(ans.center.x * 1000) / 1000;
    if (x == 0) x = 0;
    double y = round(ans.center.y * 1000) / 1000;
    if (y == 0) y = 0;
    double r = round(ans.r * 1000) / 1000;
    if (r == 0) r = 0;


    cout << x << " " << y << "\n";
    cout << r << "\n";

    return 0;
}