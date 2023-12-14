#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 扩展欧几里得
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) x = 1, y = 0;
	else exgcd(b, a % b, y, x), y -= a / b * x;
}

// a在mod p意义下的逆元
ll inv(ll a, ll p) {
	ll x, y;
	exgcd(a, p, x, y);
	return (x % p + p) % p;
}

// 快速幂
ll qpow(ll a, ll b, ll p) {
	ll t = 1;
	while (b) {
		if (b & 1) t = t * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return t;
}
