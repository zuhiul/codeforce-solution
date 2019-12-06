#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e6+10;
int n;
int num[maxm];
int cnt[maxm];
void solve() {
	scanf("%d", &n);
	num[0] = 0;
	for(int i = 1, a;i<=n;i++) {
		scanf("%d",&a);
		if(num[0] == 0) {
			num[++num[0]] = a;
			cnt[num[0]] = 1;
		} else {
			if(a==num[num[0]]) cnt[num[0]] ++;
			else {
				num[++num[0]] = a;
				cnt[num[0]] = 1;
			}
		}
	}
	for(int i = 1;i<=num[0];i++) {
		//cout<<cnt[i]<<' ';
	}
	//cout<<endl;
	int ans0 = cnt[1], ans1 = 0;
	int i;
	for(i = 2;i<=num[0];i++) {
		if(ans1 <= ans0) {
			ans1+= cnt[i];
			continue;
		}
		break;
	}
	int ans2 = 0;
	for(;i<=num[0];i++) {
		if(ans2 <= ans0) {
			ans2 += cnt[i];
			continue;
		}
		if(ans0 + ans1 + ans2 + cnt[i] <= n/2) {
			ans2 += cnt[i];
			continue;
		}
		break;
	}
	if(ans1<= ans0 || ans2 <= ans0 || ans0 + ans1 + ans2 > n/2) {
		puts("0 0 0");
	} else {
		printf("%d %d %d\n", ans0, ans1, ans2);
	}
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
