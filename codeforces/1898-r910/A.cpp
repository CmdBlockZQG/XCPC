#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, k, cnt = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    for (char c : s) {
        cnt += c == 'B';
    }
    if (cnt == k) {
        cout << "0\n";
        return;
    }
    if (cnt > k) {
        for (int i = 0; ; ++i) {
            cnt -= s[i] == 'B';
            if (cnt == k) {
                cout << "1\n" << i + 1 << " A\n";
                return;
            }
        }
    }

    k = n - k;
    cnt = n - cnt;
    for (int i = 0; ; ++i) {
        cnt -= s[i] == 'A';
        if (cnt == k) {
            cout << "1\n" << i + 1 << " B\n";
            return;
        }
    }
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	// scanf("%d", &t);
    cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}