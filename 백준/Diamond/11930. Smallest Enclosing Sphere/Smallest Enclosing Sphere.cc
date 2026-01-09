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
    double x, y, z;
    Point operator-(const Point& tmp) const {
        return { x - tmp.x, y - tmp.y, z - tmp.z };
    }

    // 외적(신발끈)
    Point cross(const Point& tmp) const {
        return {
            y * tmp.z - z * tmp.y,
            z * tmp.x - x * tmp.z,
            x * tmp.y - y * tmp.x,
        };
    }
};

struct Sphere {
    Point center;
    double r;
};

double dist(Point& a, Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

bool isInside(Sphere s, Point p) {
    return dist(s.center, p) <= s.r * s.r;
}

// 두 점을 이용한 구
Sphere sphere2_func(Point a, Point b) {
    Point center = { (a.x + b.x) / 2.0, (a.y + b.y) / 2.0, (a.z + b.z) / 2.0 };
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

// 세 점을 이용한 구
Sphere sphere3_func(Point a, Point b, Point c) {
    auto [x1, y1, z1] = a;
    auto [x2, y2, z2] = b;
    auto [x3, y3, z3] = c;

    // 가우스 소거법 이용
    vector<vector<double>> matrix(3, vector<double>(4));

    // ab 수직이등분면
    matrix[0][0] = 2 * (x2 - x1);
    matrix[0][1] = 2 * (y2 - y1);
    matrix[0][2] = 2 * (z2 - z1);
    matrix[0][3] = (x2 * x2 + y2 * y2 + z2 * z2) - (x1 * x1 + y1 * y1 + z1 * z1);

    // ac 수직이등분면
    matrix[1][0] = 2 * (x3 - x1);
    matrix[1][1] = 2 * (y3 - y1);
    matrix[1][2] = 2 * (z3 - z1);
    matrix[1][3] = (x3 * x3 + y3 * y3 + z3 * z3) - (x1 * x1 + y1 * y1 + z1 * z1);

    // 법선 벡터
    Point ab = b - a;
    Point ac = c - a;
    Point n = ab.cross(ac);
    matrix[2][0] = n.x;
    matrix[2][1] = n.y;
    matrix[2][2] = n.z;
    matrix[2][3] = n.x * x1 + n.y * y1 + n.z * z1;

    vector<double> ans = gauss(matrix);

    Point center = { ans[0], ans[1], ans[2]};

    return { center, sqrt(dist(center, a)) };
}

// 네 점을 이용한 구
Sphere sphere4_func(Point a, Point b, Point c, Point d) {
    auto [x1, y1, z1] = a;
    auto [x2, y2, z2] = b;
    auto [x3, y3, z3] = c;
    auto [x4, y4, z4] = d;

    // 가우스 소거법 이용
    vector<vector<double>> matrix(3, vector<double>(4));
    matrix[0][0] = 2 * (x2 - x1);
    matrix[0][1] = 2 * (y2 - y1);
    matrix[0][2] = 2 * (z2 - z1);
    matrix[0][3] = (x2 * x2 + y2 * y2 + z2 * z2) - (x1 * x1 + y1 * y1 + z1 * z1);

    matrix[1][0] = 2 * (x3 - x1);
    matrix[1][1] = 2 * (y3 - y1);
    matrix[1][2] = 2 * (z3 - z1);
    matrix[1][3] = (x3 * x3 + y3 * y3 + z3 * z3) - (x1 * x1 + y1 * y1 + z1 * z1);

    matrix[2][0] = 2 * (x4 - x1);
    matrix[2][1] = 2 * (y4 - y1);
    matrix[2][2] = 2 * (z4 - z1);
    matrix[2][3] = (x4 * x4 + y4 * y4 + z4 * z4) - (x1 * x1 + y1 * y1 + z1 * z1);

    vector<double> ans = gauss(matrix);

    Point center = { ans[0], ans[1], ans[2] };

    return { center, sqrt(dist(center, a)) };
}

// 최소 외접구 찾기
Sphere welzl(vector<Point> v, vector<Point> r, int idx) {
    if (idx == 0 || r.size() == 4) {
        if (r.empty()) return { { 0, 0 }, 0 }; // 없으면 원점
        if (r.size() == 1) return { r[0], 0 };
        if (r.size() == 2) return sphere2_func(r[0], r[1]);
        if (r.size() == 3) return sphere3_func(r[0], r[1], r[2]);
        return sphere4_func(r[0], r[1], r[2], r[3]);
    }

    Point p = v[idx - 1];

    Sphere d = welzl(v, r, idx - 1); // p점 빼고 최소 원

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
        cin >> v[i].x >> v[i].y >> v[i].z;
    }

    Sphere ans = welzl(v, {}, n);

    cout << fixed;
    cout.precision(2);
    double r = round(ans.r * 100) / 100;
    if (r == 0) r = 0;

    cout << r << "\n";

    return 0;
}