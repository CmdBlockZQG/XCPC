#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve() {
	int n, a[25];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int t = log2((double)n);
	for (int i = (1 << t) + 2; i <= n; ++i) {
		if (a[i - 1] > a[i]) return false;
	}
	for (int i = 2; i <= t; ++i) {
		// printf("%d %d\n", (1 << (i - 1)) + 2, (1 << i));
		for (int j = (1 << (i - 1)) + 2; j <= (1 << i); ++j) {
			if (a[j - 1] > a[j]) return false;
		}
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf(solve() ? "YES\n" : "NO\n");
	}
	return 0;
}