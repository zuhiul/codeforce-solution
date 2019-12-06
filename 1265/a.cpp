#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+10;
char que[maxm];
void handle(int a, int len) {
	bool flag[3] = {true, true, true};
	if(a) flag[que[a-1]-'a'] = false;
	if(a+1 < len && que[a+1] != '?') flag[que[a+1] - 'a'] = false;
	for(int i = 0;i<3;i++) {
		if(flag[i]) {
			que[a] = i + 'a';
			return ;
		}
	}
}
void solve() {
	scanf("%s", que);
	int len = strlen(que);
	for(int i = 0;i<len;i++) {
		if(que[i] == '?') handle(i, len);
	}
	for(int i = 1;i<len;i++) {
		if(que[i] == que[i-1]) {
			puts("-1");
			return ;
		}
	}
	puts(que);
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
