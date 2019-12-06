#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e6+10;
int num[maxm];
char ans[maxm];
int len;
map<int,int> ind;
void solve() {
	scanf("%d",&len);
	ans[len] = '\0';
	ind.clear();
	for(int i =0;i<len;i++) scanf("%d",num+i), ind[num[i]] = i;
	int min_ind = len+1, max_ind = -1;
	for(int i = 0;i<len;i++) {
		min_ind = min(min_ind, ind[i+1]);
		max_ind = max(max_ind, ind[i+1]);
		if(max_ind - min_ind == i) {
			ans[i] = '1';
		} else {
			ans[i] = '0';
		}
	}
	puts(ans);
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
