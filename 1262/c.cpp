#include<bits/stdc++.h>
using namespace std;
const int maxm = 3000;
int len, need;
int len_ans;
int ans[maxm][2];
char que[maxm];
void my_swap(int a, int b) {
	for(int i = a, j = b;i<j;i++,j--) {
		swap(que[i], que[j]);
	}
}
void get(char buf, int ind) {
	for(int i = ind+1;i<len;i++) {
		if(que[i] == buf) {
			ans[len_ans][0] = ind;
			ans[len_ans++][1] = i;
			my_swap(ind, i);
			return ;
		}
	}
}
void solve() {
	len_ans = 0;
	scanf("%d%d%s", &len, &need, que);
	for(int i = 0;i<len/2-need+1;i++) 
		if(que[i] != '(') get('(', i); 
	for(int i = len/2-need+1;i<len-(need-1)*2;i++) 
		if(que[i] != ')') get(')', i);
	for(int i = len-(need-1)*2;i<len;i++) {
		if(i&1) {
			if(que[i] != ')') get(')', i);
		} else {
			if(que[i] != '(') get('(', i);
		}
	}
	printf("%d\n", len_ans);
	for(int i = 0;i<len_ans;i++) {
		printf("%d %d\n", ans[i][0]+1, ans[i][1]+1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
