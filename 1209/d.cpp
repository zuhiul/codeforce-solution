#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10;
int n,k;
struct p{
	int ind;
	int l,r;
};
vector<p> has[maxm];
bool used[maxm];
bool eat[maxm];
int l[maxm],r[maxm];
queue<p> que;
int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=k;i++) {
		scanf("%d%d",&l[i],&r[i]);
		has[l[i]].push_back(p{i,l[i],r[i]});
		has[r[i]].push_back(p{i,l[i],r[i]});
	}
	int ans = 0;
	for(int i = 1;i<=k;i++) {
		if(used[i]) continue;
			while(!que.empty()) que.pop();
			que.push(p{i,l[i],r[i]});
			while(!que.empty()) {
				p now = que.front();que.pop();			
				used[now.ind] = true;
				if(!eat[now.l]||!eat[now.r]) {
					eat[now.l] = eat[now.r] = true;
					for(p x:has[now.l]) if(!used[x.ind]) que.push(x);
					has[now.l].clear();
					for(p x:has[now.r]) if(!used[x.ind]) que.push(x);
					has[now.r].clear();
					ans++;
				}
			}
	}
	printf("%d\n", k-ans);
	return 0;
}
