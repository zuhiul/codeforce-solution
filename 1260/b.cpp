#include<bits/stdc++.h>
using namespace std;
void solve() {
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b) swap(a,b);
	if(a>b) {
		int buf = a-b;
		a-=buf*2;
		b-=buf;
	}	
	if(a==1&&b==1) puts("NO");
	else if(a<0 || b<0) puts("NO");
	else if(a==b&& a%3!=0) puts("NO");
	else if (a==2&&b==2) puts("NO");
	else if(a>b*2 || b>a*2) puts("NO");
	else puts("YES");
}
int main () {
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
