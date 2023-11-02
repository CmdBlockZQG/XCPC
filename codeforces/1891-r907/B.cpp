#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+5;

int a[N];
vector<int> x;

void solve() {
	int n, q, t;
	x.clear();
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	while (q--) {
		scanf("%d", &t);
		if (!x.size() || t < x.back()) x.push_back(t);
	}
	// for (int &i : x) printf(">>%d ", i);
	// printf("\n");
	x.back() = 1 << (x.back() - 1);
	for (int i = x.size() - 2; i >= 0; --i) {
		x[i] = (1 << (x[i] - 1)) | x[i + 1];
	}
	// for (int &i : x) printf(">>%d ", i);
	// printf("\n");
	for (int i = 0; i < n; ++i) {
		t = a[i] & (-a[i]);
		int l = 0, r = x.size() - 1;
		while (l < r - 3) {
			int m = (l + r) / 2;
			if (x[m] < t) r = m;
			else l = m + 1;
		}
		for (int j = l; j <= r; ++j) {
			if (x[j] < t) {
				a[i] |= x[j];
				break;
			}
		}
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}