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

const int N = 5e5+3;
int a[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	BIT<int> b(n, a, true);
	int o, x, y;
	while (m--) {
		scanf("%d %d %d", &o, &x, &y);
		if (o == 1) {
			b.add(x, y);
		} else if (o == 2) {
			printf("%d\n", b.sum(x, y));
		}
	}
	return 0;
}