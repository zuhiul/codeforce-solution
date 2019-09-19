#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e5+10;
int n,k,d;
int num[maxm];
bool dp[maxm];
int main(){
	scanf("%d%d%d",&n,&k,&d);
	for(int i = 1;i<=n;i++) scanf("%d", num+i);
	sort(num+1, num+n+1);
	dp[0] = true;
	int l = 0, r = 0;
	for(int i = 0;i<=n;i++) {
		if(dp[i]) {
			l = max(l, i+k);
			r = max(r, l);
			if(r>n) break;
			while(r<=n && num[r] - num[i+1] <= d) r++;
			r--;
			for(int j = l;j<=r;j++) dp[j] = true;
			l = r+1;
		}
	}
	if(dp[n]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
