#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10;
int n;
int num[maxm];
int dp[maxm][400];
int solve(int p, int k) {
	if(p>n) return 0;
	if(dp[p][k]) return dp[p][k];
	return dp[p][k] = solve(p+num[p]+k,k) + 1;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",num+i);
	int q;
	scanf("%d",&q);
	while(q--) {
		int p,k;
		scanf("%d%d",&p,&k);
		if(k<400) printf("%d\n", solve(p,k));
		else {
			int ans = 0;
			while(p<=n) {
				ans++;
				p = p + num[p] + k;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
