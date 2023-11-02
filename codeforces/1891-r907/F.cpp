#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5+5;

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

bool op[N]; // false:point; true:value;
pair<int, ll> vx[N];
vector<int> g[N];
int son[N] = {0}, dep[N], fa[N], head[N];
ll delta[N];
BIT<ll> *bit[N] = {0};
vector<int> heads;

int dfs1(int x, int d) {
	dep[x] = d;
	int res = 0, z = 0, maxw = 0, t;
	for (int &y : g[x]) {
		t = dfs1(y, d + 1);
		if (t > maxw) z = y;
		res += t;
	}
	son[x] = z;
	return res + 1;
}

void dfs2(int x, int h) {
	head[x] = h;
	int &z = son[x];
	if (!z) { // 叶子节点
		heads.push_back(h);
		bit[h] = new BIT<ll>(dep[x] - dep[h] + 1);
	} else {
		dfs2(z, h);
		for (int &y : g[x]) {
			if (y == z) continue;
			dfs2(y, y);
		}
	}
}

void solve() {
	int q, t, v;
	ll x;
	scanf("%d", &q);
	int p = 1;
	fa[1] = 0;
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &t, &v);
		if (t == 1) { // add vertex
			op[i] = false;
			g[v].push_back(++p);
			fa[p] = v;
			vx[i] = {p, 0};
		} else if (t == 2) { // add value
			op[i] = true;
			scanf("%lld", &x);
			vx[i] = {v, x};
		}
	}

	dfs1(1, 1);
	dfs2(1, 1);

	for (int i = 0; i < q; ++i) {
		auto &[v, x] = vx[i];
		if (op[i]) { // add value
			t = head[v];
			bit[t]->add(dep[v] - dep[t] + 1, x);
		} else { // add vertex
			ll res = 0;
			for (int u = v; u; u = fa[head[u]]) {
				t = head[u];
				res += bit[t]->prefix(dep[u] - dep[t] + 1);
			}
			delta[v] = res;
		}
	}
	
	for (int i = 1; i <= p; ++i) {
		ll res = -delta[i];
		for (int u = i; u; u = fa[head[u]]) {
			t = head[u];
			res += bit[t]->prefix(dep[u] - dep[t] + 1);
		}
		printf("%lld ", res);
		g[i].clear();
	}
	putchar('\n');
	for (int &i : heads) {
		delete bit[i];
	}
	heads.clear();
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}