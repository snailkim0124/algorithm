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
    return dist(c.center, p) <= c.r * c.r;
}

// 두 점을 이용한 원
Circle circle2_func(Point a, Point b) {
    Point center = { (a.x + b.x) / 2.0, (a.y + b.y) / 2.0 };
    return { center, sqrt(dist(a, b)) / 2.0 };
}

// 가우스 소거법
vector<double> gauss(vector<vector<double>> a) {
    int n = a.size();

    for (int i = 0; i < n; i++) {
        // pivot 찾기 (절댓값 중 가장 큰 것)
        int pivot = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[pivot][i])) {
                pivot = k;
            }
        }

        // pivot행 swap
        swap(a[i], a[pivot]);

        // pivot을 1로 만들기
        double div = a[i][i];
        for (int j = i; j <= n; j++) {
            a[i][j] /= div;
        }

        // pivot 아래 행을 0으로
        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i];
            for (int j = i; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // 역대입
    vector<double> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            ans[i] -= a[i][j] * ans[j];
        }
    }

    return ans;
}

// 세 점을 이용한 원
Circle circle3_func(Point a, Point b, Point c) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    auto [x3, y3] = c;

    // 가우스 소거법 이용
    vector<vector<double>> matrix(2, vector<double>(3));
    matrix[0][0] = 2 * (x2 - x1);
    matrix[0][1] = 2 * (y2 - y1);
    matrix[0][2] = (x2 * x2 + y2 * y2) - (x1 * x1 + y1 * y1);

    matrix[1][0] = 2 * (x3 - x1);
    matrix[1][1] = 2 * (y3 - y1);
    matrix[1][2] = (x3 * x3 + y3 * y3) - (x1 * x1 + y1 * y1);

    vector<double> ans = gauss(matrix);

    Point center = { ans[0], ans[1] };

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
    cout << ans.center.x << " " << ans.center.y << " " << ans.r << "\n";

    return 0;
}