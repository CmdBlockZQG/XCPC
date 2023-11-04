#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+5;

int a[N], rain[N][2];
int solve() {
	int n, m, k;
	vector<pair<int, pair<int, int>>> d;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= n; ++i) {
		a[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &rain[i][0], &rain[i][1]);
		++a[rain[i][0]];
		--a[rain[i][1] + 1];
	}
	int acc = 0, no_rain = 0;
	for (int i = 1; i <= n; ++i) {
		acc += a[i];
		if (acc == 0) ++no_rain;
		else if (acc <= 2) d.push_back({i, {0, 0}});
	}
	auto find_l = [&](int x) -> int {
		int l = 0, r = d.size() - 1;
		while (l < r - 3) {
			int m = (l + r) / 2;
			if (d[m].first >= x) r = m;
			else l = m + 1;
		}
		for (int i = l; i <= r; ++i) {
			if (d[i].first >= x) return i;
		}
		return -1;
	};
	auto find_r = [&](int x) -> int {
		int l = 0, r = d.size() - 1;
		while (l < r - 3) {
			int m = (l + r) / 2;
			if (d[m].first <= x) l = m;
			else r = m - 1;
		}
		for (int i = r; i >= l; --i) {
			if (d[i].first <= x) return i;
		}
		return -1;
	};
	for (int i = 1; i <= m; ++i) {
		int l = find_l(rain[i][0]),
			r = find_r(rain[i][1]);
		if (l == -1 || r == -1 || l > r) continue;
		for (int j = l; j <= r; ++j) {
			if (d[j].second.second) d[j].second.first = i;
			else d[j].second.second = i;
		}
	}
	// for (auto &[i, x] : d) {
	// 	printf("%d %d %d\n", i, x.first, x.second);
	// }
	vector<pair<int, int>> t;
	for (auto &[_, i] : d) t.push_back(i);
	sort(t.begin(), t.end());
	// for (auto &[x, y] : t) {
	// 	printf("%d %d\n", x, y);
	// }
	int i = 0, mx1 = 0, mx2 = 0;
	map<int, int> ma;
	for (; i < t.size() && !t[i].first; ++i) {
		++ma[t[i].second];
	}
	for (auto &[_, x] : ma) {
		if (x >= mx1) {
			mx2 = mx1;
			mx1 = x;
		} else if (x > mx2) {
			mx2 = x;
		}
	}
	int ans = mx1 + mx2;
	if (i == t.size()) return no_rain + ans;
	acc = 1;
	for (++i; i < t.size(); ++i) {
		if (t[i] != t[i - 1]) {
			ans = max(ans, acc + ma[t[i - 1].first] + ma[t[i - 1].second]);
			acc = 1;
		} else {
			++acc;
		}
	}
	return no_rain + max(ans, acc + ma[t[i - 1].first] + ma[t[i - 1].second]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", solve());
	}
	return 0;
}