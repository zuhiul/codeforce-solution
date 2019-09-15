#include<bits/stdc++.h>
using namespace std;
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	vector<vector<int> > mat(n, vector<int>(m));
	vector<int> maxm(m);
	vector<int> ord(m);
	for(int i = 0;i<m;i++) ord[i] = i;
	for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) {
		scanf("%d", &mat[i][j]);
		maxm[j] = max(maxm[j], mat[i][j]);
	}
	sort(ord.begin(), ord.end(), [&] (int i, int j) {
		return maxm[i] > maxm[j];
	});
	if(ord.size()>n) ord.resize(n);
	vector<int>dp(1<<n);
	for(auto c:ord) {
		vector<int> dp2(1<<n);
		for(int rotate = 0;rotate < n;rotate++) {
			for(int choose = 0;choose<(1<<n);choose++) {
				int mask = 0, sum = 0;
				for(int i = 0;i<n;i++) if((choose>>i)&1) {
					mask |= (1<<((i+rotate)%n));
					sum += mat[i][c];
				}
				dp2[mask] = max(dp2[mask], sum);
			}
		}

		auto dp3 = dp;
		for(int mask = 0;mask<(1<<n);mask++) {
			for(int sub_mask = mask;sub_mask>0;sub_mask= (sub_mask-1)&mask) {
				dp3[mask] = max(dp3[mask], dp[mask^sub_mask] + dp2[sub_mask]);
			}
		}
		dp = dp3;
	}
	printf("%d\n", dp[(1<<n)-1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
