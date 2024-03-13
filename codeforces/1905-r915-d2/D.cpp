#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+3;

template<class T> struct SegTree {
	int n;
	// 所有下标均从1开始
	T *a, tree_sum[N * 8], set_tag[N * 8];

	// n:数据数量 a:数据源(下标1开始)
	void init(int n, T *a) {
		this->a = a;
		this->n = n;
		build_tree();
	}

	// private
	void build_tree(int x = 1, int l = 1, int r = 0) {
		r = r ? r : n;
		set_tag[x] = -1;
		if (l == r) {
			tree_sum[x] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build_tree(x * 2, l, m);
		build_tree(x * 2 + 1, m + 1, r);
		tree_sum[x] = tree_sum[2 * x] + tree_sum[2 * x + 1];
	}

	// private
	void push_set_tag(int x, int l, int r, int m) {
		if (set_tag[x] == -1 || l >= r) return;

		T t = set_tag[x];
		set_tag[x] = -1;

		int ls = 2 * x, rs = 2 * x + 1;
		tree_sum[ls] = t * (m - l + 1);
		tree_sum[rs] = t * (r - m);
		set_tag[ls] = t;
		set_tag[rs] = t;
	}

	// seg_add(l, r, k) -> [l, r] = k
	void seg_set(int l, int r, T k, int x = 1, int cl = 1, int cr = 0) {
		cr = cr ? cr : n;
		int cm = (cl + cr) / 2;
		push_set_tag(x, cl, cr, cm);
		if (cl > r || cr < l) return;
		if (l <= cl && cr <= r) {
			tree_sum[x] = k * (cr - cl + 1);
			if (cl < cr) set_tag[x] = k;
			return;
		}
		if (l <= cm) seg_set(l, r, k, 2 * x, cl, cm);
		if (r > cm) seg_set(l, r, k, 2 * x + 1, cm + 1, cr);
		tree_sum[x] = tree_sum[2 * x] + tree_sum[2 * x + 1];
	}

	// seg_sum(l, r) -> sum[l, r]
	T seg_sum(int l, int r, int x = 1, int cl = 1, int cr = 0) {
		cr = cr ? cr : n;
		int cm = (cl + cr) / 2;
		push_set_tag(x, cl, cr, cm);
		if (cl > r || cr < l) return 0;
		if (l <= cl && cr <= r) return tree_sum[x];
		T res = 0;
		if (l <= cm) res += seg_sum(l, r, 2 * x, cl, cm);
		if (r > cm) res += seg_sum(l, r, 2 * x + 1, cm + 1, cr);
		return res;
	}

};

int a[N * 2];
ll b[N * 2];
SegTree<ll> st;


void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
		b[i] = b[i + n] = 0;
	}
	b[n] = a[n];
	for (int i = n - 1; i >= 1; --i) {
		b[i] = a[i] < b[i + 1] ? a[i] : b[i + 1];
	}
	st.init(2 * n - 1, b);
	st.build_tree();
	
	ll ans = st.seg_sum(1, n);
	for (int i = 1; i < n; ++i) {
		int l = i, r = i + n - 1;
		while (l < r - 3) {
			int m = (l + r) / 2;
			if (st.seg_sum(m, m) > a[i]) r = m;
			else l = m + 1;
		}
		bool ok = false;
		for (int m = l; m <= r; ++m) {
			if (st.seg_sum(m, m) > a[i]) {
				st.seg_set(m, i + n, a[i]);
				ok = true;
				break;
			}
		}
		if (!ok) {
			st.seg_set(i + n, i + n, a[i]);
		}
		ans = max(ans, st.seg_sum(i + 1, i + n));
	}
	printf("%lld\n", ans + n);
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