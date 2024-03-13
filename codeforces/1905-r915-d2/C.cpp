#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+4;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int p[N];
	p[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		if (s[i] >= s[p[i + 1]]) p[i] = i;
		else p[i] = p[i + 1];
	}
	vector<int> pos;
	for (int i = 0; i < n; i = p[i] + 1) {
		pos.push_back(p[i]);
	}

	int t = pos.size();

	int h = 0;
	for (int i = 0; i < t; ++i) {
		if (s[pos[i]] == s[pos[0]]) ++h;
		else break;
	}

	for (int i = 0; i < t / 2; ++i) {
		swap(s[pos[i]], s[pos[t - i - 1]]);
	}
	bool ok = true;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] > s[i + 1]) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("%d\n", t - h);
	} else {
		printf("-1\n");
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	//scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
} 