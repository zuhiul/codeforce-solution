#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cnt;
const long long maxm = 1e5+10;
const long long mod = 1e9+7;
vector<pair<long long,long long> > mat[maxm<<3];
long long ans[maxm<<3];
inline long long duck(long long a, long long b) {
	return (a*10+b)%mod;
}
queue<long long> que;
void gao(long long from, long long to, long long value) {
	if(value<10) {
		//printf("%d->%d:%d\n", from , to , value%10);
		mat[from].push_back(make_pair(to,value));
		mat[to].push_back(make_pair(from,value));
		return ;
	}
	//printf("%d->%d:%d\n", cnt , to , value%10);
	mat[cnt].push_back(make_pair(to, value%10));
	mat[to].push_back(make_pair(cnt, value%10));
	gao(from, cnt++, value/10);
}
int main(){
	scanf("%lld%lld",&n,&m);
	cnt = n+1;
	for(int i = 1;i<=m;i++) {
		long long from,to;
		scanf("%lld%lld", &from ,&to);
		gao(from,to,i);
	}
	ans[1] = 0;
	que.emplace(1);
	while(!que.empty()) {
		long long buf = que.front();
		que.pop();
		for(int i = 0;i<10;i++) {
			for(auto e:mat[buf]) {
				if(e.second!=i) continue;
				if(ans[e.first]) continue;
				ans[e.first] = duck(ans[buf], e.second);
				//printf("ans[%d]:%d\n", e.first, ans[e.first]);
				que.emplace(e.first);
			}
		}
	}
	for(int i = 2;i<=n;i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
