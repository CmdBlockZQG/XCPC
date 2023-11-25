#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5+3;

int n, a[N];
int p[N], q[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		p[i] = a[i] + i - 1;
		q[i] = max(q[i - 1], a[i] + n - i);
	}
	for (int i = n; i >= 1; --i) {
		p[i] = max(p[i], p[i + 1]);
	}
	int ans = 2e9;
	for (int i = 1; i <= n; ++i) {
		ans = min(ans, max({ a[i], q[i - 1], p[i + 1] }));
	}
	printf("%d", ans);
	return 0;
}