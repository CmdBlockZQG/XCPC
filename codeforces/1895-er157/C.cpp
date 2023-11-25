#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<string> str[6];
int sum[6][50] = {0};

int f(string &s, int l = 0, int r = 0) {
	int res = 0;
	r = r ? r : s.length();
	for (int i = l; i < r; ++i) {
		res += s[i] - '0';
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		str[s.length()].push_back(s);
		++sum[s.length()][f(s)];
	}
	ll ans = 0;
	for (int l = 1; l <= 5; ++l) {
		for (string &s : str[l]) {
			for (int i = l & 1 ? 1 : 2; i <= l; i += 2) {
				int h = (l + i) / 2;

				int c = f(s, 0, h) - f(s, h, l);
				if (c >= 1) ans += sum[i][c];

				c = f(s, l - h, l) - f(s, 0, l - h);
				if (c >= 1) ans += sum[i][c];
			}
		}
	}
	printf("%lld", ans);
	return 0;
}