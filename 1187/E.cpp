#include<bits/stdc++.h>
using namespace std;
const int maxm = 2e5+10;
int n;
vector<int> mat[maxm];
long long size[maxm];
long long ans[maxm];
void dfs(int ind = 1, int pre = 0) {
	size[ind] = 1;
	for(auto i:mat[ind]) {
		if(i==pre) continue;
		dfs(i, ind);
		size[ind] += size[i];
	}
	ans[1] += size[ind];
}
void dfs2(int ind, int pre) {
	ans[ind] = ans[pre] - size[ind] + (n-size[ind]);
	for(auto i:mat[ind]) {
		if(i==pre) continue;
		dfs2(i, ind);
	}
}
int main(){
	scanf("%d",&n);
	for(int i = 1, from, to;i<n;i++) {
		scanf("%d%d",&from,&to);
		mat[from].push_back(to);
		mat[to].push_back(from);
	}
	dfs();
	for(auto i:mat[1]) dfs2(i, 1);
	long long rans = 0;
	for(int i = 1;i<=n;i++) rans = max(rans, ans[i]);
	printf("%lld\n", rans);
	return 0;
}
