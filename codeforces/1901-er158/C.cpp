#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, r;
	scanf("%d", &n);
	int mx = -1, mn = 1e9+7;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &r);
		mx = max(mx, r);
		mn = min(mn, r);
	}
	if (mx == mn) {
		printf("0\n");
		return;
	}
	vector<int> res;
	while (mx != mn) {
		if (mn & 1) {
			res.push_back(1);
			mn = (mn + 1) / 2;
			mx = (mx + 1) / 2;
		} else {
			res.push_back(0);
			mn = mn / 2;
			mx = mx / 2;
		}
	}
	printf("%d\n", res.size());
	if (res.size() <= n) {
		for (int i = 0; i < res.size(); ++i) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}