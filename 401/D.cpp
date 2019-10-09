#include<bits/stdc++.h>
using namespace std;
const int maxm = 1<<18;
long long ans[maxm][105];
int len;
int num[100], mod;
int main(){
	long long nouse;
	scanf("%lld%d", &nouse, &mod);
	if(nouse == 1000000000000000000ll) {
		printf("%d\n", nouse%mod?0:1);
	}
	while(nouse) {
		num[len++] = nouse%10;
		nouse/=10;
	}
	for(int i = 0;i<len;i++) {
		if(num[i]==0) continue;
		ans[1<<i][num[i]%mod]++;
	}
	for(int i = 1;i<(1<<len);i++) {
		for(int j = 0;j<mod;j++) {
			if(ans[i][j]) {
				for(int ind = 0;ind<len;ind++) {
					if((i>>ind)&1) continue;
					ans[i|(1<<ind)][(j*10+num[ind])%mod]+= ans[i][j];
					//cout<<i<<' '<<j<<' '<< ans[i][j] <<"-->"<<(i|(1<<ind))<<' '<<(j*10+num[ind])%mod<<endl;
				}
			}
		}
	}
	long long rans = ans[(1<<len)-1][0];
	sort(num,num+len);
	num[len++] = 100;
	int cnt = 1;
	for(int i = 1;i<len;i++) {
		if(num[i]==num[i-1]) cnt++;
		else {
			while(cnt!=1) {
				rans/=cnt;
				cnt--;
			}
		}
	}
	printf("%lld\n", rans);
	return 0;
}
