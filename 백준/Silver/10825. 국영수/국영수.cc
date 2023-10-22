#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct student {
	string name;
	int korean;
	int english;
	int math;
}student;

int n;
student STUDENT[100005];

bool cmp(student a, student b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				return (a.name < b.name);
			}
			else return (a.math > b.math);
		}
		else return (a.english < b.english);
	}
	else return (a.korean > b.korean);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> STUDENT[i].name >> STUDENT[i].korean >> STUDENT[i].english >> STUDENT[i].math;
	}

	sort(STUDENT, STUDENT + n, cmp);
	
	for (int i = 0; i < n; i++) {
		cout << STUDENT[i].name << "\n";
	}

	return 0;
}