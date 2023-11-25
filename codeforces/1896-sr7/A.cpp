#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve() {
	int n, a[15];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	while (true) {
		bool sorted = true;
		for (int i = 2; i <= n; ++i) {
			if (a[i - 1] > a[i]) {
				sorted = false;
				break;
			}
		}
		if (sorted) return true;
		bool canop = false;
		for (int i = 2; i <= n - 1; ++i) {
			if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
				canop = true;
				swap(a[i], a[i + 1]);
			}
		}
		if (!canop) return false;
	}
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		printf(solve() ? "YES\n" : "NO\n");
	}
	return 0;
}