#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve() {
	int n, m;
	bool s[55], t[55];
	bool sg = true, tg = true;
	int cnt[2] = {0};
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		s[i] = getchar() == '1';
		if (i && s[i] == s[i - 1]) {
			sg = false;
			++cnt[s[i]];
		}
	}
	getchar();
	for (int i = 0; i < m; ++i) {
		t[i] = getchar() == '1';
		if (i && t[i] == t[i - 1]) tg = false;
	}
	getchar();
	if (sg) return true;
	if (cnt[0] && cnt[1]) return false;
	if (!tg || t[0] != t[m - 1]) return false;
	return !cnt[t[0]];
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		printf(solve() ? "YES\n" : "NO\n");
	}
	return 0;
}