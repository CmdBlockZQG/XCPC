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
		for (; x <= n; x += lb(x)) t[x] += k;
	}

	// 查询前缀和
	T prefix(int x) {
		T c = 0;
		for (; x; x -= lb(x)) c += t[x];
		return c;
	}

	// 查询区间和
	T sum(int x, int y) {
		return prefix(y) - prefix(x - 1);
	}
};

const int N = 1e5+5;
int a[N];

void solve() {
	int n, q;
	scanf("%d %d", &n, &q);
	set<int> one;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			one.insert(i);
		}
	}
	BIT<int> pre(n, a, false);
	int op, s, i, v;

	auto fnd = [&](int x) -> int {
		int l = 1, r = n;
		while (l < r - 3) {
			int m = (l + r) / 2;
			if (pre.prefix(m) >= x) r = m;
			else l = m + 1;
		}
		for (int i = l; i <= r; ++i) {
			if (pre.prefix(i) >= x) return i;
		}
		return -1;
	};

	while (q--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &s);
			i = fnd(s);
			if (i == -1) {
				printf("NO\n");
				continue;
			}
			if (pre.prefix(i) == s || one.upper_bound(i) != one.end()) {
				printf("YES\n");
				continue;
			}
			if (one.size() == 0) {
				printf("NO\n");
				continue;
			}
			int t = *one.begin();
			if (t + i - 1 <= n) {
				printf("YES\n");
				continue;
			}
			printf("NO\n");
		} else {
			scanf("%d %d", &i, &v);
			if (a[i] == v) continue;
			a[i] = v;
			if (v == 1) {
				one.insert(i);
				pre.add(i, -1);
			} else {
				one.erase(i);
				pre.add(i, 1);
			}
		}
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