#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+5;

ll a[N], s[N];
pair<ll, int> p[N];
bool solve() {
	int n;
	ll c;
	scanf("%d %lld", &n, &c);
	scanf("%lld", &a[1]);
	for (int i = 2; i <= n; ++i) {
		scanf("%lld", &a[i]);
		p[i - 1] = {i * c - a[i], i};
	}
	sort(p + 1, p + n);
	if (p[1].first > a[1]) return false;
	s[0] = 0;
	for (int i = 1; i < n; ++i) {
		s[i] = s[i - 1] + a[p[i].second];
	}
	auto get_pos = [&](ll x) -> int {
		int l = 1, r = n - 1;
		while (l < r - 3) {
			int m = (l + r) / 2;
			if (x >= p[m].first) l = m;
			else r = m - 1;
		}
		for (int i = r; i >= l; --i) {
			if (x >= p[i].first) return i;
		}
		return -1;
	};
	ll ta = a[1];
	int pos = 0, npos;
	while (true) {
		pos = get_pos(ta);
		if (pos == -1) return false;
		if (pos == n - 1) return true;
		if (ta == a[1] + s[pos]) return false;
		ta = a[1] + s[pos];
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf(solve() ? "Yes\n" : "No\n");
	}
	return 0;
}