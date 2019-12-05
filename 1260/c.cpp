#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
	if(a==0) return b;
	return gcd(b%a, a);
}
long long lcm(long long a,long long b) {
	return a/gcd(a,b)*b;
}
void solve() {
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b) swap(a,b);
	int x = gcd(a,b);
	if((a-x-1)/b>=c-1) puts("REBEL");
	else  puts("OBEY");
}
int main () {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
