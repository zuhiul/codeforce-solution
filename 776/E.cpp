#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long euler(long long a) {
	long long buf = a,ret = a;
	for(long long i = 2;i*i<=buf;i++) {
		if(buf%i==0) {
			ret = ret/i*(i-1);
			buf/=i;
			while(buf%i==0) buf/=i;
		}
	}
	if(buf!=1) ret = ret/buf*(buf-1);
	return ret;
}
int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	b = (b+1)>>1;
	while(b--) {
		a = euler(a);
		if(a==1) break;
	}
	printf("%lld\n", a%mod);
	return 0;
}
