#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	scanf("%lld",&n);
	long long ans = 0;
	for(int i = 1, a, buf = 1, zh = 1,fu = 0;i<=n;i++) {
		scanf("%d",&a);
		int flag = -1;
		if(a>0) flag = 1;
		if(buf == flag) {//+
			ans+=zh;
			zh++;
		} else {
			ans+=fu;
			fu++;
		}
		if(a<0) buf = -buf;
	}
	printf("%lld %lld\n", n*(n+1)/2 - ans, ans);
	return 0;
}
