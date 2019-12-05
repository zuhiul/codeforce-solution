#include<bits/stdc++.h>
using namespace std;
void solve() {
	int a,b;
	scanf("%d%d",&a,&b);
	long long ans = 0;
	int nee = a;
	for(int i = 1;i<=a;i++) {
		int buf = b/nee + (b%nee!=0);
		ans+=buf*buf;
		b-=buf;
		nee--;
	}
	printf("%lld\n", ans);
}
int main () {
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
