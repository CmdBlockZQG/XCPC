#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;
int n, a[105], cnt[N];

bool solve() {
	int sum = 0;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	auto init = [&]() -> void {
		for (int i = 0; i < n; ++i) {
			cnt[a[i]] = 0;
		}
		for (int i = 0; i < n; ++i) {
			++cnt[a[i]];
		}
	};

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int k = sum * 2 - a[i] - a[j];
			if (k % (n - 1) != 0) continue;
			k /= n - 1;
			init();
			--cnt[a[i]];
			int lst = a[i];
			for (int p = 1; p <= n - 1; ++p) {
				int x = k - lst;
				if (x <= 0 || x > 1e5 || !cnt[x]) goto haha;
				--cnt[x];
				lst = x;
			}
			if (lst == a[j]) return true;
			haha:;
		}
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf(solve() ? "Yes\n" : "No\n");
	}
	return 0;
}