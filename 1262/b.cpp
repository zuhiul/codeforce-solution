#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10;
int len;
int num[maxm];
bool vis[maxm];
int ans[maxm];
void solve() {
	scanf("%d",&len);
	for(int i = 1;i<=len;i++) scanf("%d", num+i), vis[i] = false, ans[i] = 0;
	ans[1] = num[1], vis[num[1]] = true;
	for(int i = 2;i<=len;i++) if(num[i]!=num[i-1]) ans[i] = num[i], vis[num[i]] = true;
	int ind = len;
	for(int i = len;i>=1;i--) {
		if(ans[i]==0) {
			while(vis[ind]) ind--;
			ans[i] = ind--;
		}
	}
	int buf = num[1];
	for(int i = 2;i<=len;i++) {
		buf = max(buf, ans[i]);
		if(buf != num[i]) {
			puts("-1");
			return ;
		}
	}
	for(int i = 1;i<=len;i++) printf("%d ", ans[i]);
	putchar('\n');
}
int main (){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
