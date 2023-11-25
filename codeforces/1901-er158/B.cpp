#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> struct STTable {
	int n;
	static const int P = 21; // 1e6 可改小
	T (*st)[P];

	inline int pow2(int x) {
		return 1 << x;
	}

	// n:数据数量 a:数据源(下标1开始)
	STTable(int n, T *a) {
		this->n = n;
		st = new T[n + 1][P];
		for (int i = 1; i <= n; ++i) {
			st[i][0] = a[i];
		}
		for (int j = 1; j <= __lg(n); ++j) {
			for (int i = 1; i <= n - pow2(j) + 1; ++i) {
				st[i][j] = min(st[i][j - 1], st[i + pow2(j - 1)][j - 1]);
			}
		}
	}

	~STTable() {
		delete[] st;
	}

	T ask(int x, int y) {
		int p = __lg(y - x + 1);
		return min(st[x][p], st[y - pow2(p) + 1][p]);
	}
};

const int N = 2e5+3;
int n, a[N];

ll ans;
STTable<int> *st;
map<int, vector<int>> pos;

void f(int l, int r, int bias) {
	if (l > r) return;
	if (l == r) {
		ans += a[l] - bias;
		return;
	}

	int mn = st->ask(l, r);
	ans += mn - bias;

	vector<int> &posa = pos[mn];

	int pl = lower_bound(posa.begin(), posa.end(), l) - posa.begin();
	int pr = upper_bound(posa.begin(), posa.end(), r) - posa.begin();

	int lst = l;
	for (int i = pl; i < pr; ++i) {
		f(lst, posa[i] - 1, mn);
		lst = posa[i] + 1;
	}
	f(lst, r, mn);
}

void solve() {
	pos.clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	st = new STTable<int>(n, a);
	ans = 0;
	f(1, n, 0);
	printf("%lld\n", ans - 1);

	delete st;
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