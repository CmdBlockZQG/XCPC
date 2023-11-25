#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const ll P = 1e9+7;

ll qpow(ll a, ll b) {
	ll ans = 1, base = a;
	while (b) {
		if (b & 1) ans = ans * base;
		base = base * base;
		b >>= 1;
	}
	return ans;
}

ll qpowm(ll a, ll b) {
	ll ans = 1, base = a;
	while (b) {
		if (b & 1) ans = ans * base % P;
		base = base * base % P;
		b >>= 1;
	}
	return ans;
}

ll t(ll x, ll n) {
	ll t = qpowm(x, n + 1);
	ll nx = qpowm(x - 1, P - 2);
	return (n * t % P * nx % P + P - (t + P - x) % P * nx % P * nx % P) % P;
}

ll g(const ll x, ll l, ll r) {
	ll ans = 0;

	ll i = log((long double)l) / log((long double)x);
	ll il = qpow(x, i), ir = x * il - 1;

	ll j = log((long double)r) / log((long double)x);
	ll jl = qpow(x, j), jr = x * jl - 1;

	// rintf("%lld %lld %lld %lld\n", il, ir, jl, jr);

	if (i + 1 <= j - 1) {
		ans += (t(x, j - 1) + P - t(x, i)) % P;
	}

	if (ir >= l) ans += (min(ir, r) - l + 1) % P * i % P;
	if (i != j && jl <= r) ans += (r - max(l, jl) + 1) % P * j % P;
	
	return ans;
}

ll gm[65] = {0};

ll f(const ll x) {
	if (x < 4) return 0;
	ll ans = 0;
	for (ll i = 2; ; ++i) {
		ll l = (ll)1 << i, r = ((ll)1 << (i + 1)) - 1;
		if (l > x) return ans;
		// printf("%lld %lld %lld %lld\n", i, l, min(r, x), g(i, l, min(r, x)));
		// ans += g(i, l, min(x, r));
		if (x < r) {
			ans += g(i, l, x);
		} else {
			if (gm[i]) ans += gm[i];
			else ans += gm[i] = g(i, l, r);
		}
		ans %= P;
	}
}

void solve() {
	ll l, r;
	scanf("%lld %lld", &l, &r);
	printf("%lld\n", (f(r) + P - f(l - 1)) % P);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}