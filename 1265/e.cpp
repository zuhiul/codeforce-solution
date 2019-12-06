#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxm = 1e6+10;
inline int add(long long a, long long b) {a%=mod, b%=mod; return (a+b+mod)%mod;}
inline int mul(long long a, long long b) {a%=mod, b%=mod; return a*b%mod;}
inline int qpow(long long a,long long b) {/*{{{*/
	int ret = 1;
	while(b) {
		if(b&1) ret = mul(ret, a);
		a = mul(a, a);
		b>>=1;
	}
	return ret;
}/*}}}*/
int n;
int p[maxm];
void init() {
	int inv100 = qpow(100, mod-2);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) {
		scanf("%d",p+i);
		p[i] = mul(p[i], inv100);
	}
}
int main() {
	init();
	int ans = n;
	int zi = 0;
	int mu = 1;
	int base = 1;
	p[0] = 1;
	for(int i = 1;i<=n;i++) {
		base = mul(base, p[i-1]);
		zi = add(zi, mul(base, mul(i, add(1, -p[i]))));
		mu = mul(mu, p[i]);
	}
	ans = add(ans, mul(zi, qpow(mu, mod-2)));
	printf("%d\n", ans);
	return 0;
}
