#include<bits/stdc++.h>
using namespace std;
int n;
const int maxm = 1e5+10;
int num[maxm];
void solve() {
	if(n==1) {
		if(num[0] == 0) puts("YES\n0");
		else puts("NO");
		return ;
	}
	if(num[n-2] == 1) {
		puts("YES");
		for(int i = 0;i<n-1;i++) printf("%d->",num[i]);
		printf("%d\n", num[n-1]);
		return ;
	}
	int ind = -1;
	for(int i = 0;i<n-2;i++) if(num[i] == 0) ind = i;
	if(ind == -1) {
		puts("NO");
		return ;
	}
	puts("YES");
	// a -> (ind -> (ind+1 ->...-> n-2 ) ) -> n-1
	for(int i = 0;i<ind;i++) printf("%d->", num[i]);
	printf("(%d->(%d", num[ind], num[ind+1]);
	for(int i = ind+2;i<n-1;i++) printf("->%d", num[i]);
	printf("))->%d\n", num[n-1]);
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i<n;i++) scanf("%d", num+i);
	if(num[n-1] != 0) puts("NO");
	else solve();
	return 0;
}
