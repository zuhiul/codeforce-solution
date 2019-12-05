#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10;
struct p {
	int l;
	int r;
} mat[maxm];
void solve() {
	int a;
	scanf("%d",&a);	
	int l_max = 0, r_min = 1e9+10;
	for(int i =1;i<=a;i++) {
		scanf("%d%d", &mat[i].l, &mat[i].r);
		l_max = max(l_max, mat[i].l);
		r_min = min(r_min, mat[i].r);
	}
	printf("%d\n", max(0, l_max-r_min));
}
int main (){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
