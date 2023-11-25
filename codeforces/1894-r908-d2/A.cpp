#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	if (n == 1) {
		cout << s[0] << '\n';
		return;
	}
	int a = 0, b = 0;
	for (char &c : s) {
		a += c == 'A';
		b += c == 'B';
	}

	cout << s << ' ' << a << ' ' << b << '\n';

	auto f = [&](int x, int y) -> char {
		int pa = 0, pb = 0, sa = 0, sb = 0;
		for (int i = 0; i < n; ++i) {
			char c = s[i];
			pa += c == 'A';
			pb += c == 'B';
			if (pa == x) {
				++sa;
				pa = pb = 0;
			} else if (pb == x) {
				++sb;
				pa = pb = 0;
			}
			if ((sa == y || sb == y) && i != n - 1) return 'X';
		}
		if (sa == y) return 'A';
		else if (sb == y) return 'B';
		else return 'X';
	};

	int ca = 0, cb = 0;
	for (int x = 1; x <= a; ++x) {
		if (a % x) continue;
		char r = f(x, a / x);
		cout << ">> " << x << ' ' << a / x << ' ' << r << '\n';
		ca += r == 'A';
		cb += r == 'B';
	}
	for (int x = 1; x <= b; ++x) {
		if (b % x) continue;
		char r = f(x, b / x);
		cout << ">> " << x << ' ' << b / x << ' ' << r << '\n';
		ca += r == 'A';
		cb += r == 'B';
	}
	if (ca && !cb) cout << "A\n";
	else if (cb && !ca) cout << "B\n";
	else cout << ca << cb << s << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}