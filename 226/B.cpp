#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10;
int n, q;
long long a[maxm];
void input() {
	//scanf("%d",&n);
	cin>>n;
	//for(int i = 0;i<n;i++) scanf("%lld", a+i);
	for(int i = 0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	for(int i = 1;i<n;i++) a[i] += a[i-1];
}
long long get_ans(int len) {
	long long ans = 0;
	long long rlen = len, cnt = 1;
	for(int i = 1;i<n;) {
		int r = min(n-1ll,i+rlen-1);
		//cout<<i<<' '<<r<<' '<<cnt<<endl;
		ans += (a[r] - a[i-1])*cnt;
		cnt++;
		i = r+1;
		rlen *= len;
	}
	return ans;
}
long long ans[maxm];
void solve() {
	cin>>q;
	while(q--) {
		int len;
		cin>>len;
		if(ans[len]) cout<<ans[len]<<' ';
		else {
			ans[len] = get_ans(len);
			cout<<ans[len]<<' ';
		}
	}
	cout<<endl;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	input();
	solve();
	return 0;
}
