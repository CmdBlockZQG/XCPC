#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve() {
	int n, m;
	string s, t;
	cin >> n >> m;
	cin >> s >> t;
	vector<int> q[26];
	int p[26] = {0};
	for (int i = 0; i < n; ++i) {
		int x = s[i] - 'a';
		q[x].push_back(i);
	}
	auto fnd = [&](vector<int> &a, int l, int x) -> int {
		int r = a.size() - 1;
		while (l < r - 3) {
			int m = (l + r) / 2;
			if (a[m] > x) r = m;
			else l = m + 1;
		}
		for (int i = l; i <= r; ++i) {
			if (a[i] > x) return i;
		}
		return a.size();
	};
	for (char c : t) {
		int x = c - 'a';
		if (p[x] == q[x].size()) return false;
		int y = q[x][p[x]];
		++p[x];
		for (int i = 0; i < x; ++i) p[i] = fnd(q[i], p[i], y);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	// scanf("%d", &t);
	while (t--) {
		printf(solve() ? "YES\n" : "NO\n");
	}
	return 0;
}