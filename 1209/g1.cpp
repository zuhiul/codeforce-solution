#include<bits/stdc++.h>
using namespace std;
const int maxm = 2e5+20;
int n;
int num[maxm];
map<int,int> r;
int main(){
	cin>>n;
	for(int i = 0;i<n;i++) cin>>num[i],r[num[i]] = i;
	int ans = 0;
	for(int i = 0;i<n;) {
		int buf = r[num[i]];
		for(int j = i;j<=buf;j++) {
			buf = max(buf,r[num[j]]);
		}
		ans+=gao(i,buf,num[i]);
		i = buf+1;
	}
	printf("%d\n", ans);
	return 0;
}
