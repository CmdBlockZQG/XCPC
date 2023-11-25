#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> struct BIT {
	int n;
	T *t;
	bool need_free = true;

	inline int lb(int x) {
		return x & (-x);
	}

	// 构造空树状数组
	BIT(int n) {
		this->n = n;
		t = new T[n + 1]();
	}

	// n:数据数量 a:数据源(下标1开始) inplace:利用传入的数组
	BIT(int n, T *a, bool inplace = false) {
		this->n = n;
		need_free = !inplace;
		t = inplace ? a : new T[n + 1]();
		for (int i = 1; i <= n; ++i) {
			if (!inplace) t[i] = a[i];
			for (int x = lb(i) >> 1; x; x >>= 1) {
				t[i] += t[i - x];
			}
		}
	}

	~BIT() {
		if (need_free) delete[] t;
	}

	// 单点修改 a[x] += k
	void add(int x, T k) {
		for (; x <= n; x += lb(x)) t[x] = max(t[x], k);
	}

	// 查询前缀和
	T prefix(int x) {
		T c = 0;
		for (; x; x -= lb(x)) c = max(c, t[x]);
		return c;
	}

};

const int N = 2e5+5;
int b[N], dp[N];
struct Node {
	int i, a, t;
} a[N];

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		a[i].i = i;
		scanf("%d", &a[i].a);
	}
	sort(a, a + n, [](Node a, Node b) -> bool {
		return a.a < b.a;
	});
	int p = 1;
	a[0].t = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i].a != a[i - 1].a) a[i].t = ++p;
		else a[i].t = p;
	}
	sort(a, a + n, [](Node a, Node b) -> bool {
		return a.i < b.i;
	});
	BIT<int> bit(p + 3);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int x = bit.prefix(a[i].t - 1) + 1;
		dp[i] = x;
		mx = max(x, mx);
		bit.add(a[i].t, x);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	sort(b, b + m, greater<int>());

	vector<int> poses;
	for (int i = 0; i < n; ++i) {
		if (dp[i] == mx) poses.push_back(i);
	}
	int i = 0, j = 0;
	for (int &pos : poses) {
		for (; i < pos; ++i) {
			printf("%d ", a[i].a);
		}
		for (; j < m && b[j] >= a[pos].a; ++j) {
			printf("%d ", b[j]);
		}
		printf("%d ", a[pos].a);
		++i;
	}
	for (; i < n; ++i) {
		printf("%d ", a[i].a);
	}
	for (; j < m; ++j) {
		printf("%d ", b[j]);
	}
	printf("\n");
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}