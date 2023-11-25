#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n;
	bool ao[1005];
	bool *a = &ao[500];
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		a[i] = getchar() == '1';
	}
	getchar();
	if (n & 1) {
		printf("-1\n");
		return;
	}
	vector<int> ans;
	// l, r: 实际数组位置  pl, pr: 输出的位置
	int l = 1, r = n, pl = 1, pr = n;
	int cnt = 0;
	bool ok = true;
	while (l < r) {
		if (a[l] != a[r]) {
			++l;
			++pl;
			--r;
			--pr;
			continue;
		}
		if (l + 1 == r) {
			ok = false;
			break;
		}
		++cnt;
		if (cnt > 300) {
			ok = false;
			break;
		}
		if (a[l]) {
			ans.push_back(pl - 1);
			--r;
			++pr;
			--l;
			a[l] = 1;
			++pl;
		} else {
			ans.push_back(pr);
			++l;
			++pl;
			++r;
			a[r] = 0;
			++pr;
		}
	}
	if (!ok) {
		printf("-1\n");
	} else {
		printf("%d\n", ans.size());
		for (int &i : ans) printf("%d ", i);
		printf("\n");
	}
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		solve();
	}
	return 0;
}