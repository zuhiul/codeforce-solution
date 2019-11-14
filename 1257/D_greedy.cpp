#include<bits/stdc++.h>
using namespace std;
const int maxm = 2e5+10;
int n, m;
int num[maxm];
int att[maxm];
void solve() {
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d",num+i);
	memset(att,0,sizeof(att));
	scanf("%d",&m);
	for(int i = 0,a,b;i<m;i++)  {
		scanf("%d%d",&a,&b);
		att[b] = max(att[b], a);
	}
	for(int i = maxm-2;i>=0;i--) att[i] = max(att[i], att[i+1]);

	int ans = 0;
	int ind = 0;
	while(ind < n) {
		int buf = 1;
		if(att[buf] < num[ind]) {
			puts("-1");
			return ;
		}
		while(ind < n && att[buf] >= num[ind]) {
			ind++;
			buf++;
		}
		ind--;
		ans++;
	}
	printf("%d\n", ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
